/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:18:25 by poverbec          #+#    #+#             */
/*   Updated: 2025/11/17 18:16:45 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(const std::string &complicatedName,unsigned int nbr) : _name(complicatedName), _grade(nbr)
{
	if (nbr > 150)
		throw GradeTooLowException(complicatedName, nbr);
	if (nbr < 1)
		throw GradeTooHighException(complicatedName, nbr);
	
	std::cout << "Creating Bureaucrat" << std::endl;
	this->_grade = nbr;
}
Bureaucrat::Bureaucrat()
{};

Bureaucrat::~Bureaucrat()
{};
	
Bureaucrat::Bureaucrat(const Bureaucrat& object) :_name(object._name), _grade(object._grade)
{
};
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &object)
{
	if(this != &object)
	{
		//this->_name = object._name;
		this->_grade = object._grade;
	}
	return (*this);
};

std::string Bureaucrat::getName()  const noexcept
{
	return this->_name;
	
};

unsigned int Bureaucrat::getGrade() const noexcept
{
	return this->_grade;
}

void Bureaucrat::incrementBy(unsigned int nbr)
{
	int test_grade = this->getGrade();
	if(test_grade + nbr >150)
		throw GradeTooLowException(this->getName, test_grade);
	
}




// lowest 150
const char* GradeTooLowException::what() const throw()
{
	return ErrorMessage.c_str();
}

GradeTooLowException::GradeTooLowException(const std::string& Name, unsigned int Grade)
{
	ErrorMessage =  Name + ": Grade is too low: " +  std::to_string(Grade) \
	 +  ".The allowed Range is 1 - 150. Must be smaler den 151";
}

// higest 1 
const char* GradeTooHighException::what() const throw()
{
	return ErrorMessage.c_str();
}

GradeTooHighException::GradeTooHighException(const std::string& Name, unsigned int Grade)
{
	ErrorMessage =  Name + ": Grade is too high: " +  std::to_string(Grade) \
	 +  ".The allowed Range is 1 - 150. Must be 1 or greater den 1";
}


std::ostream& operator<<(std::ostream& out, const Bureaucrat& Bureaucrat )
{
	out << Bureaucrat.getName() << ", the bureaucrat's grade is " << Bureaucrat.getGrade() << ".";
	return out;
};