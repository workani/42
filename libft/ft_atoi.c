/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklepenk <dklepenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:46:35 by dklepenk          #+#    #+#             */
/*   Updated: 2025/06/04 18:41:23 by dklepenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi(const char *nptr)
{
    int i;
    int sign;
    int result;

    i = 0;
    sign = 1;
    result = 0;
    while (nptr[i] == ' ' || nptr[i] == '\t')
        i++;
    if (nptr[i] == '+' || nptr[i] == '-')
    {
        if (nptr[i] == '-')
            sign = (sign * -1);
        i++;
    }
    while ((nptr[i] >= '0' && nptr[i] <= '9') && nptr[i])
    {
        result = (result * 10) + (nptr[i] - '0');
        i++;
    }
    return (result * sign);
}

// int main()
// {
//     printf("res: %d\n", ft_atoi("        84343"));
//     printf("res: %d\n", ft_atoi("        -84343"));
//     printf("res: %d\n", ft_atoi("        +84343"));
//     printf("res: %d\n", ft_atoi("---84343"));
// }