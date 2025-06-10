/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:07:59 by isainz-r          #+#    #+#             */
/*   Updated: 2024/05/26 11:55:36 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Concatenates two strings into a new allocated string.
 *
 * Allocates and returns a new string consisting of 's1' followed by 's2'.
 * Returns NULL if the allocation fails.
 *
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return A new string containing the concatenation of s1 and s2,
 *         or NULL on failure.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*resultado;
	size_t	i;
	size_t	j;
	size_t	len_s1;
	size_t	len_s2;

	i = 0;
	j = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	resultado = ft_calloc(len_s1 + len_s2 + 1, 1);
	if (!resultado)
		return (NULL);
	while (i < len_s1 && s1[0] != '\0')
		resultado[j++] = s1[i++];
	i = 0;
	while (i < len_s2 && s2[0] != '\0')
		resultado[j++] = s2[i++];
	return (resultado);
}
/*
int   main(void)
{
    printf("%s\n", ft_strjoin("", ""));
}*/
