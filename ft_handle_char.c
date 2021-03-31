/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:40:05 by symatevo          #+#    #+#             */
/*   Updated: 2021/03/29 18:44:11 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*make_str_c(t_flags *flags)
{
	char	*str;

	str = NULL;
	if (2 <= flags->width)
		str = calloc(sizeof(char), (flags->width + 1));
	else
		str = calloc(sizeof(char), 2);
	return (str);
}

char	*spec_c(char *str, t_flags *flags)
{
	int		j;
	char	*tmp;
	char	c;

	c = flags->type;
	j = ft_strlen(str);
	tmp = str;
	if (flags->minus == 1)
		*tmp = c;
	else if (flags->width > 0)
	{
		j--;
		str[j] = c;
	}
	else
		str[j] = c;
	return (str);
}

char	*make_c(t_flags *flags, va_list args)
{
	char *str;

	flags->type = va_arg(args, int);
	str = make_str_c(flags);
	if (flags->width)
		str = star_d(str, flags->width);
	str = spec_c(str, flags);
	return (str);
}

int		count_c(t_flags *flags, va_list args)
{
	char	*ptr;
	char	*tmp;
	int		length;

	length = 0;
	tmp = make_c(flags, args);
	ptr = tmp;
	length = ft_strlen(ptr);
	if (*ptr == '\0' && flags->minus == 1 && flags->width > 0)
		ptr++;
	ft_putstr_fd(ptr, 1);
	free(tmp);
	return (length);
}
