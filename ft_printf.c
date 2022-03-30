/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:27:39 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/03/30 11:23:47 by tkempf-e         ###   ########.fr       */
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
	char	*join;
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

char	*ft_printf_options(char *tab, const char *str, int i, va_list ptr)
{
	if (str[i + 1] == 'c')
		tab = ft_charjoin(tab, va_arg(ptr, char));
	return (tab);
}

//tab : resultat affichable
int	ft_printf(const char *str, ...)
{
	int		i;
	char	*tab;
	va_list	ptr;

	tab = NULL;
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
			i++;
		}
		i++;
	}
	va_end(ptr);
	ft_putstr(tab);
	return (ft_strlen(tab));
}

int	main(void)
{
	// int	nbr = 4;
	char	c;
	
	c = 'F';
	ft_printf("\nmanger des p%cates\n", c);
	return (0);
}

// else if (str[i + 1] == 's')
// 			ft_joinstr
// 		else if (str[i + 1] == 'p')
// 			ft_joinptr
// 		else if (str[i + 1] == 'd')
// 			ft_joinnbr
// 		else if (str[i + 1] == 'i')
// 			ft_joinnbr
// 		else if (str[i + 1] == 'u')
// 			ft_joinnbr
// 		else if (str[i + 1] == 'x')
// 			ft_joinhexamin
// 		else if (str[i + 1] == 'X')
// 			ft_joinhexamaj
// 		else if (str[i + 1] == '%')//passe les deux '%'
// 	{
// 		tab = ft_stradd(tab, str[i])
// 		i++;
// 	}