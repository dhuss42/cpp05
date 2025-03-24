#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
	private:
		std::string const	_name;
		bool				_is_signed;
		unsigned int		_grade_sign;
		unsigned int		_grade_exec;
	public:
		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const _NOEXCEPT;
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char * what() const _NOEXCEPT;
		};

		Form();
		Form(const Form& src);
		Form& operator=(const Form& other);
		~Form();

		std::string		getName(void) const;
		bool			getIsSigned(void) const;
		unsigned int	getGradeSign(void) const;
		unsigned int	getGradeExec(void)	const;

		bool	beSigned(const Bureaucrat& bureaucrat);
			// changes the form's status to signed if bc's grade is high enough
			//	<= bc_grade
			// -> if too low Form::gradetooLow...

};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif