#include "ft_printf.h"

int main(void) {

    char c = 'z';
    char *s = "string";
    int d = -12;
    unsigned int u = 4294967295;
    int x = -1;
    void *p = "holacomoandamis";

//	ft_printf("mi char es %s\nmi string es %c\nmi numero es %d\nmi unsigned es %u\nmi hexadecimal es %X\nmi void puntero es %p\n", c, s, 100, u, x, p);

  printf("mi char es %c\nmi string es %s\nmi numero es %d\nmi unsigned es %u\nmi hexadecimal es %X\nmi void puntero es %p\n", c, s, 100, u, x, p);

    return 0;
}
