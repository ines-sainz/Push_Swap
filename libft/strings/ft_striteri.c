/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:16:36 by isainz-r          #+#    #+#             */
/*   Updated: 2024/01/26 14:29:50 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Applies a function to each character of a string with its index.
 *
 * Iterates over the string 's', applying the function 'f' to each character,  
 * passing its index and a pointer to the character.
 *
 * @param s The string to iterate over.
 * @param f The function to apply to each character and its index.
 */
void	ft_striteri(char *s, void (*f) (unsigned int, char*))
{
	unsigned int		i;

	i = -1;
	while (s[++i] != '\0')
	{
		f(i, &s[i]);
	}
}

/*
void    ft_tou(unsigned int i, char *c)
{
	c[i] = c[i] -32;
}
int main(void)
{
	char s[20] = "hola_Mundo";
	ft_striteri(s, ft_tou);
	printf("%s", s);
}*/
