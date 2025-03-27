/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:03:41 by dhuss             #+#    #+#             */
/*   Updated: 2025/03/27 11:43:11 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*----------------------*/
/* Default Constructor	*/
/*----------------------*/
Bureaucrat::Bureaucrat() : _name("default bureaucrat"), _grade(150)
{
}

/*----------------------*/
/* Constructor			*/
/*----------------------*/
Bureaucrat::Bureaucrat(std::string const name, unsigned int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw (GradeTooHighException());
	else if (grade > 150)
		throw (GradeTooLowException());
}

/*----------------------*/
/* Copy Constructor		*/
/*----------------------*/
Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade)
{
}

/*----------------------*/
/* Assignment Operator	*/
/*----------------------*/
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

/*----------------------*/
/* Destructor			*/
/*----------------------*/
Bureaucrat::~Bureaucrat()
{
}

//------------getters------------//

/*----------------------*/
/* returns name			*/
/*----------------------*/
std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

/*----------------------*/
/* returns grade		*/
/*----------------------*/
unsigned int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

//------------arithmetic operations------------//

/*----------------------*/
/* increment grade		*/
/*----------------------*/
void	Bureaucrat::incrementGrade(void)
{
	if (_grade - 1 < 1)
		throw(GradeTooHighException());
	else
		_grade--;
}

/*----------------------*/
/* decrement grade		*/
/*----------------------*/
void	Bureaucrat::decrementGrade(void)
{
	if (_grade + 1 > 150)
		throw(GradeTooLowException());
	else
		_grade++;
}

//------------exceptions------------//

/*------------------------------------------*/
/* Throws exception if grade too high		*/
/*------------------------------------------*/
const char* Bureaucrat::GradeTooHighException::what() const _NOEXCEPT
{
	return ("grade too high!");
}

/*------------------------------------------*/
/* Throws exception if grade too low		*/
/*------------------------------------------*/

const char* Bureaucrat::GradeTooLowException::what() const _NOEXCEPT
{
	return ("grade too low!");
}

//------------non class methods------------//

/*----------------------*/
/* Insertion Operator	*/
/*----------------------*/
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bc)
{
	os << bc.getName() << " bureaucract, grade " << bc.getGrade();
	return (os);
}
