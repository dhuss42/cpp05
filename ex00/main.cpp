#include "Bureaucrat.hpp"

// try catch allows us to handle the exception without the program crashing
// wrap insinde try catch block
	// inside try is what we want to test 
	// inside catch (...)
		// if error is found inside try, execution will move to catch block
		// (...) catches any type of excpetion could be different types
		// 		types are also derived
		//			order of catching is important!
		// can have multiple catch blocks
	// can throw own exceptions
		// inside the try block

	// custom exception types
		// create derived class of the exception class
		// own definition of what method
		// noexcept specifier -> means this function will not throw an exception

void	error(const std::exception& e)
{
	std::cout << "error: " << e.what() << std::endl;
}

int	main(void)
{
	std::cout << "\033[34m[----------Constructor Tests----------]\033[37m" << std::endl;
	std::cout << "\033[33m- Default Constructor\033[37m" << std::endl;
	Bureaucrat mrBusy("mrBusy", 2);

	std::cout << mrBusy << std::endl;

	std::cout << "\033[33m- Copy Constructor\033[37m" << std::endl;
	Bureaucrat copy(mrBusy);
	std::cout << copy << std::endl;

	std::cout << "\033[33m- Assignment\033[37m" << std::endl;
	std::cout << "\033[35m--> pre assignment\033[37m" << std::endl;
	Bureaucrat assign("assign", 5);
	std::cout << assign << std::endl;

	assign = mrBusy;
	std::cout << "\033[35m--> post assignment\033[37m" << std::endl;
	std::cout << assign << std::endl;

	std::cout << "\033[34m\n[----------Initial Grade Tests----------]\033[37m" << std::endl;
	std::cout << "\033[35m--> too high test\033[37m" << std::endl;
	try
	{
		Bureaucrat tooHigh("Mr High", 0);
	}
	catch(const std::exception& e)
	{
		error(e);
	}
	std::cout << "\033[35m--> too low test\033[37m" << std::endl;
	try
	{
		Bureaucrat tooLow("Mr Low", 151);
	}
	catch(const std::exception& e)
	{
		error(e);
	}

	std::cout << "\033[34m\n[----------Icrement/Decrement Grade Tests----------]\033[37m" << std::endl;
	std::cout << "\033[33m- succesfull incrementation \033[37m" << std::endl;
	std::cout << "\033[35m--> pre icrementation\033[37m" << std::endl;
	std::cout << mrBusy << std::endl;
	try
	{
		mrBusy.incrementGrade();
	}
	catch(const std::exception& e)
	{
		error(e);
	}
	std::cout << "\033[35m--> post icrementation\033[37m" << std::endl;
	std::cout << mrBusy << std::endl;

	std::cout << "\033[33m- succesfull decrementation \033[37m" << std::endl;
	std::cout << "\033[35m--> pre decrementation\033[37m" << std::endl;
	std::cout << assign << std::endl;
	try
	{
		assign.decrementGrade();
	}
	catch(const std::exception& e)
	{
		error(e);
	}
	std::cout << "\033[35m--> post decrementation\033[37m" << std::endl;
	std::cout << assign << std::endl;

	std::cout << "\033[33m- error decrementation \033[37m" << std::endl;
	std::cout << "\033[35m--> pre decrementation\033[37m" << std::endl;
	Bureaucrat dude("dude", 150);
	std::cout << dude << std::endl;
	try
	{
		dude.decrementGrade();
	}
	catch(const std::exception& e)
	{
		error(e);
	}
	std::cout << "\033[35m--> post decrementation\033[37m" << std::endl;
	std::cout << dude << std::endl;

	std::cout << "\033[33m- error incrementation \033[37m" << std::endl;
	std::cout << "\033[35m--> pre icrementation\033[37m" << std::endl;
	std::cout << mrBusy << std::endl;
	try
	{
		mrBusy.incrementGrade();
	}
	catch(const std::exception& e)
	{
		error(e);
	}
	std::cout << "\033[35m--> post icrementation\033[37m" << std::endl;
	std::cout << mrBusy << std::endl;
	return (0);
}
