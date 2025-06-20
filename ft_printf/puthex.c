/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklepenk <dklepenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:33:25 by dklepenk          #+#    #+#             */
/*   Updated: 2025/06/20 19:36:27 by dklepenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	itohex(char dst[], uintptr_t u_src)
{
	int				i;
	char			hex[17];

	i = 0;
	ft_strlcpy(hex, "0123456789abcdef", 17);
	while (u_src > 0)
	{
		dst[i] = hex[u_src % 16];
		u_src /= 16;
		i++;
	}
	return (i);
}

int	puthex(uintptr_t n, bool is_upper)
{
	int		i;
	int		count;
	char	hex_nbr[32]; // 32 is max length of printf's %p output

	count = 0;
	if (n == 0)
		return (ft_putchar_fd('0', 1));
	i = itohex(hex_nbr, n);
	if (is_upper)
		ft_strtoupper(hex_nbr);
	while (i--)
		count += ft_putchar_fd(hex_nbr[i], 1);
	return (count);
}
