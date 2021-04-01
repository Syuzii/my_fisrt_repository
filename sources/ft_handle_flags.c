/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:13:21 by symatevo          #+#    #+#             */
/*   Updated: 2021/03/26 17:17:12 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flags	*ft_handle_zero(const char *keep, int i, t_flags *flags)
{
	flags->zero = 1;
	while (keep[i])
	{
		if (keep[i] == '.')
			flags->zero = 0;
		i++;
	}
	return (flags);
}

t_flags	*ft_handle_minus(t_flags *flags)
{
	flags->minus = 1;
	flags->zero = 0;
	return (flags);
}

int		ft_handle_dot(const char *keep, int i, va_list args, t_flags *flags)
{
	i++;
	if (keep[i] == '*')
	{
		flags->dot = va_arg(args, int);
		i++;
	}
	else if (ft_isdigit(keep[i]))
	{
		while (ft_isdigit(keep[i]))
		{
			flags->dot = (flags->dot * 10) + (keep[i] - '0');
			i++;
		}
	}
	else
		flags->dot = -1;
	return (i);
}

int		ft_handle_star(va_list args, t_flags *flags)
{
	int a;

	a = 0;
	a = va_arg(args, int);
	if (a < 0)
	{
		flags->minus = 1;
		a = a * -1;
	}
	return (a);
}
