/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:04:38 by dhuss             #+#    #+#             */
/*   Updated: 2025/03/25 15:17:18 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

//------------public member methods------------//

/*--------------------------------------------------*/
/* checks if form is signed							*/
/* tries to sign and prints appropriate messages	*/
/*--------------------------------------------------*/
void	Bureaucrat::signForm(AForm& form)
{
	if (form.getIsSigned())
		std::cout << form.getName() << " is already signed" << std::endl;
	else
	{
		try
		{
			form.beSigned(*this);
			std::cout << this->getName() << " signed " << form.getName() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << " The required grade to sign is [" << form.getGradeSign() << "], " << getName() << "'s grade is [" << getGrade() << "]" << std::endl;
		}
	}
}

/*--------------------------------------------------*/
/* tries to exec and prints appropriate messages	*/
/*--------------------------------------------------*/
void	Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout <<  _name << " couldn't execute " << form.getName() << " because " << e.what();
		if (form.getIsSigned())
			std::cout << " The required grade to execute is [" << form.getGradeExec() << "], " << getName() << "'s grade is [" << getGrade() << "]";
		std::cout << std::endl;
	}
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
	return ("grade is too high!");
}

/*------------------------------------------*/
/* Throws exception if grade too low		*/
/*------------------------------------------*/

const char* Bureaucrat::GradeTooLowException::what() const _NOEXCEPT
{
	return ("grade is too low!");
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
