/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:47:36 by poverbec          #+#    #+#             */
/*   Updated: 2025/11/24 14:52:45 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"



RobotomyRequestForm::RobotomyRequestForm() : AForm("ShrubberyCreationForm", 72, 45) , target()
{
	std::cout << "drilling Noice forom Robotomy" << std::endl;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destroyed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :AForm("RobotomyRequestForm", 72, 45) \
,target(target)
{
	std::cout << "RobotomyRequestFormcreated with target: " << this->target << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &object) :AForm(object)
{};
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &object)
{
	if(this != &object)
	{
		AForm::operator=(object);
	}
	return (*this);
}



void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if(getSignature()== false)
	{
		throw FormNotSignedException(getName());
	}

	if (executor.getGrade() > getReGradeToExec()) 
	{
		// for Execption for executing
		throw GradeTooLowException(executor.getGrade(), getReGradeToExec(), executor.getName());
	}
	else
	{
		std::cout << "* Drilling noice *" <<  this->target << " has been robotomized by 50 %" << std::endl;
		std::cout << "Form executed by Bureaucrat: " << executor.getName() << std::endl;
	}
	
};