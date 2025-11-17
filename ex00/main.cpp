/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:08:33 by poverbec          #+#    #+#             */
/*   Updated: 2025/11/17 17:43:35 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"



int main()
{
	std::cout << "Creating some Bureaucrat" << std::endl;
	
	
	std::cout << "Test: Grade is to high: " << std::endl;
	try{
		Bureaucrat second("Thin", 0);
		std::cout << second;
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
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

}