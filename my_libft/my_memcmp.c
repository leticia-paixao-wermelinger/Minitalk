/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:16:35 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/02/17 00:16:38 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	my_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	count;
	unsigned int	cmp;
	unsigned char	*str1;
	unsigned char	*str2;

	count = 0;
	cmp = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (count <= (n - 1))
	{
		cmp = str1[count] - str2[count];
		if (str1[count] != str2[count])
			return (cmp);
		count++;
	}
	return (cmp);
}
/*
int	main()
{
	#include <stdio.h>

	int	arr1[] = {25, 50, 999999999, 100};
	int	arr2[] = {25, 50, 75, 100};
	unsigned int	number = 9;

	printf("Retorno da minha my_memcmp(): %i\n", my_memcmp(arr1, arr2, number));
	printf("Retorno da memcmp() original: %i\n", memcmp(arr1, arr2, number));
	printf("\n\n Retorno da minha my_memcmp(): %i\n", my_memcmp("t\200", "t\0", 2));
	printf("Retorno da memcmp() original: %i\n", memcmp("t\200", "t\0", 2));
}*/
