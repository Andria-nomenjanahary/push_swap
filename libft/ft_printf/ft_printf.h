/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvoandri <yvoandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 07:36:54 by yvoandri          #+#    #+#             */
/*   Updated: 2026/02/19 09:07:33 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft.h"
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int				ft_printf(const char *format, ...);
int				check_format(char c, va_list args);
int				unsigned_format(unsigned int nbr);
void			hexa_format(size_t n, int uppercase);
size_t			pointer_format(void *v);
unsigned long	int_len(long n);
int				check_hexa(char c, va_list args);
int				hex_len(size_t n);
long int		ft_putnbr_and_count(int n);
int				ft_puthex_and_count(size_t n, int uppercase);
int				ft_putstr_and_count(char *s);

#endif
