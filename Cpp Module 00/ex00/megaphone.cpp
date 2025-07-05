/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:34:57 by aychikhi          #+#    #+#             */
/*   Updated: 2025/07/04 16:39:14 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < ac; ++i)
		for (int j = 0; av[i][j] != '\0'; ++j)
			std::cout << (char) std::toupper(av[i][j]);
	std::cout << std::endl;
	return (0);
}
