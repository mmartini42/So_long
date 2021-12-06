/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:09:10 by mathmart          #+#    #+#             */
/*   Updated: 2021/11/06 14:32:31 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(long nb)
{
	size_t	count;

	count = 0;
	if (nb < 0)
	{
		count++;
		nb *= -1;
	}
	while (nb >= 10)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

static	void	ft_add_result(char *dest, long nb, int index)
{
	char	*base;

	base = "0123456789";
	if (nb >= 10)
		ft_add_result(dest, nb / 10, index - 1);
	dest[index] = base[nb % 10];
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*dest;

	nb = (long)n;
	len = ft_len(nb);
	dest = malloc(sizeof(char) * len + 2);
	if (!dest)
		return (NULL);
	if (nb < 0)
	{
		dest[0] = '-';
		nb *= -1;
	}
	ft_add_result(dest, nb, len);
	dest[len + 1] = '\0';
	return (dest);
}
