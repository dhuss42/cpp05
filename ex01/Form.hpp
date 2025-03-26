/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:04:14 by dhuss             #+#    #+#             */
/*   Updated: 2025/03/24 16:04:14 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		virtual ~Form();

		std::string		getName(void) const;
		bool			getIsSigned(void) const;
		unsigned int	getGradeSign(void) const;
		unsigned int	getGradeExec(void)	const;

		void	checkGrade(unsigned int grade) const;
		virtual void	beSigned(const Bureaucrat& bureaucrat) = 0; // ?
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif