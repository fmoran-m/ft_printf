#include "ft_printf.h"

int main (void)
{
	char c = 'z';
	char *s = "string";
	int d = 42;
	unsigned int u = 4294967295;
	int x = 223;
	void *p = "0";
	ft_printf("mi char es %c\nmi string es %s\nmi numero es %d\nmi unsigned es %u\nmi void puntero es %p\nmi hexadecimal es %x\n", c, s, d, u, p, x);
    return (0);
}