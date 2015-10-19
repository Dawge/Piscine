#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print(char a, char b, char c , char d)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(' ');
	ft_putchar(c);
	ft_putchar(d);
	ft_putchar(',');
	ft_putchar(' ');
}

void	print2(char a, char b, char c, char d)
{
	b = '0';
	while(b <= '8')
	{
		c = a;
		while(c <= '9')
		{
			d = b + 1;
			while(d <= '9')
			{
				print(a, b, c, d);
				d++;
			}
			if(c < '9')
			{
				c++;
				d = '0';
				print(a, b, c, d);
			}
			else
				c++;
		}
		b++;
	}
}

void	ft_print_comb2()
{
	char a;
	char b;
	char c;
	char d;
	a = '0';
	b = '0';
	c = '0';
	d = '1';
	while(a <= '9')
	{
		print2(a, b, c, d);
		a++;
	}
}

int	main()
{
	ft_print_comb2();
	return(0);
}
