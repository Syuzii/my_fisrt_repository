/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal_for_pointer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:52:42 by symatevo          #+#    #+#             */
/*   Updated: 2021/03/31 14:11:28 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_parser_forup(unsigned int tmp, char str)
{
	if (tmp == 10)
		str = 'A';
	else if (tmp == 11)
		str = 'B';
	else if (tmp == 12)
		str = 'C';
	else if (tmp == 13)
		str = 'D';
	else if (tmp == 14)
		str = 'E';
	else
		str = 'F';
	return (str);
}

char	*convert_hex_up(unsigned int n, char *str, int size)
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
			*str = ft_parser_forup(tmp, *str);
		str++;
		size--;
	}
	return (ptr);
}

char	*make_hex_up(unsigned int n)
{
	unsigned int	tmp;
	int				size;
	char			*str;

	tmp = n;
	size = 0;
	while (tmp > 0)
	{
		tmp = tmp / 16;
		size++;
	}
	str = calloc(sizeof(char), (size + 1));
	if (tmp == 0)
		*str = '0';
	str = convert_hex_up(n, str, size);
	str = ft_strrev_bonus(str);
	return (str);
}
