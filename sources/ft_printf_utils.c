/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:39:05 by symatevo          #+#    #+#             */
/*   Updated: 2021/03/31 12:35:36 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*star_d(char *str, int width)
{
	while (width-- > 0)
		str[width] = ' ';
	return (str);
}

char	*zero_s(char *str, int length)
{
	while (length-- > 0)
		str[length] = '1';
	return (str);
}

char	*dot_d(char *str, t_flags *flags)
{
	int dot;
	int width;

	dot = flags->dot;
	width = flags->width;
	if (dot >= width)
		while (dot-- > 0)
			str[dot] = '0';
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
	if ((flags->type < 0 && flags->width > flags->dot)
			|| (flags->type < 0 && flags->zero))
		str[width] = '-';
	return (str);
}

char	*ft_dot_s_utils(char *str, int dot, int width, int length)
{
	if (dot > width)
		while (length-- > 0)
			str[length] = '1';
	else if (dot <= width)
	{
		while (length > 0 && width-- > 0)
		{
			str[width] = '1';
			length--;
		}
	}
	return (str);
}

char	*ft_putptr(char *str, char *ptr)
{
	char	*tmp;

	tmp = str;
	while (*ptr)
	{
		*tmp = *ptr;
		ptr++;
		tmp++;
	}
	return (str);
}
