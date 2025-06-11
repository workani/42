/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklepenk <dklepenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 18:08:03 by dklepenk          #+#    #+#             */
/*   Updated: 2025/06/11 19:46:51 by dklepenk         ###   ########.fr       */
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

char **ft_split(char const *s, char c)
{
	int i;
	int last_word_idx;
	int strs_idx;
	char **strs;

	i = 0;
	strs_idx = 0;
	strs = (char **) malloc(ft_words_count((char*) s, c) * sizeof(char*));
	while (s[i])
	{
		if (s[i] != c && s[i] != '\0')
		{
			last_word_idx = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			strs[strs_idx] = malloc((i - last_word_idx) + 1);
			ft_cst_strncpy(strs[strs_idx], (char*) s + last_word_idx, i - last_word_idx);
			strs_idx++;
		}
		i++;
	}
	return (strs);
}


int main() {
	char **strs;

	// Test 1
	// strs = ft_split("hello, world, this is workani", ',');
	// for (int i = 0; i < 3; i++)
	// 	printf("%s\n", strs[i]);
	

	// 	// Test 3
	// strs = ft_split("bye,world", ',');
	// printf("Test 3: Input = \"hello!zzzzzzzz\", Sep = 'z'\nExpected:\nhello!\nGot:\n");
	// for (int i = 0; i < 2; i++)
	// 	printf("%s\n", strs[i]);

	// Test 4
	// strs = ft_split("\11\11\11\11hello!\11\11\11\11", '\11');  // \11 = tab
	// printf("Test 4: Input = \"\\11\\11\\11\\11hello!\\11\\11\\11\\11\", Sep = '\\11'\nExpected:\nhello!\nGot:\n");
	// for (int i = 0; i < 1; i++)
	// 	printf("%s\n", strs[i]);

// 	// Test 5
// 	strs = ft_split("", 'a');
// 	printf("Test 5: Input = \"\", Sep = 'a'\nExpected:\n(nothing)\nGot:\n");
// 	// Should be no output

// 	// Test 6
// 	strs = ft_split("ggggggggggg", 'g');
// 	printf("Test 6: Input = \"ggggggggggg\", Sep = 'g'\nExpected:\n(nothing)\nGot:\n");
// 	// Should be no output

// 	// Test 7
	// strs = ft_split("^^^1^^2a,^^^^3^^^^--h^^^^", '^');
	// printf("Test 7: Input = \"^^^1^^2a,^^^^3^^^^--h^^^^\", Sep = '^'\nExpected:\n1\n2a,\n 3\n--h\nGot:\n");
// 	for (int i = 0; i < 4; i++)
// 		printf("%s\n", strs[i]);

	// Test 8
	// strs = ft_split("nonempty", '\0');
	// printf("Test 8: Input = \"nonempty\0\", Sep = '\\0'\nExpected:\nnonempty\nGot:\n");
	// for (int i = 0; i < 1; i++)
	// 	printf("%s\n", strs[i]);

	return 0;
}


