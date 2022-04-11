/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:57:48 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/04/11 15:08:12 by tkempf-e         ###   ########.fr       */
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
