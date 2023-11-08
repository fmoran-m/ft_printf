#include "ft_printf.h"

int main (void)
{
	char c = 'z';
	char *s = "string";
	int d = 42;
	int u = -1;
	//void *a = "b";
	//int num = 41;
	ft_printf("mi char es %c\nmi string es %s\nmi numero es %d\nmi unsigned es %u\nmi modulo es %%\n", c, s, d, u);
    return (0);
}