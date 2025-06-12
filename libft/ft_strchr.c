/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklepenk <dklepenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:56:29 by dklepenk          #+#    #+#             */
/*   Updated: 2025/06/12 21:29:26 by dklepenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    int i;
    
    i = 0;
    c = c % 128; // prevent overflow
    while (s[i])
    {
        if (s[i] == c)
            return (char *)(s + i);
        i++;
    }
    if (c == '\0')
        return (char *) (s + i);
    return (NULL);
}

// int main()
// {
//     char *str = "hello";
//     printf("result: %c\n", *ft_strchr(str, 'e'));
// }