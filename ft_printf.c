/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:27:39 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/03/28 15:46:10 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/* chercher % et les remplacer par variable ou juste les enlever
	verifier cara par cara et str join*/

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_stradd(char *ret, char addon)
{
	int		size;

	size = ft_strlen(ret);
	if (!ret)
		ret = malloc(sizeof(char) * 2);
	else
		ret = malloc(sizeof(char) * (size + 1));
	ret[size] = addon;
	ret[size + 1] = '\0';
	return (ret);
}

//tab : resultat affichable
int	ft_printf(const char *str, ...)
{
	int		i;
	char	*tab;

	i = 0;
	tab = NULL;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == 'c')
			ft_joinchar
		else if (str[i] == '%' && str[i + 1] == 's')
			ft_joinstr
		else if (str[i] == '%' && str[i + 1] == 'p')
			ft_joinptr
		else if (str[i] == '%' && str[i + 1] == 'd')
			ft_joinnbr
		else if (str[i] == '%' && str[i + 1] == 'i')
			ft_joinnbr
		else if (str[i] == '%' && str[i + 1] == 'u')
			ft_joinnbr
		else if (str[i] == '%' && str[i + 1] == 'x')
			ft_joinhexamin
		else if (str[i] == '%' && str[i + 1] == 'X')
			ft_joinhexamaj
		else if (str[i] == '%' && str[i + 1] == '%')//passe les deux '%'
		{
			tab = ft_stradd(tab, str[i])
			i++;
		}
		else
			tab = ft_stradd(tab, str[i])
		i++;
	}
	ft_write(tab);
	return (ft_strlen(tab));
}


int	main(void)
{
	// int	nbr = 4;

	printf("manger des pates %r");
	return (0);
}
