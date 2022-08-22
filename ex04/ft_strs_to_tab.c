#include "ft_stock_str.h"
#include <stdlib.h>
#include <stdio.h>


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
	while (n < ac)
	{
		printf("string %s\n", tab[n].str);
		printf("size %d\n", tab[n].size);
		n++;
	}
	return 0;
}
