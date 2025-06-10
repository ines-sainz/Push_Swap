/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:59:17 by isainz-r          #+#    #+#             */
/*   Updated: 2024/06/27 12:34:19 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

/**
 * @brief Converts a numeric string to an integer with overflow check.
 *
 * Handles optional '+' or '-' sign, parses digits, and checks for overflow
 * against INT_MAX and INT_MIN.
 *
 * @param temp The input string to convert.
 * @return int The converted integer, or 1 on overflow.
 */
int	ft_char_to_int(char *temp)
{
	long	nb;
	int		i;
	int		s;

	nb = 0;
	i = 0;
	s = 0;
	if (temp[i] == '+')
		i++;
	if (temp[i] == '-')
	{
		s++;
		i++;
	}
	while (temp[i] >= '0' && temp[i] <= '9')
	{
		nb = nb * 10 + (temp[i] - '0');
		i++;
	}
	if (s % 2 == 1)
		nb = -nb;
	if (nb > INT_MAX || nb < INT_MIN)
		return (1);
	return (nb);
}

/**
 * @brief Converts a string to an integer and stores it in the stack.
 *
 * Validates the string format and its numeric length. Uses ft_char_to_int
 * to convert and stores the number in the list with ft_create_stack.
 *
 * @param temp  The numeric string.
 * @param list  The list to store the number in.
 * @param i     Unused index parameter (typically 0).
 * @param count Unused count parameter (typically 0).
 * @return int  0 on success, 1 on error.
 */
int	ft_int_to_stack(char *temp, t_list *list, size_t i, size_t count)
{
	int		num;

	i = 0;
	count = 0;
	if (!temp)
		return (1);
	if (!temp[0])
		return (0);
	while ((temp[i] == '0' || temp[i] == '+' || temp[i] == '-')
		&& temp[i + 1] != '\0')
		i++;
	while (temp[i])
	{
		i++;
		count++;
	}
	if (count > 11)
		return (free(temp), 1);
	num = ft_char_to_int(temp);
	if (num == 1 && (temp[i - count] != '1'
			|| (temp[i - count] == '1' && temp[i - count + 1] != '\0')))
		return (free(temp), 1);
	if (ft_create_stack(num, list) == 1)
		return (free(temp), 1);
	return (0);
}

/**
 * @brief Appends a character to a dynamic string, validating sign placement.
 *
 * Validates sign position and reallocates a new string with the character
 * appended.
 *
 * @param temp     The original string to append to.
 * @param c        The character to append.
 * @param next_c   The character that follows `c` in the source string.
 * @return char*   The new string with `c` appended, or NULL on error.
 */
char	*ft_add_char(char *temp, char c, char next_c)
{
	int		len_temp;
	char	*number;
	int		i;

	i = 0;
	if (((c == '+' || c == '-') && ft_isdigit(next_c) == 0)
		|| (ft_isdigit(c) == 1 && (next_c == '+' || next_c == '-')))
		return (free(temp), NULL);
	len_temp = ft_strlen(temp);
	number = ft_calloc(len_temp + 2, 1);
	if (!number)
		return (free(temp), NULL);
	while (temp && temp[i] != '\0')
	{
		number[i] = temp[i];
		i++;
	}
	number[len_temp] = c;
	free(temp);
	return (number);
}

/**
 * @brief Parses integers from a string and adds them to the stack.
 *
 * Splits the input string by whitespace, builds valid integer strings,
 * and stores them using ft_int_to_stack.
 *
 * @param str   The input string to parse.
 * @param list  The list to store integers into.
 * @return int  0 on success, 1 on failure.
 */
int	ft_return_int(char *str, t_list *list)
{
	int		i;
	char	*temp;

	i = 0;
	while (str[i])
	{
		temp = ft_strdup("");
		if (ft_isdigit(str[i]) == 0 && str[i] != '+' && str[i] != '-'
			&& str[i] != ' ' && !(str[i] >= 9 && str[i] <= 13))
			return (free(temp), 1);
		while (str[i] == ' ' || (str[i] >= 13 && str[i] <= 9))
			i++;
		while (ft_isdigit(str[i]) == 1 || (str[i] == '+' || str[i] == '-'))
		{
			temp = ft_add_char(temp, str[i], str[i + 1]);
			if (temp == NULL)
				return (free(temp), 1);
			i++;
		}
		if (ft_int_to_stack(temp, list, 0, 0) == 1 && !str[i])
			return (1);
		free(temp);
	}
	return (0);
}

/**
 * @brief Parses all arguments and populates the stack with valid integers.
 *
 * Iterates over argv starting from index 1, passing each to ft_return_int
 * for processing. Frees list on error.
 *
 * @param argc  Argument count.
 * @param argv  Argument vector.
 * @param list  The list to populate.
 * @return int  0 on success, 1 on failure.
 */
int	ft_parse_and_stack(int argc, char **argv, t_list *list)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		while (!argv[i][0])
		{
			if (i == argc - 1)
				return (0);
			i++;
		}
		if (ft_return_int(argv[i], list) == 1)
		{
			if (list->first_node_a != NULL)
				ft_lstclear(list);
			return (1);
		}
		i++;
	}
	return (0);
}
