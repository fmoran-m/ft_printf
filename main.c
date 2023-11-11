#include "ft_printf.h"

int main(void) {
    // Guarda el descriptor de archivo de la salida estándar
    int stdout_fd = dup(fileno(stdout));

    // Cierra la salida estándar (simulando un error de escritura)
    close(fileno(stdout));

    // Ahora, cualquier intento de escritura en stdout debería fallar

    char c = 'z';
    char *s = "string";
    int d = 42;
    unsigned int u = 4294967295;
    int x = -1;
    void *p = "holacomoandamis";

    // Llamada a ft_printf
    printf("mi char es %c\nmi string es %s\nmi numero es %d\nmi unsigned es %u\nmi hexadecimal es %X\nmi void puntero es %p\n", c, s, d, u, x, p);

    // Restaura la salida estándar
    dup2(stdout_fd, fileno(stdout));

    // Llamada a printf para comparar
    printf("\n---\n");
    printf("mi char es %c\nmi string es %s\nmi numero es %d\nmi unsigned es %u\nmi hexadecimal es %X\nmi void puntero es %p\n", c, s, d, u, x, p);

    return 0;
}
