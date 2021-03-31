/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:12:52 by symatevo          #+#    #+#             */
/*   Updated: 2021/03/26 17:17:56 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle(const char *keep, int i, t_flags *flags, va_list args)
{
	int char_count;

	char_count = 0;
	if (keep[i] == 'd' || keep[i] == 'i')
		char_count += count_d(keep, i, flags, args);
	if (keep[i] == 's')
		char_count += count_s(keep, i, flags, args);
	if (keep[i] == 'c')
		char_count += count_c(flags, args);
	if (keep[i] == 'x' || keep[i] == 'X')
		char_count += count_hex(keep, i, flags, args);
	if (keep[i] == 'u')
		char_count += count_unsigned(keep, i, flags, args);
	if (keep[i] == 'p')
		char_count += count_pointer(keep, i, flags, args);
	if (keep[i] == '%')
		char_count += ft_putchar(keep[i]);
	return (char_count);
}
