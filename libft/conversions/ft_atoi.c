/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:49:17 by isainz-r          #+#    #+#             */
/*   Updated: 2024/01/15 10:06:06 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Converts a string to an integer.
 *
 * Parses the input string, skipping any leading whitespace characters.
 * Handles an optional '+' or '-' sign to determine the sign of the result.
 * Converts digit characters into an integer value until a non-digit is found.
 *
 * @param str The null-terminated string to convert.
 * @return The converted integer value.
 */
int	ft_atoi(const char *str)
{
	int	number;
	int	i;
	int	sign;

	number = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number * sign);
}

/*int	main(void)
{
	char    s1[20] = "	-+----123 45";
	printf("%i\n", atoi(s1));
	printf("%i\n", ft_atoi(s1));
	return (0);
}*/
