/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:28:27 by isainz-r          #+#    #+#             */
/*   Updated: 2024/01/15 09:55:34 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Fills the first len bytes of the memory area pointed to by b with c.
 *
 * @param b Pointer to the memory area to fill.
 * @param c The byte value to set.
 * @param len Number of bytes to be set to the value.
 * @return A pointer to the memory area b.
 */
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)b)[i] = c;
		i++;
	}
	return (b);
}

/*int	main(void)
{
	char	ptr[5];

	printf("El resultado del memset es: %s\n", memset(ptr, 'r', (0)));
	printf("MI ft_memset me da: %s\n", ft_memset(ptr, 'r', 0));
}*/
