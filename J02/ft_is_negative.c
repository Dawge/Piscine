#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while(*str != '\0')
		ft_putchar(*str++);
}

void	ft_is_negative(int n)
{
	if(n < 0)
		ft_putstr("N");
	else
		ft_putstr("P");
}

int	main()
{
	ft_is_negative(5);
	return(0);
}
