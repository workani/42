/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklepenk <dklepenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:54:19 by dklepenk          #+#    #+#             */
/*   Updated: 2025/06/04 17:45:51 by dklepenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t i, j, k;
    
    if (needle == NULL || needle[0] == 0)
        return (char*)(haystack);
    i = 0;
    j = 0;
    k = 0;
    while (i < len && needle[i])
    {
        if (haystack[i] == needle[j])
        {
            k = i;
            while (haystack[i] == needle[j])
            {
                if (needle[j + 1] == 0)
                    return (char *)(haystack + k);
                i++;
                j++;
            }
            j = 0;
        }
        i++;
    }
    return (NULL);
}

// int main()
// {
//     printf("result: %s\n", ft_strnstr("My name is Danylo. I'm 42 student", "dasds", 50));
// }