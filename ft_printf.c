/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:27:39 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/04/01 17:21:49 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/* chercher % et les remplacer par variable correspondante 
	via conversions en char et strjoin*/

void	ft_putstr(char *tab)
{
	int		i;

	i = 0;
	while (tab && tab[i])
	{
		write(1, &tab[i], 1);
		i++;
	}
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	j = 0;
	i = 0;
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	while (s1 && s1[i])
	{
		join[i] = *(char *)(s1 + i);
		i++;
	}
	while (s2[j])
	{
		join[i + j] = *(char *)(s2 + j);
		j++;
	}
	join[i + j] = '\0';
	free(s1);
	return (join);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	void	*ptr;

	if (dest == NULL && src == NULL)
		return (NULL);
	ptr = dest;
	i = 0;
	while (i < n)
	{
		*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (ptr);
}

char	*ft_charjoin(char *tab, char c)
{
	int		i;
	int		size;
	char	*str;

	i = 0;
	size = ft_strlen(tab);
	str = malloc(sizeof(char) * (size + 2));
	str = ft_memcpy(str, tab, size);
	if (!str)
		return (NULL);
	str[size] = c;
	str[size + 1] = '\0';
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*cpy;

	cpy = malloc(ft_strlen(s) * sizeof(char));
	if (!cpy)
		return (0);
	ft_memcpy(cpy, s, ft_strlen(s) * sizeof(char));
	return (cpy);
}

long int	ft_numbers(long int n)
{
	long int	numbers;

	numbers = 1;
	if (n == 0)
		numbers = 2;
	if (n < 0)
		numbers++;
	while (n != 0)
	{
		n /= 10;
		numbers++;
	}
	return (numbers);
}

char	*filling(long int n, char *tab, long int j, long int numbers)
{
	if (n == 0)
	{
		tab[j] = 48;
		tab[j + 1] = '\0';
		return (tab);
	}
	while (n > 0)
	{
		numbers = n / 10;
		tab[j] = n - (numbers * 10) + 48;
		n /= 10;
		j--;
	}
	return (tab);
}

char	*ft_itoa(int n, char *str)
{
	char		*tab;
	long int	i;
	long int	j;
	long int	numbers;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	numbers = ft_numbers((long int)n);
	tab = malloc(sizeof(char) * numbers);
	if (!tab)
		return (NULL);
	if (n < 0)
	{
		tab[i] = '-';
		i++;
		n *= -1;
	}
	j = numbers - 2;
	tab[numbers - 1] = '\0';
	tab = filling((long int)n, tab, j, numbers);
	tab = ft_strjoin(str, tab);
	return (tab);
}

char	*ft_dectohex(char *tab, int nbr)
{
	int		temp;
	int		i;
	char	*str;
	char	*strrev;

	temp = 0;
	str = NULL;
	strrev = NULL;
	while (nbr != 0)
	{
		temp = nbr % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 87;
		str = ft_charjoin(str, (char)temp);
		nbr = nbr / 16;
	}
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		strrev = ft_charjoin(strrev, str[i]);
		i--;
	}
	tab = ft_strjoin(tab, strrev);
	return (tab);
}

char	*ft_dectobighex(char *tab, int nbr)
{
	int		temp;
	int		i;
	char	*str;
	char	*strrev;

	temp = 0;
	str = NULL;
	strrev = NULL;
	while (nbr != 0)
	{
		temp = nbr % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 55;
		str = ft_charjoin(str, (char)temp);
		nbr = nbr / 16;
	}
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		strrev = ft_charjoin(strrev, str[i]);
		i--;
	}
	tab = ft_strjoin(tab, strrev);
	return (tab);
}

char	*ft_percent(char *tab, const char *str, int i)
{
	char	c;

	tab = ft_charjoin(tab, '%');
	c = str[i + 2];
	if (c == 99 || c == 115 || c == 112 || c == 100 
		|| c == 105 || c == 117 || c == 120 || c == 88)
		tab = ft_charjoin(tab, c);
	return (tab);
}

char	*ft_printf_options(char *tab, const char *str, int i, va_list ptr)
{
	if (str[i + 1] == 'c')
		tab = ft_charjoin(tab, va_arg(ptr, int));
	else if (str[i + 1] == 's')
		tab = ft_strjoin(tab, va_arg(ptr, char *));
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		tab = ft_itoa(va_arg(ptr, int), tab);
	else if (str[i + 1] == 'x')
		tab = ft_dectohex(tab, va_arg(ptr, int));
	else if (str[i + 1] == 'X')
		tab = ft_dectobighex(tab, va_arg(ptr, int));
	else if (str[i + 1] == '%')
		tab = ft_percent(tab, str, i);
	return (tab);
}

//tab : resultat affichable
int	ft_printf(const char *str, ...)
{
	int		i;
	char	*tab;
	char	*tab2;
	va_list	ptr;

	tab = NULL;
	tab2 = NULL;
	i = 0;
	va_start(ptr, str);
	while (str[i])
	{
		while(str[i] && str[i] != '%')
		{
			tab = ft_charjoin(tab, str[i]);
			i++;
		}
		if (str[i] && str[i] == '%')
		{
			tab = ft_printf_options(tab, str, i, ptr);
			if (str[i + 1] && str[i + 1] == '%')
				i++;
			if (str[i + 1] == 99 || str[i + 1] == 115 || str[i + 1] == 112 
				|| str[i + 1] == 100 || str[i + 1] == 105 || str[i + 1] == 117 
				|| str[i + 1] == 120 || str[i + 1] == 88)
				i++;
		}
		if (str[i])
			i++;
	}
	va_end(ptr);
	ft_putstr(tab);
	return (ft_strlen(tab));
}

int	main(void)
{
	char	c;
	char	s[] = "pommes et des";
	int		d = 200000;
	int		*ptr;

	ptr = &d;	
	c = 'F';
	// printf("%p", ptr);
	d = ft_printf("\nmanger de %%c %c %s %i %x aaaaa\n",c, s, d, d);
	printf("\n %x \n", 200000);
	return (0);
}
// manger despommes et despFates30d40foisparsemaine30D40200000