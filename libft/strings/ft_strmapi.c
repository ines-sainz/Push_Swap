/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:25:42 by isainz-r          #+#    #+#             */
/*   Updated: 2024/05/26 11:56:44 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Applies a function to each character of a string to create a new one.
 *
 * Allocates and returns a new string resulting from applying the function
 * 'f' to each character of the input string 's', passing its index as the
 * first argument to 'f'.
 *
 * @param s The input string.
 * @param f The function to apply to each character.
 * @return A new string with each character modified by 'f', or NULL on error.
 */
char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	int		len;
	int		i;
	char	*new_string;

	if (s[0] == '\0')
	{
		new_string = malloc(1 * sizeof(char));
		if (!new_string)
			return (0);
		new_string[0] = '\0';
		return (new_string);
	}
	len = ft_strlen(s);
	new_string = malloc(len + 1 * sizeof(char));
	if (!new_string)
		return (0);
	i = 0;
	while (i < len)
	{
		new_string[i] = f(i, s[i]);
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

/*
char    ft_tou(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
int main(void)
{
	printf("%s", ft_strmapi("hola mundo", ft_tou));
}*/
