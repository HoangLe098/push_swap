/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:32:46 by hoale             #+#    #+#             */
/*   Updated: 2024/11/08 15:51:06 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*cdest;
	unsigned char	*csrc;

	if (dest == NULL && src == NULL)
		return (NULL);
	cdest = (unsigned char *)dest;
	csrc = (unsigned char *)src;
	if (cdest > csrc)
	{
		i = n;
		while (i-- > 0)
			cdest[i] = csrc[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			cdest[i] = csrc[i];
			i++ ;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
int main() 
{ 
	char csrc[100] = "Example"; 
	ft_memmove(csrc+4, csrc, strlen(csrc)+1); 
	printf("%s", csrc); 
	return 0; 
}
*/
/*
#include <stdio.h>
#include <string.h>
int main()
{
	int src[5] = {12, 1, 54, -2, 0};

	ft_memmove(src+2, src, 2*sizeof(src[0]));
	for (int i=0; i<5; i++)
		printf("%d ", src[i]);
	printf("\n");
	memmove(src+2, src, 2*sizeof(src[0]));
	for (int i=0; i<5; i++)
		printf("%d ", src[i]);
    return 0;
}
*/