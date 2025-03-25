/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:05:10 by dhuss             #+#    #+#             */
/*   Updated: 2025/03/25 11:38:02 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	std::cout << "\033[34m[----------Constructor Tests----------]\033[37m" << std::endl;
	std::cout << "\033[33m- Default Constructor\033[37m" << std::endl;
	ShrubberyCreationForm b27("home");
	std::cout << b27 << std::endl;
	std::cout << "\033[33m- Copy Constructor\033[37m" << std::endl;
	ShrubberyCreationForm copyB27(b27);
	std::cout << copyB27 << std::endl;
	std::cout << "\033[33m- Assignment operator\033[37m" << std::endl;
	ShrubberyCreationForm assignB27("harald");
	assignB27 = b27;
	std::cout << assignB27 << std::endl;

	std::cout << "\033[34m[----------Sign & Execute Tests----------]\033[37m" << std::endl;
	std::cout << "\033[33m- ShrubberyForm\033[37m" << std::endl;
	std::cout << "\033[35m--> succes\033[37m" << std::endl;
	Bureaucrat mrBusy("mrBusy", 1);
	std::cout << mrBusy << std::endl;
	mrBusy.signForm(b27);
	mrBusy.executeForm(b27);

	std::cout << "\033[35m--> already signed\033[37m" << std::endl;
	mrBusy.signForm(b27);
	std::cout << "\033[35m--> not signed\033[37m" << std::endl;
	ShrubberyCreationForm notSigned("notSigned");
	std::cout << notSigned << std::endl;
	mrBusy.executeForm(notSigned);
	std::cout << "\033[35m--> grade too low for signing\033[37m" << std::endl;
	Bureaucrat mrLazy("mrLazy", 150);
	ShrubberyCreationForm a20("a20");
	std::cout << mrLazy << std::endl;
	mrLazy.signForm(a20);
	std::cout << "\033[35m--> grade too low for execution\033[37m" << std::endl;
	mrBusy.signForm(a20);
	mrLazy.executeForm(a20);

	std::cout << "\033[33m- PresidentialPardonForm\033[37m" << std::endl;
	PresidentialPardonForm presidential("dude");
	std::cout << presidential << std::endl;
	std::cout << "\033[35m--> succes\033[37m" << std::endl;
	mrBusy.signForm(presidential);
	mrBusy.executeForm(presidential);
	std::cout << "\033[35m--> already signed\033[37m" << std::endl;
	mrBusy.signForm(presidential);
	std::cout << "\033[35m--> not signed\033[37m" << std::endl;
	PresidentialPardonForm notSignedPresi("notSigned");
	mrBusy.executeForm(notSignedPresi);
	std::cout << "\033[35m--> grade too low for signing\033[37m" << std::endl;
	PresidentialPardonForm low("low");
	mrLazy.signForm(low);
	std::cout << "\033[35m--> grade too low for execution\033[37m" << std::endl;
	mrBusy.signForm(low);
	mrLazy.executeForm(low);

	std::cout << "\033[33m- RobotomyRequestForm\033[37m" << std::endl;
	RobotomyRequestForm robotomy("dude");
	std::cout << robotomy << std::endl;
	std::cout << "\033[35m--> succes\033[37m" << std::endl;
	mrBusy.signForm(robotomy);
	mrBusy.executeForm(robotomy);
	std::cout << "\033[35m--> already signed\033[37m" << std::endl;
	mrBusy.signForm(robotomy);
	std::cout << "\033[35m--> not signed\033[37m" << std::endl;
	RobotomyRequestForm notSignedRobo("notSigned");
	mrBusy.executeForm(notSignedRobo);
	std::cout << "\033[35m--> grade too low for signing\033[37m" << std::endl;
	RobotomyRequestForm lowRobo("low");
	mrLazy.signForm(lowRobo);
	std::cout << "\033[35m--> grade too low for execution\033[37m" << std::endl;
	mrBusy.signForm(lowRobo);
	mrLazy.executeForm(lowRobo);

}
