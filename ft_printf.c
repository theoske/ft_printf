/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:09:06 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/04/11 15:06:49 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_percent(int i, const char *str)
{
	int		ret;

	ret = 0;
	ret += ft_putchar('%');
	if ((str[i + 2]) && (str[i + 2] == 'c' || str[i + 2] == 's'
			|| str[i + 2] == 'd'
			|| str[i + 2] == 'i' || str[i + 2] == 'x' || str[i + 2] == 'X'
			|| str[i + 2] == 'p' || str[i + 2] == 'u'))
		ret += ft_putchar(str[i + 2]);
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
	else if (str[*ptri + 1] == 'x')
		ret += ft_dectohex(va_arg(ptr, unsigned int));
	else if (str[*ptri + 1] == 'X')
		ret += ft_dectobighex(va_arg(ptr, unsigned int));
	else if (str[*ptri + 1] == '%')
		ret += ft_percent(*ptri, str);
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
