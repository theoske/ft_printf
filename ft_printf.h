/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:22:06 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/04/07 13:39:02 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

void		ft_putstr(char *tab);
int			ft_strlen(const char *s);
char		*ft_strjoin(char *s1, char *s2);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*ft_charjoin(char *tab, char c);
char		*ft_strdup(const char *s);
long int	ft_numbers(long int n);
char		*filling(long int n, char *tab, long int j, long int numbers);
char		*ft_itoa(int n, char *str);
char		*ft_unitoa(unsigned int n, char *str);
char		*ft_dectohex(char *tab, int nbr);
char		*ft_dectobighex(char *tab, int nbr);
char		*ft_percent(char *tab, const char *str, int i);
char		*ft_ptr(char *tab, long int nbr);
char		*ft_printf_options(char *tab, const char *str, int i, va_list ptr);
int			ft_printf(const char *str, ...);

#endif
