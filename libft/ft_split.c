/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklepenk <dklepenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 18:08:03 by dklepenk          #+#    #+#             */
/*   Updated: 2025/06/11 23:38:39 by dklepenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

int ft_words_count(char *str, char delimiter)
{
	int i;
	int words_count;

	i = 0;
	words_count = 0;    
	while (str[i])
	{  
		if ((str[i] != delimiter && str[i + 1] == delimiter) || (str[i] != delimiter && str[i + 1] == '\0'))
			words_count++;
		i++;
	}
	// if (words_count == 0)
	// 	return (1);
	return (words_count);
}

char *ft_cst_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char *ft_allocate_empty_str()
{
	char *str = malloc(sizeof(char));
	str[0] = '\0';
	return (str);
}

char **ft_split(char const *s, char c)
{
	int i;
	int last_word_idx;
	int strs_idx;
	char **strs;

	i = 0;
	strs_idx = 0;
	
	strs = (char **) malloc(ft_words_count((char *) s, c) * sizeof(char *) + 1);
	while (s[i])
	{
		if (s[i] != c && s[i] != '\0')
		{
			last_word_idx = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			strs[strs_idx] = malloc((i - last_word_idx + 1) * sizeof(char));
			ft_cst_strncpy(strs[strs_idx], (char*) s + last_word_idx, i - last_word_idx);
			strs_idx++;
		}
		i++;
	}
	strs[strs_idx] = NULL;
	return (strs);
}


int main() {
	char **strs;
	strs = ft_split("hello!", ' ');
	
	for (int i = 0; i < 2; i++)
		printf("%p\n", strs[i]);

	return 0;
}


