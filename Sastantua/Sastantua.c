#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoisimple(char c)
{
	int tmp;
	tmp = 0;
	if(c < '0' || c > '9')
		return(0);
	else
		tmp = c - 48;
	return(tmp);
}

int	ft_atoi(char *str)
{
	int i;
	int stk;
	i = 0;
	while(str[i] != '\0')
	{
		stk = ft_atoisimple(str[i]);
		i++;
	}
	return(stk);
}

int	decalage(int size)
{
	int stk;
	stk = (size / 2) + 1;
	return(stk); 
}

int	decay(int size)
{
	int i;
	int decay;
	i = 1;
	decay = 2;
	while(i <= size)
	{
		if(i % 2 == 1)
		{
			decay++;
			i++;
		}
		else
			i++;
	}
	return(decay);
}

int	decayporte(int size)
{
	int decay;
	if(size == 1)
		decay = 0;
	else if(size % 2 == 0)
		decay = size - 2;
	else
		decay = size - 1;
	return(decay);
}

int	verif(int size)
{
	int tmp;
	tmp = 0;
	if(size % 2 == 1)
		tmp = size;
	else
		tmp = size - 1;
	return(tmp);
}

void	drawstar(int nbetoile)
{
	int i;
	i = 0;
	while(i < nbetoile)
	{
		ft_putchar('*');
		i++;
	}
}

void	drawspace(int nbespace)
{
	while(nbespace > 0)
	{
		ft_putchar(' ');
		nbespace--;
	}
}

int 	nbspace(int size)
{
	int i;
	int j;
	int nbespace;
	int etage;
	i = 0;
	j = 0;
	etage = 3;
	nbespace = nbcharfinal(size) / 2;
	while(i < size)
	{
		j = 0;
		while(j < etage)
		{
			nbespace--;
			j++;
		}
		if(i == size - 1 && j == etage - 1)
			i++;
		else
		{
			etage++;
			nbespace--;
			nbespace -= decalage(i);
			i++;
		}
	}
	return(nbespace);
}

int	nbcharfinal(int size)
{
	int i;
	int j;
	int nbchar;
	int etage;
	i = 0;
	j = 0;
	nbchar = 1;
	etage = 3;
	while(i < size)
	{
		j = 0;
		while(j < etage)
		{
			nbchar += 2;
			j++;
		}
		if(i == size - 1 && j == etage - 1)
			i++;
		else
		{
			nbchar +=  2 + (2 * decalage(i));
			etage++;
			i++;
		}
	}
	return(nbchar);
}

void	draw(int nbespace, int nbetoile)
{
	drawspace(nbespace);
	ft_putchar('/');
	drawstar(nbetoile);
	ft_putchar('\\');
	ft_putchar('\n');
}

void	drawbricks(int tmp)
{
	int i;
	i = 0;
	while(i < tmp)
	{
		ft_putchar('|');
		i++;
	}
}

void	spetial(int tmp)
{
	drawbricks(tmp-2);
	ft_putchar('$');
	ft_putchar('|');
}
		
void	drawdoor(int nbetoile, int tmp, int stk, int size, int ptr)
{
	int i;
	int placeporte;
	i = 1;
	placeporte = (nbetoile - tmp) / 2;
	while(i <= placeporte)
	{
		ft_putchar('*');
		i++;
	}
	if(i == placeporte + 1)
	{
		if(ptr == 1)
			spetial(tmp);
		else
			drawbricks(tmp);
		i++;
	}
	while(i <= nbetoile - decayporte(size))
	{
		ft_putchar('*');
		i++;
	}
}

void	helpdraw(int size, int nbespace, int nbetoile, int stk, int tmp, int i)
{
	int placeporte;
	int ptr;
	ptr = 0;
	placeporte = (nbetoile - tmp) / 2;
	drawspace(nbespace);
	ft_putchar('/');
	if(size >= 5)
	{
		if(i < size / 2)
			drawdoor(nbetoile, tmp, stk, size, ptr);
		if(i == size / 2)
		{	
			ptr = 1;
			drawdoor(nbetoile, tmp, stk, size, ptr);
		}
		if(i < size && i > size / 2)
			drawdoor(nbetoile, tmp, stk, size, ptr);
	}
	else
		drawdoor(nbetoile, tmp, stk, size, ptr);
	ft_putchar('\\');
	ft_putchar('\n');
}

void	door(int etage, int size, int nbespace, int nbetoile, int i)
{
	int j;
	int tmp;
	int stk;
	j = 0;
	tmp = verif(size);
	stk = ((nbcharfinal(size) - decay(size)) - tmp) / 2;
	while(j < etage - (size + 1))
	{
		helpdraw(size, nbespace, nbetoile, stk, tmp, i);
		j++;
		i++;
	}
}

void	sastantua(int size)
{
	int i;
	int j;
	int k;
	int tmp;
	int etage;
	int nbetoile;
	int nbespace;
	i = 0;
	j = 0;
	k = 0;
	tmp = size;
	etage = 3;
	nbetoile = -1;
	nbespace = nbcharfinal(size) / 2  - nbspace(size) - decay(size);
	while(i < size)
	{
		j = 0;
		while(j < etage)
		{
			nbetoile += 2;
			if(i == size - 1 && j ==  2)
			{
				while(j < etage)
				{
					door(etage , size, nbespace, nbetoile, k);
					k++;
					nbetoile += 2;
					nbespace--;
					j++;
				}
			}
			else
			{
				draw(nbespace, nbetoile);
				j++;
			}
			nbespace--;
		}
		if((i == size - 1) && (j == etage - 1))
			i++;
		else
		{
			nbetoile = nbetoile + 2 + (2 * decalage(i));
			nbespace--;
			nbespace -= decalage(i);
			etage++;
			tmp--;
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	char *resp;
	int size;
	resp = argv[1];
	size = ft_atoi(resp);
	if(argc == 2)
		sastantua(size);
	else
		return(0);
	return(0);
}
