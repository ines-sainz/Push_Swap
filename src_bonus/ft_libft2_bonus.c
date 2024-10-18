/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:38:32 by isainz-r          #+#    #+#             */
/*   Updated: 2024/05/01 11:15:53 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

size_t	ft_strlen2(const char *s)
{
	size_t	i;

	i = 0;
	if (!s || !s[0])
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin2(char const *s1, char const s2)
{
	char	*resultado;
	size_t	i;
	size_t	j;
	size_t	len_s1;

	i = 0;
	j = 0;
	len_s1 = ft_strlen2(s1);
	resultado = ft_calloc(len_s1 + 1 + 1, 1);
	if (!resultado)
		return (NULL);
	while (i < len_s1 && s1[0] != '\0')
		resultado[j++] = s1[i++];
	i = 0;
	if (s2)
		resultado[j++] = s2;
	return (resultado);
}
