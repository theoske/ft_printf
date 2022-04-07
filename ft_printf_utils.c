/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:51:33 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/04/07 18:03:24 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_dectohex(char *tab, unsigned long int nbr)
{
	int		temp;
	int		i;
	char	*str;
	char	*strrev;

	temp = 0;
	str = NULL;
	strrev = NULL;
	while (nbr != 0 || !str)
	{
		temp = nbr % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 87;
		str = ft_charjoin2(str, (char)temp);
		nbr = nbr / 16;
	}
	i = ft_strlen(str);
	while (i-- > 0)
		strrev = ft_charjoin2(strrev, str[i]);
	tab = ft_strjoin(tab, strrev);
	free (str);
	free (strrev);
	return (tab);
}

char	*ft_dectobighex(char *tab, unsigned long int nbr)
{
	int		temp;
	int		i;
	char	*str;
	char	*strrev;

	temp = 0;
	str = NULL;
	strrev = NULL;
	while (nbr != 0 || !str)
	{
		temp = nbr % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 55;
		str = ft_charjoin(str, (char)temp);
		nbr = nbr / 16;
	}
	i = ft_strlen(str);
	while (i-- > 0)
		strrev = ft_charjoin(strrev, str[i]);
	tab = ft_strjoin(tab, strrev);
	free (str);
	free (strrev);
	return (tab);
}

char	*ft_charjoin(char *tab, char c)
{
	int			i;
	int			size;
	static int	zero = 0;
	char		*str;

	i = 0;
	if (c == 0)
	{
		zero++;
		c = 'F';
	}
	if (zero > 0)
		ft_putstr(tab);
	size = ft_strlen(tab);
	str = malloc(sizeof(char) * (size + 2));
	str = ft_memcpy(str, tab, size);
	if (!str)
		return (NULL);
	str[size] = c;
	str[size + 1] = '\0';
	free(tab);
	return (str);
}

char	*ft_charjoin2(char *tab, char c)
{
	int			i;
	int			size;
	char		*str;

	i = 0;
	size = ft_strlen(tab);
	str = malloc(sizeof(char) * (size + 2));
	str = ft_memcpy(str, tab, size);
	if (!str)
		return (NULL);
	str[size] = c;
	str[size + 1] = '\0';
	free(tab);
	return (str);
}

char	*ft_ptr(char *tab, unsigned long int nbr)
{
	tab = ft_strjoin(tab, "0x");
	if (nbr == 0)
	{
		tab = ft_strjoin(tab, "0");
		return (tab);
	}
	tab = ft_dectohex(tab, nbr);
	return (tab);
}
