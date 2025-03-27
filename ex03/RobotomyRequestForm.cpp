/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:17:47 by dhuss             #+#    #+#             */
/*   Updated: 2025/03/27 11:53:17 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*----------------------*/
/* Default Constructor	*/
/*----------------------*/
RobotomyRequestForm::RobotomyRequestForm() : AForm("default RobotomyRequestForm", 72, 45), _target("default target")
{
}

/*----------------------*/
/* Constructor			*/
/*----------------------*/
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

/*----------------------*/
/* Copy Constructor		*/
/*----------------------*/
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src)
{
}

/*----------------------*/
/* Assignment operator	*/
/*----------------------*/
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

/*----------------------*/
/* Destructor			*/
/*----------------------*/
RobotomyRequestForm::~RobotomyRequestForm()
{
}


//------------public methods-----------//

/*----------------------*/
/* overriden executeIt	*/
/*----------------------*/
void	RobotomyRequestForm::executeIt(void) const
{
	srand(time(0));
	int num = rand() % 2;

	std::cout << "*makes some drilling noises*";
	if (num % 2 == 0)
		std::cout << _target << " has been robotomized sucessfully" << std::endl;
	else
		std::cout << " robotomy failed" << std::endl;
}
