/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 20:08:52 by symatevo          #+#    #+#             */
/*   Updated: 2021/03/29 21:11:59 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*make_str_unsigned(t_flags *flags, unsigned int a)
{
	int		length;
	char	*str;
	char	*ptr;

	str = NULL;
	ptr = ft_unsigned_itoa(a);
	length = (ft_strlen(ptr));
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

char	*spec_unsigned(char *str, char *ptr)
{
	int i;
	int j;

	i = ft_strlen(ptr);
	j = ft_strlen(str);
	while (i-- > 0 && j-- > 0)
		str[j] = ptr[i];
	return (str);
}

char	*make_unsigned(const char *keep, int i, t_flags *flags, va_list args)
{
	char			*str;
	char			*ptr;
	unsigned int	a;

	a = va_arg(args, unsigned int);
	str = make_str_unsigned(flags, a);
	ptr = ft_unsigned_itoa(a);
	if (flags->width)
		str = star_d(str, flags->width);
	if (flags->zero || flags->dot)
		str = dot_d(str, flags);
	if ((flags->dot == -1 || ft_checkdot(keep, i)) && a == 0 && !(ft_checkstar(keep, i)))
		ptr = "\0";
	else if ((int)ft_strlen(ptr) > flags->dot &&
			(int)ft_strlen(ptr) > flags->width)
		str = ft_putptr(str, ptr);
	else
		str = spec_unsigned(str, ptr);
	if (flags->minus == 1)
		str = ft_reverse_digit(str);
	return (str);
}

int		count_unsigned(const char *keep, int i, t_flags *flags, va_list args)
{
	char	*ptr;
	char	*tmp;
	int		length;

	length = 0;
	tmp = make_unsigned(keep, i, flags, args);
	ptr = tmp;
	length += ft_strlen(ptr);
	ft_putstr_fd(ptr, 1);
	free(tmp);
	return (length);
}
