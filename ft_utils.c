/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:57:48 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/04/11 14:33:24 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (!str)
		ret += ft_putstr("(null)");
	while (str && str[i])
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
