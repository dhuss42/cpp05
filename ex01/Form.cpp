#include "Form.hpp"

/*----------------------*/
/* Constructor			*/
/*----------------------*/
Form::Form(std::string const name, unsigned int grade_sign, unsigned int grade_exec) : _name(name), _is_signed(0), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
	this->checkGrade(_grade_sign);
	this->checkGrade(_grade_exec);
}

/*----------------------*/
/* Copy Constructor		*/
/*----------------------*/
Form::Form(const Form& src) : _name(src._name), _is_signed(src._is_signed), _grade_sign(src._grade_sign), _grade_exec(src._grade_exec)
{
}

/*----------------------*/
/* Assignment operator	*/
/*----------------------*/
Form& Form::operator=(const Form& other)
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
Form::~Form()
{
}

//------------public member methods------------//

/*----------------------------------------------*/
/* checks if grade is high enough too sign		*/
/*----------------------------------------------*/
void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _grade_sign)
		throw(GradeTooLowException());
	else
		_is_signed = true;
}

//------------getters------------//

std::string Form::getName(void) const
{
	return (_name);
}

bool	Form::getIsSigned(void) const
{
	return (_is_signed);
}

unsigned int Form::getGradeSign(void) const
{
	return (_grade_sign);
}

unsigned int Form::getGradeExec(void) const
{
	return (_grade_exec);
}

//------------exceptions------------//

const char * Form::GradeTooHighException::what() const _NOEXCEPT
{
	return ("grade too high!");
}

const char * Form::GradeTooLowException::what() const _NOEXCEPT
{
	return ("grade too low!");
}

//------------helpers------------//

/*----------------------------------*/
/* Function to check passed grades	*/
/*----------------------------------*/
void	Form::checkGrade(unsigned int grade) const
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
std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form name: [" << form.getName() << "]\n\tStatus:\t\t\t [" << form.getIsSigned() << "]\n\tGrade needed to sign:\t [" << form.getGradeSign() << "]\n\tGrade needed to execute: [" << form.getGradeExec() << "]";
	return (os);
}

