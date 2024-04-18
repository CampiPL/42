/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:50:25 by jdepka            #+#    #+#             */
/*   Updated: 2024/02/29 10:50:27 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*ptr;

	if (nmemb > 0 && size > 0)
		if (nmemb > (((size_t) - 1) / size))
			return (NULL);
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (ptr != NULL)
		ft_memset(ptr, 0, total_size);
	return (ptr);
}
/*
int main() {
    size_t num = 5;
    size_t size = sizeof(int);
    int *arr = (int *)ft_calloc(num, size);
    if (arr != NULL) {
        for (size_t i = 0; i < num; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        free(arr);
    } else {
        printf("Nie udało się zaalokować pamięci\n");
    }
    return 0;
}
*/
