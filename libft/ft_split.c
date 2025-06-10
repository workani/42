/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklepenk <dklepenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 18:08:03 by dklepenk          #+#    #+#             */
/*   Updated: 2025/06/10 22:45:02 by dklepenk         ###   ########.fr       */
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
	int s_idx;
	int last_split_idx;
	int strs_idx;
	int words_count;
	char **strs;
	
	s_idx = 0;
	last_split_idx = 0;
	strs_idx = 0;
	words_count = ft_words_count((char*) s, c);
	strs = (char **) malloc(words_count * sizeof(char*));
	while (s[s_idx])
	{
		if (s[s_idx] == c|| s[s_idx + 1] == '\0')
		{
			strs[strs_idx] = malloc((s_idx - last_split_idx) + 1);
			if (last_split_idx == 0)
			{
				ft_cst_strncpy(strs[strs_idx], (char*) s, s_idx);
				last_split_idx = s_idx + 1;                                                               
			}                                                                                                       
			else
			{
				if (s[s_idx + 1] == '\0')
					s_idx++;
				ft_cst_strncpy(strs[strs_idx], (char*) s + last_split_idx, s_idx - last_split_idx);
				last_split_idx = s_idx + 1;
			}
			strs_idx++;
		}
		s_idx++;
	}
	return (strs);
}

// int main()
// {
// 	char **strs;
	
// 	strs = ft_split("hello,world", ',');
// 	printf("%s %s", strs[0], strs[1]);
// }

int main() {
	char **strs;

	// Test 1
	strs = ft_split("hello!", ' ');
	printf("Test 1: Input = \"hello!\", Sep = ' '\nExpected:\nhello!\nGot:\n");
	for (int i = 0; i < 1; i++)
		printf("%s\n", strs[i]);

		// Test 3
	strs = ft_split("hello!zzzzzzzz", 'z');
	printf("Test 3: Input = \"hello!zzzzzzzz\", Sep = 'z'\nExpected:\nhello!\nGot:\n");
	for (int i = 0; i < 1; i++)
		printf("%s\n", strs[i]);

	// Test 4
	strs = ft_split("\11\11\11\11hello!\11\11\11\11", '\11');  // \11 = tab
	printf("Test 4: Input = \"\\11\\11\\11\\11hello!\\11\\11\\11\\11\", Sep = '\\11'\nExpected:\nhello!\nGot:\n");
	for (int i = 0; i < 1; i++)
		printf("%s\n", strs[i]);

	// Test 5
	strs = ft_split("", 'a');
	printf("Test 5: Input = \"\", Sep = 'a'\nExpected:\n(nothing)\nGot:\n");
	// Should be no output

	// Test 6
	strs = ft_split("ggggggggggg", 'g');
	printf("Test 6: Input = \"ggggggggggg\", Sep = 'g'\nExpected:\n(nothing)\nGot:\n");
	// Should be no output

	// Test 7
	strs = ft_split("^^^1^^2a,^^^^3^^^^--h^^^^", '^');
	printf("Test 7: Input = \"^^^1^^2a,^^^^3^^^^--h^^^^\", Sep = '^'\nExpected:\n1\n2a,\n3\n--h\nGot:\n");
	for (int i = 0; i < 4; i++)
		printf("%s\n", strs[i]);

	// Test 8
	strs = ft_split("nonempty", '\0');
	printf("Test 8: Input = \"nonempty\", Sep = '\\0'\nExpected:\nnonempty\nGot:\n");
	for (int i = 0; i < 1; i++)
		printf("%s\n", strs[i]);

	return 0;
}


