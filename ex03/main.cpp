/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:08:33 by poverbec          #+#    #+#             */
/*   Updated: 2025/11/24 15:00:18 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main()
{
	 std::cout << "=== TESTING FORM SIGNING AND EXECUTION ===" << std::endl;

    // ========== SHRUBBERY CREATION FORM ==========
    std::cout << "\n--- SHRUBBERY CREATION FORM (sign: 145, exec: 137) ---\n";
	

	std::cout << "\n// 1. Grade to low to sign\n";
	try
	{
		Bureaucrat B3("Charlie", 146);  // Exact grade to execute
        ShrubberyCreationForm SCF3("forest");
        B3.signForm(SCF3);
        //std::cout << SCF3 << std::endl;
        B3.executeForm(SCF3);  // Should create file
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}




    
    std::cout << "\n--- SHRUBBERY CREATION FORM (sign: 145, exec: 137) ---\n";
	

	std::cout << "\n// 3. Exact grade to execute\n";
	try
	{
		Bureaucrat B3("Charlie", 137);  // Exact grade to execute
        ShrubberyCreationForm SCF3("forest");
        B3.signForm(SCF3);
        //std::cout << SCF3 << std::endl;
        B3.executeForm(SCF3);  // Should create file
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}


	// ========== ROBOTOMY REQUEST FORM ==========
	std::cout << "\n--- ROBOTOMY REQUEST FORM (sign: 72, exec: 45) ---\n";
	

	std::cout << "\n// 6. Bureaucrat with exact grade to execute\n";
	try
    {
        Bureaucrat B6("Frank", 45);  // Exact grade to execute
        RobotomyRequestForm RF3("target3");
        B6.signForm(RF3);
        std::cout << RF3 << std::endl;
        B6.executeForm(RF3);  // Should robotomize
    }
    catch (const std::exception &e)
    {
        std::cerr  << e.what() << std::endl;
    }

	// ========== PRESIDENTIAL PARDON FORM ==========
    std::cout << "\n--- PRESIDENTIAL PARDON FORM (sign: 25, exec: 5) ---\n";


	std::cout << "\n// 8. Bureaucrat with exact grade to execute\n";
    try
    {
        Bureaucrat B9("Iris", 5);  // Exact grade to execute
        PresidentialPardonForm PF3("criminal3");
        B9.signForm(PF3);
        std::cout << PF3 << std::endl;
        B9.executeForm(PF3);  // Should pardon
    }
    catch (const std::exception &e)
    {
        std::cerr  << e.what() << std::endl;
    }

    // ========== Interm coffee making ==========
    std::cout << "\n--- Intern creating FORM (sign: 25, exec: 5) ---\n";
    try
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        delete rrf;
    }
    catch (const std::exception &e)
    {
        std::cerr  << e.what() << std::endl;
    }
	return 0;
}