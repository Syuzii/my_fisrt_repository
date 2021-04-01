/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:33:01 by symatevo          #+#    #+#             */
/*   Updated: 2021/03/29 19:43:51 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*make_str_hex(t_flags *flags, int length)
{
	char *str;

	str = NULL;
	if (length >= flags->width && length >= flags->dot)
		str = calloc(sizeof(char), (length + 1));
	else if (length <= flags->width && length <= flags->dot)
	{
		if (flags->width >= flags->dot)
			str = calloc(sizeof(char), (flags->width + 1));
		else if (flags->width <= flags->dot)
			str = calloc(sizeof(char), (flags->dot + 1));
	}
	else if (length <= flags->width || length <= flags->dot)
	{
		if (length <= flags->width)
			str = calloc(sizeof(char), (flags->width + 1));
		else if (length <= flags->dot)
			str = calloc(sizeof(char), (flags->dot + 1));
	}
	return (str);
}

char	*spec_hex(char *str, char *ptr)
{
	int	i;
	int	j;

	i = ft_strlen(ptr);
	j = ft_strlen(str);
	while (i-- > 0 && j-- > 0)
		str[j] = ptr[i];
	return (str);
}

char	*make_hexadecimal(const char *keep, int i, t_flags *flags,
		unsigned int a)
{
	char *str;
	char *ptr;

	if (keep[i] == 'x')
		ptr = make_hex(a);
	else if (keep[i] == 'X')
		ptr = make_hex_up(a);
	str = make_str_hex(flags, ft_strlen(ptr));
	if (flags->width)
		str = star_d(str, flags->width);
	if (flags->zero || flags->dot)
		str = dot_d(str, flags);
	if ((flags->dot == -1 || ft_checkdot(keep, i)) && *ptr == '0' && !(ft_checkstar(keep, i)))
		ptr = "\0";
	else if ((int)ft_strlen(ptr) > flags->dot &&
			(int)ft_strlen(ptr) > flags->width)
		str = ft_putptr(str, ptr);
	else
		str = spec_hex(str, ptr);
	if (flags->minus == 1 && (!(flags->dot) ||
				(flags->dot && ft_checkdot(keep, i))))
		str = ft_reverse_hex(str, ft_strlen(ptr), flags->dot);
	return (str);
}

int		count_hex(const char *keep, int i, t_flags *flags, va_list args)
{
	char			*ptr;
	char			*tmp;
	int				length;
	unsigned int	a;

	a = va_arg(args, unsigned int);
	length = 0;
	tmp = make_hexadecimal(keep, i, flags, a);
	ptr = tmp;
	length += ft_strlen(ptr);
	ft_putstr_fd(ptr, 1);
	free(tmp);
	return (length);
}
