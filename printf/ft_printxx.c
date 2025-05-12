/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printxx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saciurus <saciurus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:23:36 by saciurus          #+#    #+#             */
/*   Updated: 2025/01/24 16:22:29 by saciurus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printxx(unsigned int Hexa)
{
	int		tab_len;
	int		tab_i;
	char	*tab;

	tab_len = ft_len_tab(Hexa);
	tab_i = tab_len - 1;
	tab = (char *)malloc(sizeof(char) * (tab_len + 1));
	if (!tab)
		return (0);
	if (Hexa == 0)
		tab[0] = '0';
	while (Hexa > 0)
	{
		if ((Hexa % 16) > 9)
			tab[tab_i] = (Hexa % 16) + 55;
		else
			tab[tab_i] = (Hexa % 16) + 48;
		Hexa /= 16;
		tab_i--;
	}
	tab[tab_len] = '\0';
	ft_prints(tab);
	free(tab);
	return (tab_len);
}
