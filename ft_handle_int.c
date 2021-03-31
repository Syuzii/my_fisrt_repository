/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:37:26 by symatevo          #+#    #+#             */
/*   Updated: 2021/03/29 18:00:51 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*make_str_d(t_flags *flags, int length)
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

char	*spec_d(char *str, char *ptr, t_flags *flags, int *length)
{
	int i;
	int j;

	i = ft_strlen(ptr);
	j = ft_strlen(str);
	while (i-- > 0 && j-- > 0)
	{
		if (ptr[i] == '-' && flags->dot >= flags->width && !(flags->zero))
		{
			write(1, "-", 1);
			*length += 1;
			break ;
		}
		if ((ptr[i] == '-' && flags->dot >= (int)ft_strlen(ptr)) &&
				(flags->dot < flags->width || flags->zero))
			break ;
		str[j] = ptr[i];
	}
	return (str);
}

char	*make_d(const char *keep, int idx, t_flags *flags, int *length)
{
	char *str;
	char *ptr;

	ptr = ft_itoa(flags->type);
	str = make_str_d(flags, ft_strlen(ptr));
	if (flags->width)
		str = star_d(str, flags->width);
	if (flags->zero || flags->dot)
		str = dot_d(str, flags);
	if ((flags->dot == -1 || ft_checkdot(keep, idx)) && flags->type == 0)
		ptr = "\0";
	else if ((int)ft_strlen(ptr) > flags->dot &&
			(int)ft_strlen(ptr) > flags->width)
		str = ft_putptr(str, ptr);
	else
		str = spec_d(str, ptr, flags, length);
	if (flags->minus == 1)
		str = ft_reverse_digit(str);
	return (str);
}

int		count_d(const char *keep, int i, t_flags *flags, va_list args)
{
	char	*ptr;
	char	*tmp;
	int		length;

	flags->type = va_arg(args, int);
	length = 0;
	tmp = make_d(keep, i, flags, &length);
	ptr = tmp;
	length += ft_strlen(ptr);
	ft_putstr_fd(ptr, 1);
	free(tmp);
	return (length);
}
