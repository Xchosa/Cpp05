/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:31:22 by poverbec          #+#    #+#             */
/*   Updated: 2025/11/24 14:35:48 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::Intern()
{
	std::cout << "Intern created" << std::endl;
}
Intern::~Intern()
{
	std::cout << "Intern destroyed" << std::endl;
}
Intern::Intern(const Intern &object)
{
	(void)object;
}


Intern& Intern::operator=(const Intern &object)
{
	(void)object;
    return (*this);
}

enum type
{
	shrubbery,
	robotomy,
	presidential,
};
// allowed input 
// shrubbery creation
// robotomy request
// presidential pardon
AForm* Intern::makeForm(const std::string &FormName, const std::string &TargetofForm)
{
	std::string TypeForm[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	int type = 0;
	for (int i = 0; i <3 ; i++)
	{
		if (TypeForm[i] == FormName)
		{
			type = i;
			break;
		}
		if (i == 2)
			throw FromNotExisting(FormName);
	}
	
	switch(type)
	{
		case(shrubbery): return (new ShrubberyCreationForm(TargetofForm));
		case(robotomy) : return (new RobotomyRequestForm(TargetofForm));
		case(presidential): return (new PresidentialPardonForm(TargetofForm));
		default: throw FromNotExisting(FormName);
	}
	
}

