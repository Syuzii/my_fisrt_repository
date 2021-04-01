/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:44:26 by symatevo          #+#    #+#             */
/*   Updated: 2021/03/31 13:51:20 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_unsigned_intlen(unsigned int n)
{
	int				i;
	unsigned int	t;

	i = 1;
	t = n;
	if (t < 0)
	{
		t = t * -1;
		i++;
	}
	while (t >= 10)
	{
		t = t / 10;
		i++;
	}
	return (i);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	int				idx;
	unsigned int	positive_n;
	char			*value;

	positive_n = n;
	if (n == 0)
		return (ft_strdup("0"));
	if (!(value = (char *)malloc(sizeof(char) * (ft_unsigned_intlen(n) + 1))))
		return (NULL);
	ft_memset(value, '\0', (ft_unsigned_intlen(n) + 1));
	idx = 0;
	while (positive_n != 0)
	{
		value[idx++] = (positive_n % 10) + '0';
		positive_n = positive_n / 10;
	}
	return (ft_strrev(value));
}
