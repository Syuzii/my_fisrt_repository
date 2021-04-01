/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:39:03 by symatevo          #+#    #+#             */
/*   Updated: 2021/03/31 13:50:59 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reverse_hex(char *str, int length, int dot)
{
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(str);
	if (dot > length && dot)
		while (i > 0 && dot > 0)
		{
			i--;
			dot--;
		}
	else
		while (i > 0 && length > 0)
		{
			i--;
			length--;
		}
	str = reverse_elements(str, i);
	return (str);
}
