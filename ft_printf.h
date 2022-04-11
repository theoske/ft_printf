/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:22:06 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/04/11 14:33:22 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_strlen(char *str);
int		ft_putstr(char *str);
char	*ft_charjoin(char *tab, char c);
int		ft_dectobighex(unsigned long int nbr);
int		ft_dectohex(unsigned long int nbr);
int		ft_ptr(unsigned long int nbr);
int		ft_numbers(long int n);
int		ft_filling(long int n);
int		ft_itoa(int n);
int		ft_percent(int i, const char *str);
int		ft_printf2(int i, const char *str);
int		ft_printf_options(const char *str, int *ptri, va_list ptr);
int		ft_printf(const char *str, ...);

#endif
