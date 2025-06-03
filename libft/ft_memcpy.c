/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklepenk <dklepenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:50:23 by dklepenk          #+#    #+#             */
/*   Updated: 2025/06/03 16:54:00 by dklepenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_bzero(void *s, size_t n)
{
    int i;
    unsigned char *str;
    
    i = 0;
    str = (unsigned char) s;
    while(str[i] != '\0')
}