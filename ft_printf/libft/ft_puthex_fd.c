/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklepenk <dklepenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:33:25 by dklepenk          #+#    #+#             */
/*   Updated: 2025/06/20 14:02:53 by dklepenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_itohex(char dst[], int src)
{
	int				i;
	unsigned int	u_src;
	char			hex[17];

	i = 0;
	u_src = (unsigned int) src;
	ft_strlcpy(hex, "0123456789abcdef", 17);
	while (u_src > 0)
	{
		dst[i] = hex[u_src % 16];
		u_src /= 16;
		i++;
	}
	return (i);
}

int	ft_puthex_fd(int n, int fd, bool is_upper)
{
	int		i;
	int		count;
	char	hex_nbr[8];

	count = 0;
	if (n == 0)
	{
		count += ft_putchar_fd('0', fd);
		return (count);
	}
	i = ft_itohex(hex_nbr, n);
	if (is_upper)
		ft_strtoupper(hex_nbr);
	while (i--)
		count += ft_putchar_fd(hex_nbr[i], fd);
	return (count);
}

//int	main(void)
//{
//	int n = 1223423423;
//	ft_puthex_fd(n, 1, true);
//	ft_putchar_fd('\n', 1);
//	ft_puthex_fd(n, 1, false);
//	//  ft_putchar_fd('\n', 1);
//	//  ft_puthex_fd(1234, 1);
//	//  ft_putchar_fd('\n', 1);
//	//  ft_puthex_fd(-1234, 1);
//	//  ft_puthex_fd(-1234, 1);
//}