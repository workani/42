/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklepenk <dklepenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:08:05 by dklepenk          #+#    #+#             */
/*   Updated: 2025/06/04 15:14:26 by dklepenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    char *occurrence;
    
    occurrence = NULL;
    while (*s)
    {
        if (*s == c)
            occurrence = (char *)s;
        s++;
    }
    return (occurrence);
}

// int main()
// {
//     char *str = "hello";
//     printf("result: %c\n", *ft_strchr(str, 'e'));
// }