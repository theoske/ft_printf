/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:57:48 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/04/07 18:14:57 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	ft_putstr(char *tab)
{
	int			i;
	static int	once = 0;

	i = 0;
	while (once == 0 && tab && tab[i])
	{
		write(1, &tab[i], 1);
		i++;
	}
	once++;
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s2)
		s2 = "(null)";
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	while (s1 && s1[i])
	{
		join[i] = *(char *)(s1 + i);
		i++;
	}
	while (s2 && s2[j])
	{
		join[i + j] = *(char *)(s2 + j);
		j++;
	}
	join[i + j] = '\0';
	free(s1);
	return (join);
}

char	*ft_unitoa(unsigned int n, char *str)
{
	char			*tab;
	unsigned int	i;
	unsigned int	j;
	unsigned int	numbers;

	i = 0;
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
	str = ft_strjoin(str, tab);
	free (tab);
	return (str);
}
