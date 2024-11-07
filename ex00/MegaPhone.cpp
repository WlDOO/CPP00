/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:19:03 by najeuneh          #+#    #+#             */
/*   Updated: 2024/10/30 17:11:33 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>



int	main(int ac, char **av)
{
	int i = 1;
	int	j;

	if (ac > 1)
	{
		while (av[i])
		{
			j = -1;
			while (av[i][++j])
				av[i][j] = toupper(av[i][j]);
			i++;
		}
		i = 0;
		while (av[++i])
			std::cout << av[i];
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	return 0;
}