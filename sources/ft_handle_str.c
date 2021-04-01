/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:33:00 by symatevo          #+#    #+#             */
/*   Updated: 2021/04/01 19:37:12 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*make_str_s(t_flags *flags, char *ptr)
{
	int		length;
	char	*str;

	str = NULL;
	length = (ft_strlen(ptr));
	if (length >= flags->width && length >= flags->dot)
	{
		if (length >= flags->width && !(flags->dot))
			str = calloc(sizeof(char), (length + 1));
		else if (flags->width >= flags->dot)
			str = calloc(sizeof(char), (flags->width + 1));
		else if (flags->width <= flags->dot)
			str = calloc(sizeof(char), (flags->dot + 1));
	}
	else if (length <= flags->width || length <= flags->dot)
	{
		if (length <= flags->width)
			str = calloc(sizeof(char), (flags->width + 1));
		else if (length <= flags->dot)
			str = calloc(sizeof(char), (length + 1));
	}
	return (str);
}

char	*spec_s(char *str, char *ptr)
{
	int		i;
	int		j;

	i = ft_strlen(ptr);
	j = ft_strlen(str);
	while (i-- > 0 && j-- > 0)
		str[j] = ptr[i];
	return (str);
}

char	*dot_s(char *str, int dot, int width, int length)
{
	if (length < width && length < dot)
		while (length > 0 && width-- > 0)
		{
			str[width] = '1';
			length--;
		}
	else if (length >= dot)
	{
		if (dot >= width)
			while (dot-- > 0)
				str[dot] = '1';
		else if (dot < width)
		{
			width--;
			while (dot > 0)
			{
				str[width] = '1';
				width--;
				dot--;
			}
		}
	}
	else if (length <= dot)
		str = ft_dot_s_utils(str, dot, width, length);
	return (str);
}

char	*make_s(const char *keep, int i, t_flags *flags, va_list args)
{
	char *str;
	char *ptr;

	ptr = va_arg(args, char *);
	if (ptr == NULL)
		ptr = "(null)";
	str = make_str_s(flags, ptr);
	if (flags->width)
		str = star_d(str, flags->width);
	if (flags->zero)
		str = zero_s(str, ft_strlen(ptr));
	if (flags->dot)
		str = dot_s(str, flags->dot, flags->width, ft_strlen(ptr));
	if ((int)ft_strlen(ptr) > flags->width &&
			(((!(flags->dot) && !(ft_checkdot(keep, i))) || (flags->dot < 0 && flags->dot != -1 ) || (flags->dot == -1 && ft_checkstar(keep, i)))))
		str = ft_putptr(str, ptr);
	else if (flags->dot || ft_checkdot(keep, i))
		str = write_tmp(str, ptr);
	else
		str = spec_s(str, ptr);
	if (flags->minus == 1 && !(flags->zero))
		str = ft_reverse_str(str, ft_strlen(ptr), flags->dot);
	return (str);
}

int		count_s(const char *keep, int i, t_flags *flags, va_list args)
{
	char	*ptr;
	char	*tmp;
	int		length;

	length = 0;
	tmp = make_s(keep, i, flags, args);
	ptr = tmp;
	length = ft_strlen(ptr);
	ft_putstr_fd(ptr, 1);
	free(tmp);
	return (length);
}
