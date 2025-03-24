#include "Bureaucrat.hpp"


void	error(const std::exception& e)
{
	std::cout << "error: " << e.what() << std::endl;
}

int	main(void)
{
	std::cout << "\033[34m[----------Constructor Tests----------]\033[37m" << std::endl;
	std::cout << "\033[33m- Default Constructor\033[37m" << std::endl;
	Form form("B27", 4, 7);
	std::cout << form << std::endl;

	std::cout << "\033[33m- Copy Constructor\033[37m" << std::endl;
	Form copyForm(form);
	std::cout << copyForm << std::endl;

	std::cout << "\033[33m- Assignment operator\033[37m" << std::endl;
	Form assign("A20", 45, 50);
	std::cout << "\033[35m--> pre assignment\033[37m" << std::endl;
	std::cout << assign << std::endl;

	assign = form;
	std::cout << "\033[35m--> post assignment\033[37m" << std::endl;
	std::cout << assign << std::endl;

	std::cout << "\033[34m\n[----------Initial Grade Tests Form----------]\033[37m" << std::endl;
	std::cout << "\033[33m- _grade_sign\033[37m" << std::endl;
	std::cout << "\033[35m--> too high test\033[37m" << std::endl;
	try
	{
		Form formError("B27", 0, 7);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\033[35m--> too low test\033[37m" << std::endl;
	try
	{
		Form formError("B27", 151, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\033[33m- _grade_exec\033[37m" << std::endl;
	std::cout << "\033[35m--> too high test\033[37m" << std::endl;
	try
	{
		Form formError("B27", 2, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\033[35m--> too low test\033[37m" << std::endl;
	try
	{
		Form formError("B27", 1, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\033[34m\n[----------Sign Form Tests----------]\033[37m" << std::endl;
	std::cout << "\033[35m--> successful signing the form\033[37m" << std::endl;
	Bureaucrat mrBusy("mrBusy", 1);
	mrBusy.signForm(form);

	std::cout << "\033[35m--> already signed\033[37m" << std::endl;
	mrBusy.signForm(form);

	std::cout << "\033[35m--> grade too low\033[37m" << std::endl;
	Bureaucrat mrLazy("mrLazy", 150);
	mrLazy.signForm(assign);
}
