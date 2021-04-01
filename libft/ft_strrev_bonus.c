/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 19:56:10 by symatevo          #+#    #+#             */
/*   Updated: 2021/01/27 19:57:57 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev_bonus(char *str)
{
	int		i;
	int		size;
	char	t;

	i = 0;
	size = ft_strlen(str);
	while (str[i] != 0 && i < size / 2)
	{
		t = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = t;
		i++;
	}
	return (str);
}
