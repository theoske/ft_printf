/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:01:03 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/04/11 14:33:25 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	char	*tab;

	ret = 0;
	j = ft_numbers(n);
	tab = NULL;
	if (n == 0)
		return (ft_putchar('0'));
	tab = malloc(sizeof(char) * (j));
	if (!tab)
		return (0);
	tab[j - 1] = 0;
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