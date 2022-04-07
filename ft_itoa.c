/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:01:03 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/04/07 18:10:56 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		return (ft_strjoin(str, "-2147483648"));
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
