/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:24:03 by poverbec          #+#    #+#             */
/*   Updated: 2025/11/24 15:09:24 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp" 

Form::Form(const std::string &name, unsigned int nbrToSign, unsigned int nbrToExe ): _Name(name) , isSigned(false), ReGradeToSign(nbrToSign), ReGradeToExec(nbrToExe)
{
	if (nbrToSign > 150)
		throw GradeTooLowException(_Name, nbrToSign);
	if (nbrToSign  < 1)
		throw GradeTooHighException(_Name, nbrToSign);
	if (nbrToExe > 150)
		throw GradeTooLowException(_Name, nbrToExe);
	if (nbrToExe  < 1)
		throw GradeTooHighException(_Name, nbrToExe);
	

	
	std::cout << "Creating Form: "<< getName() << " ,Grade to Sign: " << getReGradeToSign()
	<< " ,Grade to Execute: " << getReGradeToExec()<<std::endl;
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
		this->isSigned = object.isSigned;
	}
	return(*this);
}

Form::Form(const Form &object) : _Name(object._Name) , isSigned(object.isSigned), ReGradeToSign(object.ReGradeToSign), ReGradeToExec(object.ReGradeToExec)
{
};

void Form::beSigned( Bureaucrat &object)
{
	// 	
// 					16 						10
	if (this->getReGradeToSign() < object.getGrade())
	{
		throw GradeTooLowException(object.getName(), object.getGrade(), getReGradeToSign());
	}
//		5					3
	//if (object.getGrade()  > object.getGrade())
	//	throw GradeTooHighException(object.getName(), object.getGrade());
	else
	{
		this->isSigned = true;
		std::cout << "Form signed by Bureaucrat: " << object.getName() << std::endl;
	}
}
/*

	*/

std::string Form::getName() const noexcept
{
	return(this->_Name);
}

bool Form::getSignature() const noexcept
{
	return (this->isSigned);
}
unsigned int Form::getReGradeToSign() const noexcept
{
	return (this->ReGradeToSign);
}
unsigned int Form::getReGradeToExec() const noexcept
{
	return(this->ReGradeToExec);
}
void Form::getStatus() const noexcept
{
	std::cout << "Status of Bureaucrat: " << std::endl;
	std::cout << getName() << " is signed: " << getSignature() << "Grade needed to sign: "
	<< getReGradeToSign() << "Grade needed to Execute " << getReGradeToExec() << std::endl;
}

//std::string Form::stringSignature(Form object)
//{
//	if(object.getSignature() == 1)
//		return("signed");
//	else
//		return("unsigned");
//}

std::ostream &operator<<(std::ostream &out, const Form& Form )
{
	out << "The Form: \" "<< Form.getName() << " \" is " << (Form.getSignature() ? "signed" : "unsigned") << "." << std::endl;
	return out;
}