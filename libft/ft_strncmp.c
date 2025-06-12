/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklepenk <dklepenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:17:30 by dklepenk          #+#    #+#             */
/*   Updated: 2025/06/12 21:40:00 by dklepenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;
    unsigned char *u_s1;
    unsigned char *u_s2;

    i = 0;
    u_s1 = (unsigned char*) s1;
    u_s2 = (unsigned char*) s2;
    while ((u_s1[i] || u_s2[i]) && i < n)
    {
        if (u_s1[i] != u_s2[i])
            return (u_s1[i] - u_s2[i]);
        i++;
    }
    return (0);
}

// int main()
// {
//     printf("result: %d\n", ft_strncmp("hello", "hello", 5));
//     printf("result: %d\n", ft_strncmp("zello", "horld", 5));
//     printf("result: %d\n", ft_strncmp("world", "worldddddddd", 20));
// }