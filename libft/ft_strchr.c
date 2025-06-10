/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklepenk <dklepenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:56:29 by dklepenk          #+#    #+#             */
/*   Updated: 2025/06/04 15:06:36 by dklepenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == c)
            return (char *)(s);
        s++;
    }
    return (NULL);
}

// int main()
// {
//     char *str = "hello";
//     printf("result: %c\n", *ft_strchr(str, 'e'));
// }