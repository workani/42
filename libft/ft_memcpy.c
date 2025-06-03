/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklepenk <dklepenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:50:23 by dklepenk          #+#    #+#             */
/*   Updated: 2025/06/03 20:23:46 by dklepenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void *ft_memcpy(void *dst, const void *src, size_t n)
{
    unsigned char *dest = (unsigned char*) dst;
    unsigned char *source = (unsigned char*) src;
    
    while (n--)
        *dest++ = *source++;
    return (dst);
}


int main()
{
    int n = 6;
    int dst[n];
    int src[] = {6, 2, 5, 5, 3, 1};
    
    ft_memcpy(dst, src, 24);

    for(int i = 0; i < n; i++)
        printf("arr[%d]: %d\n",i + 1, dst[i]);
}