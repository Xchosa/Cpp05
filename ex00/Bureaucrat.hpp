/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:07:00 by poverbec          #+#    #+#             */
/*   Updated: 2025/11/17 18:14:08 by poverbec         ###   ########.fr       */
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

	
	void incrementBy(unsigned int nbr);
	void decrementBy(unsigned int nbr);
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

#endif