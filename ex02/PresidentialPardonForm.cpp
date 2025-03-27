/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:40:08 by dhuss             #+#    #+#             */
/*   Updated: 2025/03/27 11:50:04 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*----------------------*/
/* Default Constructor	*/
/*----------------------*/
PresidentialPardonForm::PresidentialPardonForm() : AForm("default PresidentialPardonForm", 25, 5), _target("default target")
{
}

/*----------------------*/
/* Constructor			*/
/*----------------------*/
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

/*----------------------*/
/* Copy Constructor		*/
/*----------------------*/
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src)
{
}

/*----------------------*/
/* Assignment operator	*/
/*----------------------*/
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

/*----------------------*/
/* Destructor			*/
/*----------------------*/
PresidentialPardonForm::~PresidentialPardonForm()
{
}

//------------public methods-----------//

/*----------------------*/
/* overriden executeIt	*/
/*----------------------*/
void	PresidentialPardonForm::executeIt(void) const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}