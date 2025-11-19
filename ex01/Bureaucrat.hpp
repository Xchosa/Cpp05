/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:07:00 by poverbec          #+#    #+#             */
/*   Updated: 2025/11/19 16:06:07 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
	protected:
	std::string const _name;
	unsigned int _grade;

	public:
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(const std::string &name, unsigned int );
	Bureaucrat(const Bureaucrat& object);
	
	Bureaucrat& operator=(const Bureaucrat& object);
	
	std::string getName()  const noexcept;
	unsigned int getGrade() const noexcept;

	
	void incrementBy(int nbr);
	void decrementBy(int nbr);
	void getStatus();
};

class Form
{
	private:
	std::string _Name;
	bool isSigned;
	unsigned int ReGradeToSign;
	unsigned int ReGradeToExec;

	public:
	Form();
	~Form();
	Form(const std::string &name, unsigned int );
	Form& operator=(const Form &object);
	Form(const Form &object);
	void beSigned(const Bureaucrat &object);
	unsigned int getReGradeToSign();
	unsigned int getReGradeToExec();

	std::string getName();
	bool getSignature();
	unsigned int getReGradeToSign();
	unsigned int getReGradeToExec();
	void getStatus();
};






std::ostream &operator<<(std::ostream &out, const Bureaucrat& Bureaucrat );



class GradeTooHighException : public std::exception
{
	private:
	std::string ErrorMessage;
	
	public:
	GradeTooHighException(const std::string& Name, unsigned int Grade) ;
	virtual const char* what() const throw();
};

class GradeTooLowException : public std::exception
{
	private:
	std::string ErrorMessage;
	
	public:
	GradeTooLowException(const std::string& name, unsigned int grade);
	virtual const char* what() const throw();
};


Form::GradeTooHighException : public std::exception

#endif