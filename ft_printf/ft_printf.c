/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklepenk <dklepenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:48:41 by dklepenk          #+#    #+#             */
/*   Updated: 2025/06/20 19:53:04 by dklepenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_placeholder(char placeholder, va_list *args)
{
	int	count;

	count = 0;
	if (placeholder == 'c')
		count += ft_putchar_fd(va_arg(*args, int), 1);
	if (placeholder == 's')
		count += putstr(va_arg(*args, char *));
	if (placeholder == 'p')
		count += putptr(va_arg(*args, void *));
	if (placeholder == 'd' || placeholder == 'i')
		count += ft_putnbr_fd(va_arg(*args, int), 1);
	if (placeholder == 'u')
		count += putuint(va_arg(*args, unsigned int));
	if (placeholder == 'x')
		count += puthex((unsigned int)va_arg(*args, int), false);
	if (placeholder == 'X')
		count += puthex((unsigned int)va_arg(*args, int), true);
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
			count += print_placeholder(str[i + 1], &args);
			i++;
		}
		else
			count += ft_putchar_fd(str[i], 1);
		i++;
	}
	return (count);
}

// int	main(void)
//{
//	int count1, count2;
//	int n = INT32_MIN;
//	// case 1 --- Hex ---
//	count1 = ft_printf(" %x \n", n);
//	count2 = printf(" %x \n", n);
//	count1 = ft_printf(" %X \n", n);
//	count2 = printf(" %X \n", n);
//	printf("[ft_printf: %d | printf: %d]\n", count1, count2);

////	// case 2 --- Valid pointer --
////	count1 = ft_printf("Ptr: %p.\n", &count1);
////	count2 = printf("Ptr: %p.\n", &count1);
////	printf("[ft_printf: %d | printf: %d]\n", count1, count2);

////	// case 3 -- Null pointer
////	//count1 = ft_printf("Ptr: %p.\n", NULL);
////	//count2 = printf("Ptr: %p.\n", NULL);
////	//printf("[ft_printf: %d | printf: %d]\n", count1, count2);

////	// case 2 --- Null str ---
////	// count1 = ft_printf("%s\n", NULL);
////	// count2 = printf("%s\n", NULL);
////	// printf("ft_printf: %d\nprintf: %d\n", count1, count2);
//}