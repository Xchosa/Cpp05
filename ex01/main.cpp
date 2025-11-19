/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:08:33 by poverbec          #+#    #+#             */
/*   Updated: 2025/11/19 17:48:49 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"



int main()
{
	std::cout << "Creating some Bureaucrat" << std::endl;
	
	
	std::cout << "Test: Sign Grade is to low: " << std::endl;
	try{
		Bureaucrat second("Thin", 100);
		Form toLow("Doof", 10, 50 );
		signForm(tolow);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}


	std::cout << "Test: Grade is to low: " << std::endl;
	try{
		Bureaucrat third("Dump", 151);
		std::cout << third;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	try{
		Bureaucrat first("Dick", 5);
		std::cout << first;
		first.incrementBy(10);
		first.getStatus();
		first.decrementBy(-13);
		first.getStatus();
		first.decrementBy(-2);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	

	return 0;
}