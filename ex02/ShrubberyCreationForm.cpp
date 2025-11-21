/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:12:15 by poverbec          #+#    #+#             */
/*   Updated: 2025/11/21 16:29:21 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) , target()
{
	 std::cout << "ShrubberyCreationForm created" << std::endl;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destroyed" << std::endl;
};
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) \
,target(target + "_shrubbery.txt")
{
	std::cout << "ShrubberyCreationForm created with target: " << this->target << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &object)
{
	if(this != &object)
	{
		AForm::operator=(object);
	}
	return (*this);
}
ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &object) : AForm(object)
{
};

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if(getSignature()== false)
	{
		std::cout << "ShrubberyCreationForm is not signed yet" << std::endl; 
		return;
	}

	if (executor.getGrade() > getReGradeToExec()) 
	{
		// for Execption for executing
		throw GradeTooLowException(executor.getGrade(), getReGradeToExec(), executor.getName());
	}
	else
	{
		//std::cout << "* Tz tz tz tz tz *" << std::endl;
		std::cout << "Form executed by Bureaucrat: " << executor.getName() << std::endl;
		std::ofstream outfile(this->target);
		if(!outfile.is_open())
		{
			std::cerr << "Error: Could not create file" << std::endl;
            return;
		}
		outfile << "                    *" << std::endl;
		outfile << "                   /|\\" << std::endl;
		outfile << "                  / | \\" << std::endl;
		outfile << "                 /  |  \\" << std::endl;
		outfile << "                *   |   *" << std::endl;
		outfile << "               /|   |   |\\" << std::endl;
		outfile << "              / |   |   | \\" << std::endl;
		outfile << "             *  |   |   |  *" << std::endl;
		outfile << "            /|\\ |   |   | /|\\" << std::endl;
		outfile << "           / | \\|   |   |/ | \\" << std::endl;
		outfile << "          *  |  *   |   *  |  *" << std::endl;
		outfile << "         /|\\ | /|\\  |  /|\\ | /|\\" << std::endl;
		outfile << "        / | \\|/ | \\ | / | \\|/ | \\" << std::endl;
		outfile << "       *  |  *  |  *-*  |  *  |  *" << std::endl;
		outfile << "      /|\\ | /|\\ | /   \\ | /|\\ | /|\\" << std::endl;
		outfile << "     / | \\|/ | \\|/     \\|/ | \\|/ | \\" << std::endl;
		outfile << "    *  |  *  |  *       *  |  *  |  *" << std::endl;
		outfile << "   /|\\ | /|\\ | /|\\     /|\\ | /|\\ | /|\\" << std::endl;
		outfile << "  / | \\|/ | \\|/ | \\   / | \\|/ | \\|/ | \\" << std::endl;
		outfile << " *  |  *  |  *  |  *-*  |  *  |  *  |  *" << std::endl;
		outfile << "/|\\ | /|\\ | /|\\ | /   \\ | /|\\ | /|\\ | /|\\" << std::endl;
		outfile << "-----+-----+-----+-------+-----+-----+-----" << std::endl;
		outfile.close();
		std::cout << "Shrubbery file created now: " << this->target << std::endl;
	}
	
};
