/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:08:33 by poverbec          #+#    #+#             */
/*   Updated: 2025/11/20 10:09:22 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"


int main()
{
	std::cout << "Creating some Bureaucrat" << std::endl;
	

	std::cout << "\n// 1. Form creation too high\n";
	try
	{
		Form f2("Dick", 50, 0); // executeGrade > 0
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}



	
	
	std::cout << "\n// 2. Form creation too low\n";
	try
	{
		Form F1("Dick", 50, 175); // executeGrade > 150
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

	std::cout << "\n// 3. Bureaucrat grade fits\n";
	try
	{
		Bureaucrat B2("Bob", 100);			 // bureaucrat with grade 100
		Form F3("Enough", 120, 50); 			// requires grade 120 to sign
		B2.signForm(F3);
		std::cout << F3 << "\n";						 // should work
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n// 4 . Bureaucrat grade too low to sign" << std::endl;
	try{
		Bureaucrat B1("Thin", 50);
		Form F2("Doof", 49, 50 );			// requiers 10 -> B1 only has 50
		B1.signForm(F2);
		std::cout << F2 << std::endl;				// should fail 
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n// 5. Bureaucrat with exact grade\n";
	try
	{
		Bureaucrat B3("Italia", 50);
		Form F5("perfect", 50, 100); 	// needs exactly 50 to sign
		B3.signForm(F5);				   // should succeed
		std::cout << F5 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}