#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

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

		Form(std::string const name, unsigned int grade_sign, unsigned int grade_exec);
		Form(const Form& src);
		Form& operator=(const Form& other);
		~Form();

		std::string		getName(void) const;
		bool			getIsSigned(void) const;
		unsigned int	getGradeSign(void) const;
		unsigned int	getGradeExec(void)	const;

		void	checkGrade(unsigned int grade) const;
		void	beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif