/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:09:06 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/04/11 13:22:23 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_strlen(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		ret += ft_putchar(str[i]);
		i++;
	}
	return (ret);
}

char	*ft_charjoin(char *tab, char c)
{
	int			i;
	int			size;
	char		*str;

	i = 0;
	size = ft_strlen(tab);
	str = malloc(sizeof(char) * (size + 2));
	while (i < size)
	{
		str[i] = tab[i];
		i++;
	}
	if (!str)
		return (NULL);
	str[size] = c;
	str[size + 1] = '\0';
	free(tab);
	return (str);
}

int	ft_dectohex(unsigned long int nbr)
{
	int		temp;
	int		i;
	int		ret;
	char	*str;

	temp = 0;
	ret = 0;
	str = NULL;
	while (nbr != 0 || !str)
	{
		temp = nbr % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 87;
		str = ft_charjoin(str, temp);
		nbr = nbr / 16;
	}
	i = ft_strlen(str);
	while (i--)
		ret += ft_putchar(str[i]);
	free (str);
	return (ret);
}

int	ft_ptr(unsigned long int nbr)
{
	int		ret;

	ret = 0;
	ret += ft_putstr("0x");
	if (nbr == 0)
	{
		ret += ft_putstr("0");
		return (ret);
	}
	ret += ft_dectohex(nbr);
	return (ret);
}

int	ft_numbers(long int n)
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

int	ft_filling(long int n)
{
	int		j;
	int		ret;
	int		temp;
	char	*tab;

	ret = 0;
	j = ft_numbers(n);
	tab = NULL;
	tab = malloc(sizeof(char) * (j + 1));
	if (!tab)
		return (0);
	if (n == 0)
		return (ft_putchar('0'));
	tab[j] = 0;
	j--;
	while (j > 0)
	{
		tab[j - 1] = (n % 10) + 48;
		n /= 10;
		j--;
	}
	ret += ft_putstr(tab);
	free (tab);
	return (ret);
}

int	ft_itoa(int n)
{
	long int	i;
	long int	j;
	int			ret;

	i = 0;
	ret = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		ret += ft_putchar('-');
		i++;
		n *= -1;
	}
	ret += ft_filling(n);
	return (ret);
}

int	ft_printf2(int i, const char *str)
{
	if (str[i + 1] && str[i + 1] == '%')
		i++;
	if (str[i + 1] == 'c' || str[i + 1] == 's' || str[i + 1] == 'd'
		|| str[i + 1] == 'i' || str[i + 1] == 'x' || str[i + 1] == 'X'
		|| str[i + 1] == 'p' || str[i + 1] == 'u')
		i++;
	return (i);
}

int	ft_printf_options(const char *str, int *ptri, va_list ptr)
{
	int		ret;

	ret = 0;
	if (str[*ptri + 1] == 'c')
		ret += ft_putchar(va_arg(ptr, int));
	if (str[*ptri + 1] == 's')
		ret += ft_putstr(va_arg(ptr, char *));
	else if (str[*ptri + 1] == 'p')
		ret += ft_ptr(va_arg(ptr, unsigned long int));
	else if (str[*ptri + 1] == 'd' || str[*ptri + 1] == 'i')
		ret += ft_itoa(va_arg(ptr, int));
	else if (str[*ptri + 1] == 'u')
		ret += ft_filling(va_arg(ptr, unsigned int));
	// else if (str[i + 1] == 'x')
	// 	ret += ft_dectohex(va_arg(ptr, unsigned int));
	// else if (str[i + 1] == 'X')
	// 	ret += ft_dectobighex(va_arg(ptr, unsigned int));
	// else if (str[i + 1] == '%')
	// 	ret += ft_percent(str, i);
	*ptri = ft_printf2(*ptri, str);
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		ret;
	va_list	ptr;

	i = 0;
	ret = 0;
	va_start(ptr, str);
	while (str[i])
	{
		while (str[i] && str[i] != '%')
		{
			ret += ft_putchar(str[i]);
			i++;
		}
		if (str[i] && str[i] == '%')
		{
			ret += ft_printf_options(str, &i, ptr);
			i++;
		}
	}
	va_end(ptr);
	return (ret);
}

#include <stdio.h>

int main()
{
	int d;
	int *ptri = &d;
	
	d = ft_printf("jem %%%d%c\n%u ange\n", -2, 'f', -429496295);
	printf("jem %%%d%c\n%u ange\n", -2, 'f', -429496295);
	return 0;
}