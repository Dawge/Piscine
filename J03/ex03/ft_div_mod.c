#include <stdio.h>

void	ft_div_mod(int a, int b)
{
	int *div;
	int *mod;
	*div = a / b;
	*mod = a % b;
	printf("%d et %d", div, mod);
}

int	main()
{
	ft_div_mod(7, 3);
	return(0);
}
