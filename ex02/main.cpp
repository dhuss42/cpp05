/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:05:10 by dhuss             #+#    #+#             */
/*   Updated: 2025/03/24 16:05:10 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

void	error(const std::exception& e)
{
	std::cout << "error: " << e.what() << std::endl;
}

int	main(void)
{
	std::cout << "\033[34m[----------Constructor Tests----------]\033[37m" << std::endl;
	std::cout << "\033[33m- Default Constructor\033[37m" << std::endl;
	ShrubberyCreationForm b27("hans");
	std::cout << b27 << std::endl;
	std::cout << "\033[33m- Copy Constructor\033[37m" << std::endl;
	ShrubberyCreationForm copyB27(b27);
	std::cout << copyB27 << std::endl;
	std::cout << "\033[33m- Assignment operator\033[37m" << std::endl;
	ShrubberyCreationForm assignB27("harald");
	assignB27 = b27;
	std::cout << assignB27 << std::endl;

	std::cout << "\033[34m[----------Sign Tests----------]\033[37m" << std::endl;
	std::cout << "\033[33m- ShrubberyForm\033[37m" << std::endl;
	Bureaucrat mrBusy("mrBusy", 1);
	mrBusy.signForm(b27);
	mrBusy.executeForm(b27);
}
