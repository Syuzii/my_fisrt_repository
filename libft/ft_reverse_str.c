/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:43:31 by symatevo          #+#    #+#             */
/*   Updated: 2021/03/31 12:44:14 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*reverse_elements(char *str, int i)
{
	char	temp;
	int		j;

	j = 0;
	while (str[i])
	{
		temp = str[j];
		str[j] = str[i];
		str[i] = temp;
		j++;
		i++;
	}
	return (str);
}

char	*ft_reverse_str(char *str, int length, int dot)
{
	int i;

	i = ft_strlen(str);
	if (dot < length && dot)
	{
		while (i > 0 && dot > 0)
		{
			i--;
			dot--;
		}
	}
	else
	{
		while (i > 0 && length > 0)
		{
			i--;
			length--;
		}
	}
	str = reverse_elements(str, i);
	return (str);
}
