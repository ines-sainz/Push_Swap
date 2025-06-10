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

#include "ft_push_swap.h"

/**
 * @brief Converts a numeric string to an integer with validation.
 *
 * Handles optional '+' or '-' sign and checks for overflow or underflow.
 *
 * @param temp The string to convert.
 * @return The converted integer, or 1 on overflow/invalid format.
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
 * @brief Converts a string to int and pushes it to the stack.
 *
 * Validates the input format and its length before converting and adding
 * to the list stack.
 *
 * @param temp The numeric string to convert and push.
 * @param list Pointer to the list structure.
 * @param i Unused index parameter (set to 0).
 * @param count Unused count parameter (set to 0).
 * @return 0 on success, 1 on error.
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
 * @brief Appends a character to a temporary string with validation.
 *
 * Validates character sequence and appends `c` to `temp`. If invalid, frees
 * and returns NULL.
 *
 * @param temp Current number string.
 * @param c Current character to append.
 * @param next_c The next character in the sequence.
 * @return New string with the character appended, or NULL on error.
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
 * @brief Parses a space-separated string and adds valid ints to the stack.
 *
 * Skips whitespaces, validates characters, and builds integer strings to
 * convert and store in the stack.
 *
 * @param str Input string to parse.
 * @param list Pointer to the list structure.
 * @return 0 on success, 1 on error.
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
 * @brief Parses command-line arguments and builds the initial stack.
 *
 * Iterates over argv, skips empty strings, and calls ft_return_int()
 * to validate and store each argument.
 *
 * @param argc Argument count.
 * @param argv Argument values.
 * @param list Pointer to the list structure.
 * @return 0 on success, 1 on error.
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
