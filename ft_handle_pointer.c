/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:47:46 by symatevo          #+#    #+#             */
/*   Updated: 2021/03/30 16:58:49 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_size(unsigned int a)
{
	int size;

	size = 0;
	while (a > 0)
	{
		a = a / 16;
		size++;
	}
	return (size);
}

char	*spec_pointer(char *str, char *ptr, t_flags *flags, int *length)
{
	int	i;
	int	j;
	int	count;

	count = ft_size(flags->p);
	i = ft_strlen(ptr);
	j = ft_strlen(str);
	if (i > flags->dot && i > flags->width)
		str = ft_putptr(str, ptr);
	else
	{
		while (i-- > 0 && j-- > 0)
		{
			if (flags->dot >= flags->width && count == 0)
			{
				*length += 1;
				break ;
			}
			str[j] = ptr[i];
			count--;
		}
	}
	return (str);
}

char	*dot_p(char *str, t_flags *flags)
{
	int dot;
	int width;

	dot = flags->dot;
	width = flags->width;
	if (dot >= width)
	{
		write(1, "0x", 2);
		while (dot-- > 0)
		{
			str[dot] = '0';
		}
	}
	else if (dot < width)
	{
		width--;
		while (dot > 0)
		{
			str[width] = '0';
			width--;
			dot--;
		}
	}
	return (str);
}

char	*make_pointer(const char *keep, int i, t_flags *flags, int *length)
{
	char *str;
	char *ptr;

	ptr = make_hex_forpointer(flags->p);
	str = make_str_hex(flags, ft_strlen(ptr));
	if (flags->width)
		str = star_d(str, flags->width);
	if (flags->zero || flags->dot)
		str = dot_p(str, flags);
	if ((flags->dot == -1 || ft_checkdot(keep, i)) &&
			(ptr == NULL || (ptr[2] == '0' && !(flags->dot))))
	{
		write(1, "0x", 2);
		*length += 2;
		ptr = "\0";
	}
	else
		str = spec_pointer(str, ptr, flags, length);
	if (flags->minus == 1 && (!(flags->dot) ||
			(flags->dot && ft_checkdot(keep, i))))
		str = ft_reverse_hex(str, ft_strlen(ptr), flags->dot);
	free(ptr);
	return (str);
}

int		count_pointer(const char *keep, int i, t_flags *flags, va_list args)
{
	char	*ptr;
	char	*tmp;
	int		length;

	length = 0;
	flags->p = va_arg(args, unsigned long long int);
	tmp = make_pointer(keep, i, flags, &length);
	ptr = tmp;
	length += ft_strlen(ptr);
	ft_putstr_fd(ptr, 1);
	free(tmp);
	return (length);
}
