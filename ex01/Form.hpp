/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:24:00 by poverbec          #+#    #+#             */
/*   Updated: 2025/11/20 10:02:49 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

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
	Form(const std::string &name, unsigned int nbrToSign, unsigned int nbrToExe );
	Form& operator=(const Form &object);
	Form(const Form &object);
	void beSigned(Bureaucrat &object);
	//unsigned int getReGradeToSign();
	//unsigned int getReGradeToExec();

	std::string getName() const noexcept;
	bool getSignature() const noexcept;
	unsigned int getReGradeToSign() const noexcept;
	unsigned int getReGradeToExec() const noexcept;;
	void getStatus() const noexcept;
};




#endif