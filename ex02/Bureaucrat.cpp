/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:18:25 by poverbec          #+#    #+#             */
/*   Updated: 2025/11/24 14:18:00 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"


Bureaucrat::Bureaucrat(const std::string &complicatedName,unsigned int nbr) : _name(complicatedName), _grade(nbr)
{
	if (nbr > 150)
		throw GradeTooLowException(complicatedName, nbr);
	if (nbr < 1)
		throw GradeTooHighException(complicatedName, nbr);
	
	std::cout << "Creating Bureaucrat: " << getName() << ", grade: " << getGrade() <<std::endl;
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

void Bureaucrat::signForm( AForm &object) 
{
	if(object.getSignature() == true)
	{
		std::cout << object.getName() << "already signed" << std::endl;
		return;
	}

	// void Form::beSigned( Bureaucrat &object)
	object.beSigned(*this);
	if(object.getSignature() == true)
	{
		std::cout << this->getName() << " signed " << object.getName() << std::endl;
	}
	else
		std::cout << "couldn't sign" << object.getName() << "because" << "grade is to low: "
		"Bureaucrat grade: "<< this->getGrade() << "required to sign" << object.getReGradeToSign() << std::endl;
};






void Bureaucrat::executeForm(AForm const & form) const
{
	//if(form.getSignature() == false)
	//{
	//	std::cout << "Form is not signed yet" << std::endl; 
	//	return;
	//}

	//if (form.getReGradeToExec() < this->getGrade())
	//{
	//	// for Execption for executing
	//	throw GradeTooLowException(this->getGrade(), form.getReGradeToExec(), this->getName());
	//}
	//else
	//{
	//	std::cout << getName() <<"* executed  *" << std::endl;
	//	std::cout << "Form executed by Bureaucrat: " << this->getName() << std::endl;
	//}


	try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch (const std::exception & e)
    {
        std::cout << this->getName() << " couldn't execute " << form.getName() 
            << " because " << e.what() << std::endl;
    }
};








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
GradeTooLowException::GradeTooLowException(const std::string& Name, unsigned int gradeBu, unsigned int gradeForm)
{
	ErrorMessage =  Name + ": Grade if is too low (" +  std::to_string(gradeBu) \
	 +  ") to sign Form. Form requires: " + std::to_string(gradeForm);
}

GradeTooLowException::GradeTooLowException(unsigned int gradeBu, unsigned int gradeForm, const std::string& Name)
{
	ErrorMessage =  Name + ": Grade if is too low (" +  std::to_string(gradeBu) \
	 +  ") to execute Form. Form requires: " + std::to_string(gradeForm);
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


