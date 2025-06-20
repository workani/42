/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklepenk <dklepenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:45:03 by dklepenk          #+#    #+#             */
/*   Updated: 2025/06/20 19:05:05 by dklepenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdint.h>
# include <stdarg.h>

int	putuint(unsigned long n);
int	puthex(uintptr_t n, bool is_upper);
int	putptr(void *ptr);
int	putstr(char *str);
int	ft_printf(const char *str, ...);

#endif 