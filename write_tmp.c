/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_hex_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:21:03 by symatevo          #+#    #+#             */
/*   Updated: 2021/03/31 13:21:09 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*write_tmp(char *str, char *ptr)
{
	char	*tmp;

	tmp = str;
	while (*tmp)
	{
		if (*tmp == '1')
		{
			*tmp = *ptr;
			ptr++;
		}
		tmp++;
	}
	return (str);
}
