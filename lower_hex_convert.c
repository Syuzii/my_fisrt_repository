/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_hex_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:21:03 by symatevo          #+#    #+#             */
/*   Updated: 2021/03/31 14:07:00 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_parser_forlow(unsigned int tmp, char str)
{
	if (tmp == 10)
		str = 'a';
	else if (tmp == 11)
		str = 'b';
	else if (tmp == 12)
		str = 'c';
	else if (tmp == 13)
		str = 'd';
	else if (tmp == 14)
		str = 'e';
	else
		str = 'f';
	return (str);
}

char	*convert_hex(unsigned int n, char *str, int size)
{
	unsigned int	tmp;
	char			*ptr;

	tmp = n;
	ptr = str;
	while (size > 0)
	{
		tmp = n % 16;
		n = n / 16;
		if (tmp < 10)
			*str = tmp + '0';
		else if (tmp > 9 && tmp < 16)
			*str = ft_parser_forlow(tmp, *str);
		str++;
		size--;
	}
	return (ptr);
}

char	*make_hex(unsigned int n)
{
	char			*str;
	unsigned int	tmp;
	int				size;

	tmp = n;
	size = 0;
	while (tmp > 0)
	{
		tmp = tmp / 16;
		size++;
	}
	str = calloc(sizeof(char), (size + 1));
	str = convert_hex(n, str, size);
	if (n == 0)
		*str = '0';
	str = ft_strrev_bonus(str);
	return (str);
}
