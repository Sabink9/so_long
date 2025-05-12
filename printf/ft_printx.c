/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saciurus <saciurus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:14:28 by saciurus          #+#    #+#             */
/*   Updated: 2025/01/24 16:22:24 by saciurus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printx(unsigned int hexa)
{
	int		tab_len;
	int		tab_i;
	char	*tab;

	tab_len = ft_len_tab(hexa);
	tab_i = tab_len - 1;
	tab = (char *)malloc(sizeof(char) * (tab_len + 1));
	if (!tab)
		return (0);
	if (hexa == 0)
		tab[0] = '0';
	while (hexa > 0)
	{
		if ((hexa % 16) > 9)
			tab[tab_i] = (hexa % 16) + 87;
		else
			tab[tab_i] = (hexa % 16) + 48;
		hexa /= 16;
		tab_i--;
	}
	tab[tab_len] = '\0';
	ft_prints(tab);
	free(tab);
	return (tab_len);
}
