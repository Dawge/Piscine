#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_reverse_alphabet()
{
	char c;
	c = 'z';
	while(c >= 'a')
	{
		ft_putchar(c);
		c--;
	}
}

int	main()
{
	ft_reverse_alphabet();
	return(0);
}
