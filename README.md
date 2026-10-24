*Este proyecto ha sido creado como parte del currículo de 42 por [reiascan]*

# ft_printf

## Descripción

`ft_printf` es un proyecto individual del currículo de 42 cuyo objetivo es recrear el comportamiento de la función `printf` de la librería estándar de C. La función debe interpretar una cadena de formato, consumir los argumentos variables correspondientes mediante `va_list` y escribir el resultado en la salida estándar, devolviendo el número total de caracteres impresos.

Implementar `ft_printf` me ayudó a comprender en profundidad el manejo de funciones variádicas (`stdarg.h`) y la recursión aplicada a la conversión de números en distintas bases.

---

## Conversiones soportadas

El  objetivo de este proyecto es replicar el comportamiento de printf, bajo los esppecificadores que se nos han planteado desde  la escuela de 42. No se incluyen los demas especificadores de la funcion `printf`original, solo los de la lista siguiente. 

| Especificador | Argumento | Descripción |
| :---: | :--- | :--- |
| `%c` | `int` | Imprime un único carácter. |
| `%s` | `char *` | Imprime una cadena; si es `NULL`, imprime `(null)`. |
| `%p` | `void *` | Imprime la dirección en hexadecimal con prefijo `0x`; si es `NULL`, imprime `(nil)`. |
| `%d` | `int` | Imprime un entero decimal con signo. |
| `%i` | `int` | Imprime un entero decimal con signo. |
| `%u` | `unsigned int` | Imprime un entero decimal sin signo. |
| `%x` | `unsigned int` | Imprime un entero en hexadecimal (minúsculas). |
| `%X` | `unsigned int` | Imprime un entero en hexadecimal (mayúsculas). |
| `%%` | — | Imprime el carácter `%`. |

Este proyecto cubre únicamente la **parte obligatoria** del subject: no implementa los flags de bonus.

---

## Descripción general de la librería y descripción de funciones

### 1. Núcleo del programa

* `ft_printf` – Recorre la cadena de formato carácter a carácter, inicializa y cierra la `va_list` y delega cada conversión en `print_evaluator`. Acumula y devuelve el número total de caracteres escritos. Si el formato es `NULL`, devuelve `-1`.
* `print_evaluator` – Identifica el especificador de conversión y llama a la función auxiliar correspondiente, extrayendo el argumento con `va_arg`.
* `ft_printf.h` – Header único de la librería: declara los prototipos y las cabeceras necesarias (`unistd.h`, `stdlib.h`, `stdarg.h`).

### 2. Funciones auxiliares

* `print_char` – Escribe un solo carácter en el descriptor de salida.
* `print_str` – Recorre e imprime una cadena, con gestión de `NULL` y devolución del número de caracteres.
* `print_digit` – Convierte y escribe un número en la base indicada (10 o 16), en minúsculas o mayúsculas, mediante recursión. Gestiona el signo negativo de `%d`/`%i`.
* `print_mem_dir` – Imprime una dirección de memoria con el prefijo `0x`, o `(nil)` si el puntero es nulo.

### 3. Estructura del proyecto

| Archivo | Contenido |
| :--- | :--- |
| `ft_printf.c` | Bucle principal y gestión de la `va_list`. |
| `print_evaluator.c` | Dispatcher de especificadores. |
| `print_char.c` | Conversión `%c`. |
| `print_str.c` | Conversión `%s`. |
| `print_digit.c` | Conversiones `%d`, `%i`, `%u`, `%x` y `%X`. |
| `print_mem_dir.c` | Conversión `%p`. |
| `ft_printf.h` | Prototipos y cabeceras. |
| `Makefile` | Reglas de compilación y creación de la librería. |

---

## Instrucciones

### Compilación

El proyecto utiliza un `Makefile` que compila todos los archivos fuente con `cc` y las flags `-Wall -Wextra -Werror`, y genera la librería estática `libftprintf.a` mediante `ar`.

1. **Compilar la librería:**

   ~~~bash
   make
   ~~~

   Compila todos los archivos `.c` listados en `SRC` y genera la librería estática `libftprintf.a`.

2. **Limpiar los archivos objeto:**

   ~~~bash
   make clean
   ~~~

   Elimina todos los archivos objeto (`.o`) generados durante la compilación.

3. **Limpiar los archivos objeto y `libftprintf.a`:**

   ~~~bash
   make fclean
   ~~~

   Elimina tanto los archivos objeto como la librería estática.

4. **Recompilar todo desde cero:**

   ~~~bash
   make re
   ~~~

   Ejecuta `fclean` y luego `all`, recompilando el proyecto completo.

### Integración y ejecución

Para usar `libftprintf.a`:

1. Incluye el header en tu archivo `*.c`:

   ~~~c
   #include "ft_printf.h"
   ~~~

2. Compila enlazando la librería:

   ~~~bash
   cc -Wall -Wextra -Werror main.c libftprintf.a
   ~~~

   - `-Wall` para activar los warnings importantes.
   - `-Wextra` activa warnings adicionales.
   - `-Werror` convierte los warnings en errores.

   También puedes enlazarla por nombre, indicando al enlazador dónde buscar:

   ~~~bash
   cc -Wall -Wextra -Werror main.c -L. -lftprintf
   ~~~

   - `-L.` indica al enlazador que busque librerías en el directorio actual.
   - `-lftprintf` indica que enlace con `libftprintf.a` (el prefijo `lib` y la extensión `.a` se omiten).

   En ambos casos, la librería debe colocarse **después** de los archivos que la usan.

### Ejemplo de uso

~~~c
#include "ft_printf.h"

int	main(void)
{
	int	n;

	n = 42;
	ft_printf("Hola %s, tienes %d años\n", "Pepito", 42);
	ft_printf("hex: %x | HEX: %X | ptr: %p | %%\n",
		255, 255, (void *)&n);
	return (0);
}
~~~

Salida:

~~~text
Hola Pepito, tienes 42 años
hex: ff | HEX: FF | ptr: 0x... | %
~~~

---

## Comportamiento y notas

* `ft_printf` devuelve el número total de bytes escritos, igual que `printf`.
* `%s` con `NULL` imprime `(null)` y `%p` con `NULL` imprime `(nil)` (convención de glibc en Linux).
* `%d` con `INT_MIN` y `%u`/`%x`/`%X` con `UINT_MAX` se gestionan sin desbordamiento en plataformas de 64 bits.
* `%c` con el carácter `\0` escribe el byte nulo y lo cuenta como un carácter.
* La función `write` es la única función de salida utilizada.

---

## Recursos

### Referencias y documentación

* **PDF del subject de 42** – Contiene las reglas específicas del proyecto, los prototipos exactos, los requisitos de normativa y los criterios de evaluación.
* **https://es.cppreference.com/c/variadic** – Utilizado para repasar conceptos de funciones t argumentos variadicos, me ayudo muhco a comprender a visualizar lo que se me pedia para este proyecto
* **https://es.cppreference.com/c/io/fprintf** – Utilizado para repasar la funcion printf e intentar mimetizarla en todo lo que se me pedia de la manera mas fidedigna.
* **El man (manual) de Linux** – Consulta de comandos del sistema y de los prototipos y comportamientos de las funciones estándar de `libc` (por ejemplo, `man write`, `man printf`), y además tambien consultar el man de `va_start`, `va_arg`, `va_list`, `va_end`.

### Herramientas de prueba

* **Tests propios** – Mis tests, aunque sencillos, fueron los que me ayudaron a plantearme la mayoría de problemas y/o a como abordar mis funciones.
* **https://pythontutor.com/c.html** – Herramienta de visualización paso a paso de código C. Se utilizó para identificar fallos, entender el flujo de ejecución y depurar el manejo de punteros y la recursión.
* **[francinette-image](https://github.com/WaRtr0/francinette-image)** –  Se ha utilizado esta herramienta de la comunidad de 42 para testear mi proyecto

### Sobre el uso de IA

* La IA se utilizó para crear, formatear y estructurar este archivo `README.md` de acuerdo con los requisitos indicados en el subject de este proyecto de 42.
