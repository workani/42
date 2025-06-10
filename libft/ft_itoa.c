/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklepenk <dklepenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:12:50 by dklepenk          #+#    #+#             */
/*   Updated: 2025/06/10 20:54:23 by dklepenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int ft_get_int_len(int n)
{
    int i;

    i = 0;
    if (n == 0)
        i++;
    while (n)
    {
        n /= 10;
        i++;
    }
    return (i);
}

/* Append each digit of the n in reverse order to the result str*/
void ft_digits_to_str(char *dest, int n, int i)
{
    dest[i + 1] = '\0'; 
    while (i--)
    {
        if (dest[i] == '-')
            break; 
        dest[i] = (n % 10) + '0';
        n /= 10; 
    }
}

char *ft_itoa(int n)
{
    int i;
    char *result;
  
    i = 0;
    result = (char *)malloc(12);
    if (result == NULL)
        return (NULL);
    if (n == -2147483648)
    {
        ft_strlcpy(result, "-2147483648", 12);
        return (result);
    }
    if (n < 0)
    {
        result[i] = '-';
        n = -n;
        i++;
    }
    i += ft_get_int_len(n);
    ft_digits_to_str(result, n, i);
    return (result);
}
// int main()
// {
//     printf("res: %s\n", ft_itoa(1234423434));
//     printf("res: %s\n", ft_itoa(-1234));
//     printf("res: %s\n", ft_itoa(0));
//     printf("res: %s\n", ft_itoa(-2147483648));
// }