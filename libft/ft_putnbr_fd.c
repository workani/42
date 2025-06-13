/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklepenk <dklepenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:33:25 by dklepenk          #+#    #+#             */
/*   Updated: 2025/06/13 16:01:13 by dklepenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_itostr(char dst[], int src)
{
	int	i;

	i = 0;
	while (true)
	{
		dst[i] = src % 10 + '0';
		src /= 10;
		i++;
		if (src == 0)
			break ;
	}
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	nbr[10];

	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	i = ft_itostr(nbr, n);
	while (i--)
		ft_putchar_fd(nbr[i], fd);
}

// int main()
// {
//     // ft_putnbr_fd(2147483647, 1);
//     // ft_putchar_fd('\n', 1);
//     // ft_putnbr_fd(1234, 1);
//     // ft_putchar_fd('\n', 1);
//     // ft_putnbr_fd(-1234, 1);
//     // ft_putnbr_fd(-1234, 1);
// }