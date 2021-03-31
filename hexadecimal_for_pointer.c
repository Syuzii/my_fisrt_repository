/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal_for_pointer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:52:42 by symatevo          #+#    #+#             */
/*   Updated: 2021/03/31 13:55:50 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_parser(long long unsigned int tmp, char str)
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

char	*convert_hex_forpointer(long long unsigned int n, char *str, int size)
{
	long long unsigned int	tmp;
	char					*ptr;

	tmp = n;
	ptr = str;
	if (n == 0)
	{
		*str = '0';
		str++;
	}
	while (size > 0)
	{
		tmp = n % 16;
		n = n / 16;
		if (tmp < 10)
			*str = tmp + '0';
		else if (tmp > 9 && tmp < 16)
			*str = ft_parser(tmp, *str);
		str++;
		size--;
	}
	*str = 'x';
	str++;
	*str = '0';
	return (ptr);
}

char	*make_hex_forpointer(long long unsigned int n)
{
	char					*str;
	long long unsigned int	tmp;
	int						size;

	size = 0;
	tmp = n;
	while (tmp > 0)
	{
		tmp = tmp / 16;
		size++;
	}
	str = calloc(sizeof(char), (size + 3));
	str = convert_hex_forpointer(n, str, size);
	str = ft_strrev_bonus(str);
	return (str);
}
