/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:18:25 by poverbec          #+#    #+#             */
/*   Updated: 2025/11/19 16:12:04 by poverbec         ###   ########.fr       */
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

//unsigned int Bureaucrat::setGrade()
//{
//	t
//}

void Bureaucrat::incrementBy(int nbr)
{
	int test_grade = this->getGrade();
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

void Bureaucrat::decrementBy(int nbr)
{
	int test_grade = this->getGrade();
	std::cout << "Try to decrement " << getName() << " by "<< nbr << std::endl;
	if((test_grade + nbr ) < 1)
		throw GradeTooHighException(this->getName(), test_grade);
	else
	{
		this->_grade = test_grade +nbr;
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


Form::Form(const std::string &name, unsigned int nbrToSign, unsigned int nbrToExe ): _Name(_Name) , isSigned(false), ReGradeToSign(), ReGradeToExec()
{
	if (nbrToSign > 150)
		throw GradeTooLowException(Name, nbrToSign);
	if (nbrToSign  < 1)
		throw GradeTooHighException(Name, nbrToSign);
	if (nbrToExe > 150)
		throw GradeTooLowException(Name, nbrToExe);
	if (nbrToExe  < 1)
		throw GradeTooHighException(Name, nbrToExe);
	
	std::cout << "Creating Form: " << std::endl;
}


Form::Form(): _Name("default") , isSigned(false), ReGradeToSign(), ReGradeToExec()
{
	std::cout << "Form created:" << std::endl;
}

Form::~Form()
{};
Form& Form::operator=(const Form &object)
{
	if(this != &object)
	{
		this->_Name = _Name;
		this->isSigned = isSigned;
		this->ReGradeToExec = ReGradeToExec;
		this->ReGradeToSign = ReGradeToSign;
	}
	return(*this);
}
Form::Form(const Form &object) : _Name("default") , isSigned(false), ReGradeToSign(), ReGradeToExec()
{
};

void Form::beSigned(const Bureaucrat &object)
{
	// 	
// 					10 						15
	if (this->getReGradeToSign() > object.getGrade())
		throw GradeTooLowException(object.getName(), object.getGrade());
//			5					3
	if (object.getGrade()  > object.getGrade())
		throw GradeTooHighException(object.getName(), object.getGrade());
	
	this->isSigned = true;
	std::cout << "Form signed by Bureaucrat: " << object.getName() << std::endl;
}
/*

	*/

std::string Form::getName()
{
	return(this->_Name);
}

bool Form::getSignature()
{
	return (this->isSigned);
}
unsigned int Form::getReGradeToSign()
{
	return (this->ReGradeToSign);
}
unsigned int Form::getReGradeToExec()
{
	return(this->ReGradeToExec);
}
void Form::getStatus()
{
	std::cout << "Status of Bureaucrat: " << std::endl;
	std::cout << getName() << " is signed: " << getSignature() << "Grade needed to sign: "
	<< getReGradeToSign << "Grade needed to Execute " << getReGradeToExec() << std::endl;
}