/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:00:30 by isainz-r          #+#    #+#             */
/*   Updated: 2024/05/26 11:54:38 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Allocates memory for an array of count elements of size bytes each 
 *        and initializes all bytes to zero.
 *
 * @param count Number of elements to allocate.
 * @param size Size of each element in bytes.
 * @return Pointer to the allocated and zero-initialized memory, or NULL if 
 *         allocation fails or parameters are invalid.
 */
void	*ft_calloc(size_t count, size_t size)
{
	char	*pointer;
	size_t	i;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (0);
	pointer = malloc(count * size);
	if (!pointer)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		pointer[i] = '\0';
		i++;
	}
	return ((void *)pointer);
}

/*
int main(void)
{
  char *ptr;
  ptr = ft_calloc(10, sizeof(char));
  if (ptr == NULL)
    return 1;
  ft_strlcpy(ptr, "Hola", 5);
  printf("%s\n", ptr);
  free(ptr);
  return 0;
}*/
