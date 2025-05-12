/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saciurus <saciurus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:58:42 by saciurus          #+#    #+#             */
/*   Updated: 2025/01/24 16:22:21 by saciurus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printu(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb < 10)
		count += ft_printc(nb + '0');
	else
	{
		count += ft_printu(nb / 10);
		count += ft_printu(nb % 10);
	}
	return (count);
}
