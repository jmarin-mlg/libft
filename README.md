# Libft (125/100)

![Puntuación conseguida](./images/libft_01.png)

Libft es el primer proyecto del `Cursus` en `42 Network`, consiste en
desarrollar un conjunto de funciones que serán de gran utilidad en el resto de
proyectos. La mayoría de estas funciones simulan a funciones nativas de **C**.

Este proyecto debe estar escrito siguiendo la [Norma](https://github.com/jmarin-mlg/resources_42_malaga/blob/master/pdfs/es.norm.pdf).

> **¡Atención!**
>
> Este proyecto contiene la versión entregada (directorio `evaluated_version`) y
> por lo tanto evaluada en `42 Network`, pero también una versión mejorada
> (directorio `improved_version`) que he desarrollado a posteriori, en la que
> optimizo el código para mejorar su eficiencia y/o legibilidad.
>
> Debo puntualizar que en la `versión entregada` a pesar de estar aprobada con
> la máxima puntuación no la merece, debido a que el `Makefile` hace `relink` y
> esto es algo que no está permitido en `42 Network`. De este error, me
> advirtieron los compañeros que me evaluarón el siguiente proyecto (`Printf`).
>
> Evidentemente y como no podía ser de otra manera, este error lo he subsanado
> en la `versión mejorada` de este proyecto.

## Parte obligatoria

- **Nombre programa:** libft.a
- **Archivos a entregar:** Makefile, libft.h, ft_*.c
- **Makefile:** NAME, all, clean, fclean, re
- **Funciones autorizadas:** Detalles debajo

### 1. Consideraciones técnicas

- Declarar variables globales está prohibido.
- Si necesitas separar una función compleja en varias, asegúrate de utilizar la palabra
static para ello. De esta forma, las funciones se quedarán en el archivo apropiado.
- Pon todos tus archivos en la raíz de tu repositorio.
- Se prohibe entregar archivos no utilizados.
- Todos los archivos **.c** deben compilarse con las flags `-Wall -Werror -Wextra`.
- Debes utilizar el comando `ar` para generar la librería. El uso de **libtool** queda
prohibido.
- Tu `libft.a` tiene que ser creado en la raíz del repositorio.

### 2. Primera parte - Funciones de libc

Para empezar, deberás rehacer algunas funciones de la **libc**. Tus funciones
tendrán los mismos prototipos e implementarán los mismos comportamientos que las
funciones originales. Deberán ser tal y como las describe el `man`. La única
diferencia será la nomenclatura. Empezarán con el prefijo “ft_”. Por ejemplo,
`strlen` se convertirá en `ft_strlen`.

> Algunas funciones tienen en sus prototipos la palabra **“restrict”**.
> Esta palabra forma parte del estándar de **c99**. Por lo tanto, está
> prohibido incluirla en tus propios prototipos, así como compilar tu
> código con la flag `-std=c99`.

Deberás escribir tus propias funciones implementando las siguientes funciones
originales. No requieren de funciones autorizadas:

| Funciones de libc |  |
|--------------|--------------|
| isalpha   | toupper   |
| isdigit   | tolower   |
| isalnum   | strchr   |
| isascii   | strrchr   |
| isprint   | strncmp   |
| strlen   | memchr   |
| memset   | memcmp   |
| bzero   | strnstr   |
| memcpy   | atoi   |
| memmove   | * calloc   |
| strlcpy   | * strdup   |
| strlcat   |  |

> \* **Nota**: Para implementar esta función tendrás que utilizar `malloc()`

### 3. Segunda parte - Funciones adicionales

En esta `segunda parte`, deberás desarrollar un conjunto de funciones que, o no
son de la librería **libc**, o lo son pero de una forma distinta.

> Algunas de las siguientes funciones se pueden hacer de forma más fácil si
> utilizas funciones de la `primera parte`.

1. Función `ft_substr`
	- **Prototipo:** char *ft_substr(char const *s, unsigned int start, size_t
	len);
	- **Parámetros:**
		- **s:** La string desde la que crear la substring.
		- **start:** El índice del caracter en ’s’ desde el que empezar la
		substring.
		- **len:** La longitud máxima de la substring.
	- **Valor devuelto:** La substring resultante. `NULL` si falla la reserva de
	memoria.
	- **Funciones autorizadas:** `malloc`
	- **Descripción:** Reserva (con `malloc(3)`) y devuelve una substring de la
	string ’s’. La substring empieza desde el índice ’start’ y tiene una
	longitud máxima ’len’.

2. Función `ft_strjoin`
	- **Prototipo:** char *ft_strjoin(char const *s1, char const *s2);
	- **Parámetros:**
		- **s1:** La primera string.
		- **s2:** La string a añadir a ’s1’.
	- **Valor devuelto:** La nueva string. `NULL` si falla la reserva de
	memoria.
	- **Funciones autorizadas:** `malloc`
	- **Descripción:** Reserva (con `malloc(3)`) y devuelve una nueva string,
	formada por la concatenación de ’s1’ y ’s2’.

3. Función `ft_strtrim`
	- **Prototipo:** char *ft_strtrim(char const *s1, char const *set);
	- **Parámetros:**
		- **s1:** La string que debe ser recortada.
		- **set:** Los caracteres a eliminar de la string.
	- **Valor devuelto:** La string recortada. `NULL` si falla la reserva de
	memoria.
	- **Funciones autorizadas:** `malloc`
	- **Descripción:** Elimina todos los caracteres de la string ’set’ desde el
	principio y desde el final de ’s1’, hasta encontrar un caracter no
	perteneciente a ’set’. La string resultante se devuelve con una reserva de
	`malloc(3)`.

4. Función `ft_split`
	- **Prototipo:** char **ft_split(char const *s, char c);
	- **Parámetros:**
		- **s:** La string a separar.
		- **c:** El carácter delimitador.
	- **Valor devuelto:** El array de nuevas strings resulatente de la
	separación. `NULL` si falla la reserva de memoria.
	- **Funciones autorizadas:** `malloc`, `free`
	- **Descripción:** Reserva (utilizando `malloc(3)`) un array de strings
	resultante de separar la string ’s’ en substrings utilizando el caracter ’c’
	como delimitador. El array debe terminar con un puntero `NULL`.

5. Función `ft_itoa`
	- **Prototipo:** char *ft_itoa(int n);
	- **Parámetros:**
		- **n:** El entero a convertir.
	- **Valor devuelto:** La string que represente el número. `NULL` si falla la
	reserva de memoria.
	- **Funciones autorizadas:** `malloc`
	- **Descripción:** Utilizando `malloc(3)`, genera una string que represente
	el valor entero recibido como argumento. Los números negativos tienen que
	gestionarse.

6. Función `ft_strmapi`
	- **Prototipo:** char *ft_strmapi(char const *s, char (*f)(unsigned int,
	char));
	- **Parámetros:**
		- **s:** La string que iterar.
		- **f:** La función a aplicar sobre cada carácter.
	- **Valor devuelto:** La string creada tras el correcto uso de ’f’ sobre
	cada carácter. `NULL` si falla la reserva de memoria.
	- **Funciones autorizadas:** `malloc`
	- **Descripción:** A cada carácter de la string ’s’, aplica la función ’f’
	dando como parámetros el índice de cada carácter dentro de ’s’ y el propio
	carácter. Genera una nueva string con el resultado del uso sucesivo de ’f’.

7. Función `ft_striteri`
	- **Prototipo:** void ft_striteri(char *s, void (*f)(unsigned int, char*));
	- **Parámetros:**
		- **s:** La string que iterar.
		- **f:** La función a aplicar sobre cada carácter.
	- **Valor devuelto:** Nada
	- **Funciones autorizadas:** Ninguna
	- **Descripción:** A cada carácter de la string ’s’, aplica la función ’f’
	dando como parámetros el índice de cada carácter dentro de ’s’ y la
	dirección del propio carácter, que podrá modificarse si es necesario.

8. Función `ft_putchar_fd`
	- **Prototipo:** void ft_putchar_fd(char c, int fd);
	- **Parámetros:**
		- **c:** El carácter a enviar.
		- **fd:** El file descriptor sobre el que escribir.
	- **Valor devuelto:** Nada
	- **Funciones autorizadas:** `write`
	- **Descripción:** Envía el carácter ’c’ al file descriptor especificado.

9. Función `ft_putstr_fd`
	- **Prototipo:** void ft_putstr_fd(char *s, int fd);
	- **Parámetros:**
		- **s:** El string a enviar.
		- **fd:** El file descriptor sobre el que escribir.
	- **Valor devuelto:** Nada
	- **Funciones autorizadas:** `write`
	- **Descripción:** Envía la string ’s’ al file descriptor especificado.

10. Función `ft_putendl_fd`
	- **Prototipo:** void ft_putendl_fd(char *s, int fd);
	- **Parámetros:**
		- **s:** El string a enviar.
		- **fd:** El file descriptor sobre el que escribir.
	- **Valor devuelto:** Nada
	- **Funciones autorizadas:** `write`
	- **Descripción:** Envía la string ’s’ al file descriptor dado, seguido de
	un salto de línea.

11. Función `ft_putnbr_fd`
	- **Prototipo:** void ft_putnbr_fd(int n, int fd);
	- **Parámetros:**
		- **n:** El número a enviar.
		- **fd:** El file descriptor sobre el que escribir.
	- **Valor devuelto:** Nada
	- **Funciones autorizadas:** `write`
	- **Descripción:** Envía el número ’n’ al file descriptor dado.

## Bonus

Las funciones para manipular memoria y strings son muy útiles... Pero pronto
descubrirás que la manipulación de listas lo es incluso más.

Deberás utilizar la siguiente estructura para representar un nodo de tu lista.
Añade la declaración a tu archivo `libft.h`:

```c
typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
```

Los miembros de la estructura `t_list` son:
- **content**: la información contenida por el nodo (`void *` permite guardar
cualquier tipo de información).
- **next**: la dirección del siguiente nodo, o `NULL` si el siguiente nodo es el
último.

En tu Makefile, añade una regla make `bonus` que incorpore las funciones bonus a
tu `libft.a`.

Implementa las siguientes funciones para utilizar fácilmente tus listas.

1. Función `ft_lstnew`
	- **Prototipo:** t_list *ft_lstnew(void *content);
	- **Parámetros:**
		- **content:** El contenido con el que crear el nodo.
	- **Valor devuelto:** El nuevo nodo.
	- **Funciones autorizadas:** `malloc`
	- **Descripción:** Crea un nuevo nodo utilizando `malloc(3)`. La variable
	miembro ’content’ se inicializa con el contenido del parámetro ’content’. La
	variable ’next’, con `NULL`.

2. Función `ft_lstadd_front`
	- **Prototipo:** void ft_lstadd_front(t_list **lst, t_list *new);
	- **Parámetros:**
		- **lst:** La dirección de un puntero al primer nodo de una lista.
		- **new:** Un puntero al nodo que añadir al principio de la lista.
	- **Valor devuelto:** Nada
	- **Funciones autorizadas:** Ninguna
	- **Descripción:** Añade el nodo ’new’ al principio de la lista ’lst’.

3. Función `ft_lstsize`
	- **Prototipo:** int ft_lstsize(t_list *lst);
	- **Parámetros:**
		- **lst:** El principio de la lista.
	- **Valor devuelto:** La longitud de la lista.
	- **Funciones autorizadas:** Ninguna
	- **Descripción:** Cuenta el número de nodos de una lista.

4. Función `ft_lstlast`
	- **Prototipo:** t_list *ft_lstlast(t_list *lst);
	- **Parámetros:**
		- **lst:** El principio de la lista.
	- **Valor devuelto:** Último nodo de la lista.
	- **Funciones autorizadas:** Ninguna
	- **Descripción:** Devuelve el último nodo de la lista.

5. Función `ft_lstadd_back`
	- **Prototipo:** void ft_lstadd_back(t_list **lst, t_list *new);
	- **Parámetros:**
		- **lst:** El puntero al primer nodo de una lista.
		- **new:** El puntero a un nodo que añadir a la lista.
	- **Valor devuelto:** Nada
	- **Funciones autorizadas:** Ninguna
	- **Descripción:** Añade el nodo ’new’ al final de la lista ’lst’.

6. Función `ft_lstdelone`
	- **Prototipo:** void ft_lstdelone(t_list *lst, void
	(*del)(void *));
	- **Parámetros:**
		- **lst:** El nodo a liberar.
		- **del:** Un puntero a la función utilizada para liberar el contenido
		del nodo.
	- **Valor devuelto:** Nada
	- **Funciones autorizadas:** `free`
	- **Descripción:** Toma como parámetro un nodo ’lst’ y libera la memoria del
	contenido utilizando la función ’del’ dada como parámetro, además de liberar
	el nodo. La memoria de ’next’ no debe liberarse.

7. Función `ft_lstclear`
	- **Prototipo:** void ft_lstclear(t_list **lst, void (*del)(void *));
	- **Parámetros:**
		- **lst:** La dirección de un puntero a un nodo.
		- **del:** Un puntero a función utilizado para eliminar el contenido de
		un nodo.
	- **Valor devuelto:** Nada
	- **Funciones autorizadas:** `free`
	- **Descripción:** Elimina y libera el nodo ’lst’ dado y todos los
	consecutivos de ese nodo, utilizando la función ’del’ y `free(3)`. Al final,
	el puntero a la lista debe ser `NULL`.

8. Función `ft_lstiter`
	- **Prototipo:** void ft_lstiter(t_list *lst, void (*f)(void *));
	- **Parámetros:**
		- **lst:** Un puntero al primer nodo.
		- **f:** Un puntero a la función que utilizará cada nodo.
	- **Valor devuelto:** Nada
	- **Funciones autorizadas:** Ninguna
	- **Descripción:** Itera la lista ’lst’ y aplica la función ’f’ en el
	contenido de cada nodo.

9. Función `ft_lstmap`
	- **Prototipo:** t_list *ft_lstmap(t_list *lst, void *(*f)(void *),
	void (*del)(void *));
	- **Parámetros:**
		- **lst:** Un puntero a un nodo.
		- **f:** La dirección de un puntero a una función usada en la iteración
		de cada elemento de la lista.
		- **del:** Un puntero a función utilizado para eliminar el contenido de
		un nodo, si es necesario.
	- **Valor devuelto:** La nueva lista. `NULL` si falla la reserva de memoria.
	- **Funciones autorizadas:** `malloc`, `free`
	- **Descripción:** Itera la lista ’lst’ y aplica la función ’f’ al contenido
	de cada nodo. Crea una lista resultante de la aplicación correcta y sucesiva
	de la función ’f’ sobre cada nodo. La función ’del’ se utiliza para eliminar
	el contenido de un nodo, si hace falta.
