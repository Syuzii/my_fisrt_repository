/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_digit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:38:15 by symatevo          #+#    #+#             */
/*   Updated: 2021/03/31 12:38:51 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reverse_digit(char *str)
{
	char	*ptr;
	char	*tmp;
	char	c;

	ptr = str;
	tmp = str;
	while (*ptr)
	{
		if (*tmp && (ft_isdigit(*ptr) || *ptr == '-'))
		{
			c = *ptr;
			*ptr = *tmp;
			*tmp = c;
			tmp++;
		}
		ptr++;
	}
	return (str);
}
