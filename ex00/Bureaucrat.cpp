/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:18:25 by poverbec          #+#    #+#             */
/*   Updated: 2025/11/24 14:14:23 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(const std::string &complicatedName,unsigned int nbr) : _name(complicatedName), _grade(nbr)
{
	if (nbr > 150)
		throw GradeTooLowException(complicatedName, nbr);
	if (nbr < 1)
		throw GradeTooHighException(complicatedName, nbr);
	
	std::cout << "Creating Bureaucrat: " << std::endl;
}
Bureaucrat::Bureaucrat()
{};

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destroying Bureaucrat: " << getName() << std::endl;
};
	
Bureaucrat::Bureaucrat(const Bureaucrat& object) :_name(object._name), _grade(object._grade)
{
};
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &object)
{
	if(this != &object)
	{
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


void Bureaucrat::decrementBy(int nbr)
{
	int test_grade = this->getGrade();
	std::cout << "Try to decrement " << getName() << " by "<< nbr << std::endl;
	if((test_grade + nbr ) > 150)
		throw GradeTooLowException(this->getName(), test_grade);
	else
	{
		this->_grade = test_grade +nbr;
	}
}


void Bureaucrat::getStatus()
{
	std::cout << "Status of Bureaucrat: " << std::endl;
	std::cout << getName() << "grade: " << getGrade() << std::endl;
}

void Bureaucrat::incrementBy(int nbr)
{
	int test_grade = this->getGrade();
	std::cout << "Try to increment " << getName() << " by "<< nbr << std::endl;
	if((test_grade - nbr ) < 1)
		throw GradeTooHighException(this->getName(), test_grade);
	else
	{
		this->_grade = test_grade  - nbr;
	}
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
	out << Bureaucrat.getName() << ", the bureaucrat's grade is " << Bureaucrat.getGrade() << "." << std::endl;
	return out;
};