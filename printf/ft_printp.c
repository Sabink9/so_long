/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saciurus <saciurus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:23:22 by saciurus          #+#    #+#             */
/*   Updated: 2025/01/24 17:24:41 by saciurus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_tab_long(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

void	create_tab(unsigned long addr, char *tab, int tab_i)
{
	while (addr > 0)
	{
		if ((addr % 16) > 9)
			tab[tab_i] = (addr % 16) + 87;
		else
			tab[tab_i] = (addr % 16) + 48;
		addr /= 16;
		tab_i--;
	}
}

int	ft_printp(void *ptr)
{
	unsigned long	addr;
	int				tab_len;
	int				tab_i;
	char			*tab;

	if (!ptr)
		return (ft_prints("(nil)"));
	addr = (unsigned long)ptr;
	tab_len = ft_len_tab_long(addr);
	tab_i = tab_len - 1;
	tab = (char *)malloc(sizeof(char) * (tab_len + 1));
	if (!tab)
		return (0);
	ft_prints("0x");
	create_tab(addr, tab, tab_i);
	tab[tab_len] = '\0';
	ft_prints(tab);
	free(tab);
	return (tab_len + 2);
}
