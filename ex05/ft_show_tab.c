#include "ft_stock_str.h"
#include <stdlib.h>
#include <unistd.h>


void ft_putchar(char c)
{
	write(1, &c, 1);
}


void ft_putstr(char *str)
{
	char *pstr;
	
	pstr = str;
	while (*(pstr) != '\0')
		ft_putchar(*(pstr++));
}


void ft_putsize(int size)
{	// recursive !
	while (size > 10)
	{
		ft_putsize(size / 10); // recurse !
		ft_putchar('0' + (size % 10));
		return;
	}
	ft_putchar('0' + size);
}


void ft_show_tab(struct s_stock_str *par)
{
	int	n;

	n = 0;
	while(par[n].str != 0) // while there are strings;
	{
		ft_putstr(par[n].str);
		ft_putchar('\n');
		ft_putsize(par[n].size);
		ft_putchar('\n');
		ft_putstr(par[n].copy);
		ft_putchar('\n');
		n++;
	}
}





//  DONT NEED THIS DOWN HERE !!!

char *copyofstr(char *str, int size)
{
	char *copy = (char *) malloc (size);
	char *pcopy;
	pcopy = copy;
	while (*(str) != '\0')
		*(pcopy++) = *(str++);
	*pcopy = '\0';
	return copy;
}


int ft_strlen(char *str)
{
	int size;
	size = 0;
	while (*(str++) != '\0')
		size++;
	return size;
}


t_stock_str *ft_strs_to_tab(int ac, char **av)
{
	t_stock_str *tab;
	int n;
	int size;
	char *str;
	
	tab = (t_stock_str *) malloc (sizeof(t_stock_str) * (ac +  1));
	if (!tab)
		return 0;
	n = 0;
	while (n < ac)
	{
		str = *(av + n);
		size = ft_strlen(str);
		tab[n].str = str;
		tab[n].size = size;
		tab[n].copy = copyofstr(str, size);
		n++;
	}	// leaves with n being == ac ; which is index of '\0' meaning end of array of strings
	tab[n].str = 0;
	return tab;
}



int main()
{	
	char *av[8] = {"Hello", "World", "", "9213kodm138", "Zagadu", "Xanadu", "Gradabadu"};
	int ac = 7;
	int n = 0;
	t_stock_str *tab = ft_strs_to_tab(ac, av);
	ft_show_tab(tab);
	return 0;
}
