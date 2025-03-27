/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:04:33 by dhuss             #+#    #+#             */
/*   Updated: 2025/03/27 11:47:40 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_is_signed;
		unsigned int		_grade_sign;
		unsigned int		_grade_exec;
	protected:
		virtual void executeIt(void) const = 0;
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
		class FormIsNotSignedException: public std::exception
		{
			public:
				const char * what() const _NOEXCEPT;
		};
		class FormIsSignedException: public std::exception
		{
			public:
				const char * what() const _NOEXCEPT;
		};

		AForm();
		AForm(std::string const name, unsigned int grade_sign, unsigned int grade_exec);
		AForm(const AForm& src);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		std::string		getName(void) const;
		bool			getIsSigned(void) const;
		unsigned int	getGradeSign(void) const;
		unsigned int	getGradeExec(void)	const;

		void	checkGrade(unsigned int grade) const;
		void	beSigned(const Bureaucrat& bureaucrat);
		int		execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);

#endif