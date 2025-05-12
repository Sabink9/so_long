/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saciurus <saciurus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:54:24 by saciurus          #+#    #+#             */
/*   Updated: 2025/01/24 16:22:05 by saciurus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printd(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		count += ft_printc('-');
		count += ft_printd(214748364);
		count += ft_printc('8');
	}
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			count += ft_printc('-');
		}
		if (nb < 10)
			count += ft_printc(nb + '0');
		else
		{
			count += ft_printd(nb / 10);
			count += ft_printd(nb % 10);
		}
	}
	return (count);
}
