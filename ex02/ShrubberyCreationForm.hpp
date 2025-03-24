#ifndef SHRUBBERYCREATIONFORM_CPP
# define SHRUBBERYCREATIONFORM_CPP

#include "AForm.hpp"
#include "fstream"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& src);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		void executeIt(void) const;
};


// sign grade 145
// execute grade 137
// creates a file target_shrubbery in wc and writes ASCII trees inside it

// one parameter in constructor
//	the target of the form
#endif