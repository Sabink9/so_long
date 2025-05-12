/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saciurus <saciurus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:16:55 by saciurus          #+#    #+#             */
/*   Updated: 2025/01/24 16:23:08 by saciurus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_prints(char *str);
int	ft_printc(char c);
int	ft_printd(int nb);
int	ft_printu(unsigned int nb);
int	ft_printp(void *ptr);
int	ft_printx(unsigned int hexa);
int	ft_printxx(unsigned int Hexa);
int	ft_len_tab(unsigned int n);
int	ft_printf(const char *format, ...);

#endif
