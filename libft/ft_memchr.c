/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklepenk <dklepenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:15:08 by dklepenk          #+#    #+#             */
/*   Updated: 2025/06/04 16:32:25 by dklepenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    size_t i;
    unsigned char *str;
    
    i = 0;
    str = (unsigned char *) s;
    while (i < n)
    {
        if (str[i] == c)
            return (str + i);
        i++;
    }
    return (NULL);
}

// int main()
// {
//     char *str = "hello";
//     char *str = "hello";
//     printf("result: %c\n", *(unsigned char*) ft_memchr(str, 'e', 5));
// }