/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:40:08 by dhuss             #+#    #+#             */
/*   Updated: 2025/03/25 11:40:08 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

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

void	PresidentialPardonForm::executeIt(void) const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}