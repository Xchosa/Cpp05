/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:08:33 by poverbec          #+#    #+#             */
/*   Updated: 2025/11/24 14:31:00 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
	 std::cout << "=== TESTING FORM SIGNING AND EXECUTION ===" << std::endl;

    // ========== SHRUBBERY CREATION FORM ==========
    std::cout << "\n--- SHRUBBERY CREATION FORM (sign: 145, exec: 137) ---\n";
	

	std::cout << "\n// 1. Grade too low to sign\n";
	try
	{
		Bureaucrat B2("Bob", 150);
		ShrubberyCreationForm SCF1("Shrubbery_Dick"); // executeGrade > 0
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

	std::cout << "\n// 2. Exact grade to sign\n";
	try
	{
		 Bureaucrat B2("Bob", 145); 
		ShrubberyCreationForm SCF2("park");
        B2.signForm(SCF2);
        std::cout << SCF2 << std::endl;
        
        // Try to execute with grade too low
        B2.executeForm(SCF2);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

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
	
	std::cout << "\n// 4 . Bureaucrat grade too low to sign" << std::endl;
	try
	{
		Bureaucrat B4("David", 100);  // Grade too low to sign
        RobotomyRequestForm RF1("target1");
        B4.signForm(RF1);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n// 5. Bureaucrat with exact grade to sign but too low to execute\n";
	try
	{
		Bureaucrat B5("Eve", 72);  // Exact grade to sign
        RobotomyRequestForm RF2("target2");
        B5.signForm(RF2);
        std::cout << RF2 << std::endl;
        
        // Try to execute with grade too low
        B5.executeForm(RF2);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

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

	std::cout << "\n// 7 . Bureaucrat grade too low to sign" << std::endl;
    try
    {
        Bureaucrat B7("Grace", 50);  // Grade too low to sign
        PresidentialPardonForm PF1("criminal1");
        B7.signForm(PF1);
    }
    catch (const std::exception &e)
    {
        std::cerr  << e.what() << std::endl;
    }

	std::cout << "\n// 8. Bureaucrat with exact grade to sign but too low to execute\n";
    try
    {
        Bureaucrat B8("Henry", 25);  // Exact grade to sign
        PresidentialPardonForm PF2("criminal2");
        B8.signForm(PF2);
        std::cout << PF2 << std::endl;
        
        // Try to execute with grade too low
        B8.executeForm(PF2);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

	std::cout << "\n// 9. Bureaucrat with exact grade to execute\n";
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


	return 0;
}