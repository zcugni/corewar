/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex2dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 19:05:11 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/10/18 19:23:44 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

int	ft_strhex2dec(unsigned char *str, int len)
{
	int 	value;
	int		i;

	i = -1;
	value = 0;
	while (++i < len)
	{
		value += str[i] * ft_pow(16, (len - (i + 1)) * 2);
	}
	return (value);
}
