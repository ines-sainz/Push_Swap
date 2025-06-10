/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:17:29 by isainz-r          #+#    #+#             */
/*   Updated: 2024/01/27 16:50:10 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Outputs the integer n to the given file descriptor.
 *
 * Handles edge case for INT_MIN and writes digits recursively.
 *
 * @param n The integer to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putnbr_fd(int n, int fd)
{
	int	n1;
	int	divn1;
	int	restn1;

	if (n == INT_MIN)
		write(fd, "-2147483648", 11);
	if (n <= INT_MAX && n > INT_MIN)
	{
		n1 = n;
		if (n1 < 0)
		{
			n1 = -n1;
			write(fd, "-", 1);
		}
		divn1 = (n1 / 10);
		if (n1 >= 10)
			ft_putnbr_fd(divn1, fd);
		restn1 = ((n1 % 10) + '0');
		write(fd, &restn1, 1);
	}
}

/*int main(void)
{
	int	string;
	char	*file = "./test";
	int		fd;

	fd = open(file, 1);
	string = 12345;
	ft_putnbr_fd(string, fd);
	close(fd);
}*/
