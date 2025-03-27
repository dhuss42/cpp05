/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:04:28 by dhuss             #+#    #+#             */
/*   Updated: 2025/03/27 11:47:43 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*----------------------*/
/* Default Constructor	*/
/*----------------------*/
AForm::AForm() : _name("default form"), _is_signed(0), _grade_sign(150), _grade_exec(150)
{
}

/*----------------------*/
/* Constructor			*/
/*----------------------*/
AForm::AForm(std::string const name, unsigned int grade_sign, unsigned int grade_exec) : _name(name), _is_signed(0), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
	this->checkGrade(_grade_sign);
	this->checkGrade(_grade_exec);
}

/*----------------------*/
/* Copy Constructor		*/
/*----------------------*/
AForm::AForm(const AForm& src) : _name(src._name), _is_signed(src._is_signed), _grade_sign(src._grade_sign), _grade_exec(src._grade_exec)
{
}

/*----------------------*/
/* Assignment operator	*/
/*----------------------*/
AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		_is_signed = other._is_signed;
		_grade_sign = other._grade_sign;
		_grade_exec = other._grade_exec;
	}
	return (*this);
}

/*----------------------*/
/* Destructor			*/
/*----------------------*/
AForm::~AForm()
{
}

//------------public member methods------------//

/*----------------------------------------------*/
/* checks if grade is high enough too sign		*/
/*----------------------------------------------*/
void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _grade_sign)
		throw(GradeTooLowException());
	else
		_is_signed = true;
}

int	AForm::execute(const Bureaucrat& executor) const
{
	if (!getIsSigned())
		throw (FormIsNotSignedException());
	else if (executor.getGrade() > _grade_exec)
		throw (GradeTooLowException());
	else
	{
		executeIt();
		return (1);
	}
}

//------------getters------------//

std::string AForm::getName(void) const
{
	return (_name);
}

bool	AForm::getIsSigned(void) const
{
	return (_is_signed);
}

unsigned int AForm::getGradeSign(void) const
{
	return (_grade_sign);
}

unsigned int AForm::getGradeExec(void) const
{
	return (_grade_exec);
}

//------------exceptions------------//

const char * AForm::GradeTooHighException::what() const _NOEXCEPT
{
	return ("grade is too high!");
}

const char * AForm::GradeTooLowException::what() const _NOEXCEPT
{
	return ("grade is too low!");
}

const char * AForm::FormIsNotSignedException::what() const _NOEXCEPT
{
	return ("form is not signed");
}

//------------helpers------------//

/*----------------------------------*/
/* Function to check passed grades	*/
/*----------------------------------*/
void	AForm::checkGrade(unsigned int grade) const
{
	if (grade < 1)
		throw(GradeTooHighException());
	else if (grade > 150)
		throw(GradeTooLowException());
}

//------------Non-member methods------------//

/*----------------------*/
/* Insertion Operator	*/
/*----------------------*/
std::ostream& operator<<(std::ostream& os, const AForm& AForm)
{
	os << "Form name: [" << AForm.getName() << "]\n\tStatus:\t\t\t [" << AForm.getIsSigned() << "]\n\tGrade needed to sign:\t [" << AForm.getGradeSign() << "]\n\tGrade needed to execute: [" << AForm.getGradeExec() << "]";
	return (os);
}

