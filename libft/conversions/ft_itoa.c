/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:02:31 by isainz-r          #+#    #+#             */
/*   Updated: 2024/05/26 11:56:08 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Checks if an integer is negative.
 *
 * @param n The integer to check.
 * @return 0 if n is negative, 1 otherwise.
 */
int	ft_negative(int n)
{
	if (n < 0)
		return (0);
	return (1);
}

/**
 * @brief Counts the number of characters needed to represent an integer as a
 *        string, including space for sign and null terminator.
 *
 * @param n The integer to count digits for.
 * @return The number of characters required for the string representation.
 */
int	ft_count_numbers(int n)
{
	int	contador;

	contador = 0;
	if (n == INT_MIN)
		return (12);
	if (n <= INT_MAX && n > INT_MIN)
	{
		if (n < 0)
		{
			contador++;
			n = -n;
		}
		while (n >= 10)
		{
			n = n / 10;
			contador++;
		}
		contador++;
	}
	return (contador + 1);
}

/**
 * @brief Converts an integer to a null-terminated string.
 *
 * Allocates memory for the string representation, including sign if negative.
 *
 * @param n The integer to convert.
 * @return Pointer to the newly allocated string, or NULL if allocation fails.
 */
char	*ft_itoa(int n)
{
	char	*number;
	int		n_number;
	long	nb;

	nb = (long)n;
	n_number = ft_count_numbers(nb);
	number = ft_calloc(n_number, sizeof(char));
	if (!number)
		return (NULL);
	if (ft_negative(nb) == 0)
	{
		number[0] = '-';
		nb = -nb;
	}
	while (nb >= 10)
	{
		number[n_number - 2] = ((nb % 10) + '0');
		nb = (nb / 10);
		n_number--;
	}
	number[n_number - 2] = ((nb % 10) + '0');
	return (number);
}

/*int	main(void)
{
	printf("%s", ft_itoa(-123456));
}*/
