/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:48:01 by poverbec          #+#    #+#             */
/*   Updated: 2025/11/24 14:52:28 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"



PresidentialPardonForm::PresidentialPardonForm() :AForm("PresidentialPardonForm", 25, 5) , target()
{
	std::cout << "PresidentialPardonForm created" << std::endl;
};
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructed" << std::endl;
};
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &object): AForm(object)
{
	
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &object)
{
	if(this != &object)
	{
		AForm::operator=(object);
	}
	return(*this);
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :AForm("PresidentialPardonForm", \
25, 5) , target(target + "_PresidentialPardon")
{
	
}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const
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
		std::cout << "* pardoned by Zaphod Beeblebrox *" << std::endl;
		std::cout << "Form executed by Bureaucrat: " << executor.getName() << std::endl;
	}
}