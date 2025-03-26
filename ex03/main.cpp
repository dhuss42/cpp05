/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:05:10 by dhuss             #+#    #+#             */
/*   Updated: 2025/03/25 16:13:51 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::cout << "\033[34m[----------Tests----------]\033[37m" << std::endl;
	std::cout << "\033[33m- MakeFormTests\033[37m" << std::endl;
	std::cout << "\033[35m--> Shrubbery\033[37m" << std::endl;
	Intern	intern;
	AForm*	formShrub;

	formShrub = intern.makeForm("ShrubberyCreationForm", "bob");
	Bureaucrat mrBusy("mrBusy", 1);
	mrBusy.signForm(*formShrub);
	mrBusy.executeForm(*formShrub);

	std::cout << "\033[35m--> Robo\033[37m" << std::endl;
	AForm*	formRobo;
	formRobo = intern.makeForm("RobotomyRequestForm", "bob");
	mrBusy.signForm(*formRobo);
	mrBusy.executeForm(*formRobo);

	std::cout << "\033[35m--> Presi\033[37m" << std::endl;
	AForm*	formPresi;
	formPresi = intern.makeForm("PresidentialPardonForm", "bob");
	mrBusy.signForm(*formPresi);
	mrBusy.executeForm(*formPresi);

	std::cout << "\033[35m--> Error\033[37m" << std::endl;
		AForm*	formError;
		formError = intern.makeForm("a", "bob");
		if (formError)
		{
			mrBusy.signForm(*formError);
			mrBusy.executeForm(*formError);
		}
}
