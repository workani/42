/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklepenk <dklepenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:58:21 by dklepenk          #+#    #+#             */
/*   Updated: 2025/06/05 14:43:46 by dklepenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t i;
    char *result;
    
    i = 0;
    result = malloc(len);
    if (result == NULL || s == NULL)
        return (NULL);
    while (i <= len && s[start]) // include '\0'
    {
        result[i] = s[start];
        i++;
        start++;
    }
    return (result);
}

// int main()
// {
//     printf("res: %s", ft_substr("hello, my name is Danylo", 18, 6));
// }