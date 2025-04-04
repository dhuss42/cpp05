/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:39:54 by dhuss             #+#    #+#             */
/*   Updated: 2025/03/27 11:54:08 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*----------------------*/
/* Default Constructor	*/
/*----------------------*/
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default ShrubberyCreationForm", 145, 137), _target("default target")
{
}

/*----------------------*/
/* Constructor			*/
/*----------------------*/
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

/*----------------------*/
/* Copy Constructor		*/
/*----------------------*/
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src)
{
}

/*----------------------*/
/* Assignment operator	*/
/*----------------------*/
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

/*----------------------*/
/* Destructor			*/
/*----------------------*/
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

//------------public methods-----------//

/*----------------------*/
/* overriden executeIt	*/
/*----------------------*/
void	ShrubberyCreationForm::executeIt(void) const
{
	std::ofstream file(_target + "_shrubbery");
	if (!file)
		std::cerr << "Error: could not open file " << _target + "_shrubbery" << std::endl;
	file	<< "                                                     \n"
			<< "                                  .         ;\n"
			<< "                 .              .              ;%     ;;\n"
			<< "                   ,           ,                :;%  %;\n"
			<< "                    :         ;                   :;%;'     ., \n"
			<< "           ,.        %;     %;            ;        %;'    ,;\n"
			<< "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
			<< "              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
			<< "               ;%;      %;        ;%;        % ;%;  ,%;'\n"
			<< "                `%;.     ;%;     %;'         `;%%;.%;'\n"
			<< "                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
			<< "                    `:%;.  :;bd%;          %;@%;'\n"
			<< "                      `@%:.  :;%.         ;@@%;'\n"
			<< "                        `@%.  `;@%.      ;@@%;\n"
			<< "                          `@%%. `@%%    ;@@%;\n"
			<< "                            ;@%. :@%%  %@@%;\n"
			<< "                              %@bd%%%bd%%:;\n"
			<< "                                #@%%%%%:;;\n"
			<< "                                %@@%%%::;\n"
			<< "                                %@@@%(o);  . '\n"
			<< "                                %@@@o%;:(.,'\n"
			<< "                            `.. %@@@o%::;\n"
			<< "                               `)@@@o%::;\n"
			<< "                                %@@(o)::;\n"
			<< "                               .%@@@@%::;\n"
			<< "                               ;%@@@@%::;.\n"
			<< "                              ;%@@@@%%:;;;.\n"
			<< "                          ...;%@@@@@%%:;;;;,..    Artist: Gilo97\n";
	file.close();
}