/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:07:00 by poverbec          #+#    #+#             */
/*   Updated: 2025/11/22 12:44:28 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>


class AForm;

class Bureaucrat
{
	protected:
	std::string const _name;
	unsigned int _grade;

	public:
	Bureaucrat();
	virtual ~Bureaucrat();
	Bureaucrat(const std::string &name, unsigned int );
	Bureaucrat(const Bureaucrat& object);
	
	Bureaucrat& operator=(const Bureaucrat& object);
	
	std::string getName()  const noexcept;
	unsigned int getGrade() const noexcept;

	
	void incrementBy(int nbr);
	void decrementBy(int nbr);
	void getStatus();
	void signForm(AForm &object);

	virtual void executeForm(AForm const & form) const;
};





std::ostream &operator<<(std::ostream &out, const Bureaucrat& Bureaucrat );
std::ostream &operator<<(std::ostream &out, const AForm& object );


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
	//signing
	GradeTooLowException(const std::string& Name, unsigned int gradeBu, unsigned int gradeForm);
	//execute
	GradeTooLowException(unsigned int gradeBu, unsigned int gradeForm, const std::string& Name);
	virtual const char* what() const throw();
};

class FromNotExisting : public std::exception
{
	private:
	std::string ErrorMessage;
	
	public:
	FromNotExisting(const std::string &name);
	virtual const char* what() const throw();
};
//Form::GradeTooHighException : public std::exception

#endif