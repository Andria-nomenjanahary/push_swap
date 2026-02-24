/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvoandri <yvoandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 07:14:40 by yvoandri          #+#    #+#             */
/*   Updated: 2026/02/15 11:09:46 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_validity(const char *format, char *symboles, va_list args,
							int count)
{
	if (ft_strchr(symboles, *(format + 1)))
	{
		format++;
		count += check_format(*format, args);
	}
	else
	{
		format++;
		write(1, format, 1);
		count++;
	}
	return (count);
}

static int	count_char(const char *format, char *symboles,
						va_list args, int count)
{
	while (*format)
	{
		if (*format == '%')
		{
			if (!*(format + 1))
				break ;
			count = check_validity(format, symboles, args, count);
			format++;
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	char	*symboles;

	if (!format)
		return (-1);
	va_start(args, format);
	symboles = "cspdiuxX%";
	count = 0;
	count = count_char(format, symboles, args, count);
	va_end(args);
	return (count);
}
