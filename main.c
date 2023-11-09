#include "ft_printf.h"

int main (void)
{
	char c = 'z';
	char *s = "string";
	int d = 42;
	unsigned int u = 4294967295;
	int x = -1;
	void *p = "holacomoandamis";
	ft_printf("mi char es %c\nmi string es %z\nmi numero es %d\nmi unsigned es %u\nmi hexadecimal es %X\nmi void puntero es %p\n", c, s, d, u, x, p);
	printf("mi char es %c\nmi string es %z\nmi numero es %d\nmi unsigned es %u\nmi hexadecimal es %X\nmi void puntero es %p\n", c, s, d, u, x, p);
	return (0);
}