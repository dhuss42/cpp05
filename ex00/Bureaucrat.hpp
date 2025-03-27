/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:03:46 by dhuss             #+#    #+#             */
/*   Updated: 2025/03/27 11:38:32 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

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

		Bureaucrat();
		Bureaucrat(std::string const name, unsigned int grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& src);
		~Bureaucrat();

		std::string		getName(void) const;
		unsigned int	getGrade(void) const;

		void	incrementGrade(void);
		void	decrementGrade(void);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bc);

#endif