/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:58:42 by symatevo          #+#    #+#             */
/*   Updated: 2021/03/26 17:12:08 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		init_struct(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.dot = 0;
	flags.width = 0;
	flags.star = 0;
	flags.zero = 0;
	flags.type = 0;
	flags.p = 0;
	return (flags);
}

int			ft_flag_parse(const char *keep, int i, t_flags *flags, va_list args)
{
	while (keep[i])
	{
		if (is_specifier(keep[i]))
			break ;
		else if (keep[i] == '*')
			flags->width = ft_handle_star(args, flags);
		if (keep[i] == '0' && !(ft_isdigit(keep[i - 1])))
			flags = ft_handle_zero(keep, i, flags);
		else if (keep[i] == '-')
			flags = ft_handle_minus(flags);
		else if (ft_isdigit(keep[i]) && !(flags->zero))
			flags->width = (flags->width * 10) + keep[i] - '0';
		if (keep[i] == '.' || flags->zero == 1)
		{
			i = ft_handle_dot(keep, i, args, flags);
			if (is_specifier(keep[i]))
				break ;
		}
		i++;
	}
	return (i);
}

int			ft_handle_keep(const char *keep, va_list args)
{
	int		i;
	int		char_count;
	t_flags	flags;

	i = 0;
	char_count = 0;
	while (1)
	{
		flags = init_struct();
		if (!keep[i])
			break ;
		else if (keep[i] == '%' && keep[i + 1])
		{
			i = ft_flag_parse(keep, ++i, &flags, args);
			if (is_specifier(keep[i]))
				char_count += ft_handle(keep, i, &flags, args);
			else if (keep[i])
				char_count += ft_putchar(keep[i]);
		}
		else if (keep[i] != '%')
			char_count += ft_putchar(keep[i]);
		i++;
	}
	return (char_count);
}

int			ft_printf(const char *format, ...)
{
	const char	*keep;
	va_list		args;
	int			char_count;

	char_count = 0;
	keep = ft_strdup(format);
	va_start(args, format);
	char_count += ft_handle_keep(keep, args);
	free((char *)keep);
	va_end(args);
	return (char_count);
}
