/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:22:06 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/04/07 18:14:25 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int			ft_strlen(const char *s);
void		ft_putstr(char *tab);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_unitoa(unsigned int n, char *str);
char		*ft_dectohex(char *tab, unsigned long int nbr);
char		*ft_dectobighex(char *tab, unsigned long int nbr);
char		*ft_charjoin(char *tab, char c);
char		*ft_charjoin2(char *tab, char c);
char		*ft_ptr(char *tab, unsigned long int nbr);
long int	ft_numbers(long int n);
char		*filling(long int n, char *tab, long int j, long int numbers);
char		*ft_itoa(int n, char *str);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*ft_percent(char *tab, const char *str, int i);
int			ft_printf2(int i, const char *str);
char		*ft_printf_options(char *tab, const char *str,
				int *ptri, va_list ptr);
int			ft_printf(const char *str, ...);

#endif
