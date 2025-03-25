/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:24:44 by dhuss             #+#    #+#             */
/*   Updated: 2025/03/25 15:40:35 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include	"AForm.hpp"
#include	"ShrubberyCreationForm.hpp"
#include	"RobotomyRequestForm.hpp"
#include	"PresidentialPardonForm.hpp"

class Intern
{
	private:

	public:
		Intern();
		Intern(const Intern& src);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm* makeShrub(std::string target);
		AForm* makeRobo(std::string target);
		AForm* makePresi(std::string target);
		AForm* makeForm(std::string name, std::string target);
};

#endif