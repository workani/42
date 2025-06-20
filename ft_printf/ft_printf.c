/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklepenk <dklepenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:48:41 by dklepenk          #+#    #+#             */
/*   Updated: 2025/06/20 14:03:08 by dklepenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdint.h>
#include <stdarg.h>

int	ft_cst_putstr(char *str)
{
	if (!str)
		return (ft_putstr_fd("(null)", 1));
	return (ft_putstr_fd(str, 1));
}

int ft_putptr(void *ptr)
{
	int count;
	
	if (!ptr)
		return (ft_putstr_fd("(nil)", 1));
	uintptr_t number = (uintptr_t)ptr;
	count = ft_putstr_fd("0x", 1);
	count += ft_puthex_fd(number, 1, false);
	return (count);
}

int	ft_print_placeholder(char placeholder, va_list *args)
{
	int	count;

	count = 0;
	if (placeholder == 'c')
		count += ft_putchar_fd(placeholder, 1);
	if (placeholder == 's')
		count += ft_cst_putstr(va_arg(*args, char *));
	//if (placeholder == 'p')
	//	count += ft_putptr(va_arg(*args, void *));
	if (placeholder == 'd' || placeholder == 'i')
		count += ft_putnbr_fd(va_arg(*args, int), 1);
	if (placeholder == 'u')
		count += ft_putnbr_fd(va_arg(*args, unsigned int), 1);
	if (placeholder == 'x')
		count += ft_puthex_fd(va_arg(*args, int), 1, false);
	if (placeholder == 'X')
		count += ft_puthex_fd(va_arg(*args, int), 1, true);
	if (placeholder == '%')
		count += ft_putchar_fd(placeholder, 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_print_placeholder(str[i + 1], &args);
			i++;
		}
		else
			count += ft_putchar_fd(str[i], 1);
		i++;
	}
	return (count);
}

int	main(void)
{
	int count1, count2;
	// case 1 --- Proper input of multiple types ---
	count1 = ft_printf("hello from %d. I'm %s.100 %% good vibes. Hex: %x.\n", 42,
			"dklepenk", -1232132132);
	count2 = printf("hello from %d. I'm %s.100 %% good vibes. Hex: %x.\n", 42,
			"dklepenk", -1232132132);
	printf("[ft_printf: %d | printf: %d]\n", count1, count2);
	
	// case 2 -- Valid pointer
	count1 = ft_printf("Ptr: %p.\n", &count1);
	count2 = printf("Ptr: %p.\n", &count2);
	printf("[ft_printf: %d | printf: %d]\n", count1, count2);

	// case 3 -- Null pointer
	//count1 = ft_printf("Ptr: %p.\n", NULL);
	//count2 = printf("Ptr: %p.\n", NULL);
	//printf("[ft_printf: %d | printf: %d]\n", count1, count2);
	
	// case 2 --- Null str ---
	// count1 = ft_printf("%s\n", NULL);
	// count2 = printf("%s\n", NULL);
	// printf("ft_printf: %d\nprintf: %d\n", count1, count2);
}