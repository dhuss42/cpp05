#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Bureaucrat
{
	private:
		std::string const	_name;
		unsigned int		_grade;
	public:

		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const _NOEXCEPT;
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const _NOEXCEPT;
		};
		
		Bureaucrat(std::string const name, unsigned int grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& src);
		~Bureaucrat();

		std::string		getName(void) const;
		unsigned int	getGrade(void) const;

		void	incrementGrade(void);
		void	decrementGrade(void);
	
		void	signForm(Form& form);
		// calls Form::beSigned()
		// -> if form is signed it prints name signed form
		// -> otherwise name couldn't sign form because reason
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bc);

#endif