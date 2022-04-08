/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:27:39 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/04/08 14:35:00 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char	*ft_percent(char *tab, const char *str, int i)
{
	char	c;

	tab = ft_charjoin(tab, '%');
	c = str[i + 2];
	if (c == 'c' || c == 's' || c == 'p' || c == 'x'
		|| c == 'X' || c == 'i' || c == 'u' || c == 'd')
		tab = ft_charjoin(tab, c);
	return (tab);
}

int	ft_printf2(int i, const char *str)
{
	if (str[i + 1] && str[i + 1] == '%')
		i++;
	if (str[i + 1] == 99 || str[i + 1] == 115 || str[i + 1] == 112
		|| str[i + 1] == 100 || str[i + 1] == 105 || str[i + 1] == 117
		|| str[i + 1] == 120 || str[i + 1] == 88)
		i++;
	return (i);
}

char	*ft_printf_options(char *tab, const char *str, int *ptri, va_list ptr)
{
	int		i;

	i = *ptri;
	if (str[i + 1] == 'c')
		tab = ft_charjoin(tab, va_arg(ptr, int));
	else if (str[i + 1] == 's')
		tab = ft_strjoin(tab, va_arg(ptr, char *));
	else if (str[i + 1] == 'p')
		tab = ft_ptr(tab, va_arg(ptr, unsigned long int));
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		tab = ft_itoa(va_arg(ptr, int), tab);
	else if (str[i + 1] == 'u')
		tab = ft_unitoa(va_arg(ptr, unsigned int), tab);
	else if (str[i + 1] == 'x')
		tab = ft_dectohex(tab, va_arg(ptr, unsigned int));
	else if (str[i + 1] == 'X')
		tab = ft_dectobighex(tab, va_arg(ptr, unsigned int));
	else if (str[i + 1] == '%')
		tab = ft_percent(tab, str, i);
	*ptri = ft_printf2(i, str);
	return (tab);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	char	*tab;
	va_list	ptr;

	i = 0;
	tab = NULL;
	va_start(ptr, str);
	while (i >= 0 && str[i])
	{
		while (str[i] && str[i] != '%')
		{
			tab = ft_charjoin(tab, str[i]);
			i++;
		}
		if (str[i] && str[i] == '%')
			tab = ft_printf_options(tab, str, &i, ptr);
		if (str[i])
			i++;
	}
	va_end(ptr);
	ft_putstr(tab);
	i = ft_strlen(tab);
	free (tab);
	return (i);
}
