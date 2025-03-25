/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:25:34 by dhuss             #+#    #+#             */
/*   Updated: 2025/03/25 16:16:17 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*----------------------*/
/* Constructor			*/
/*----------------------*/
Intern::Intern()
{
}

/*----------------------*/
/* Copy Constructor		*/
/*----------------------*/
Intern::Intern(const Intern& src)
{
}

/*----------------------*/
/* Assignment operator	*/
/*----------------------*/
Intern& Intern::operator=(const Intern& other)
{
	if (this != &other)
		std::cout << "intern has no private attiributes" << std::endl;
	return (*this);
}

/*----------------------*/
/* Destructor			*/
/*----------------------*/
Intern::~Intern()
{
}

//------------public member methods------------//

/*----------------------------------------------*/
/* creates and returns a ShrubberyForm			*/
/*----------------------------------------------*/
AForm* Intern::makeShrub(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

/*----------------------------------------------*/
/* creates and returns a RoboForm				*/
/*----------------------------------------------*/
AForm* Intern::makeRobo(std::string target)
{
	return (new RobotomyRequestForm(target));
}

/*----------------------------------------------*/
/* creates and returns a PresiForm				*/
/*----------------------------------------------*/
AForm* Intern::makePresi(std::string target)
{
	return (new PresidentialPardonForm(target));
}

/*----------------------------------------------*/
/* checks if name matches levels array			*/
/* -> if so calls the function at that index	*/
/* -> else returns error						*/
/*----------------------------------------------*/
AForm* Intern::makeForm(std::string name, std::string target)
{
	AForm*	(Intern::*forms[])(std::string) = { &Intern::makeShrub, &Intern::makeRobo, &Intern::makePresi};
	std::string levels[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm*	form;

	form = NULL;
	for (int i = 0; i < 3; i++)
	{
		if (name == levels[i])
		{
			form = ((this->*forms[i])(target));
			std::cout << "Intern creates - " << *form << std::endl;
			return (form);
		}
	}
	std::cout << name << " is an invalid form name" << std::endl; // segmentation fault
	return (form);
}
