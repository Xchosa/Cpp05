/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:24:00 by poverbec          #+#    #+#             */
/*   Updated: 2025/11/21 15:10:14 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
	private:
	std::string _Name;
	bool isSigned;
	unsigned int ReGradeToSign;
	unsigned int ReGradeToExec;

	public:
	AForm();
	virtual ~AForm();
	AForm(const std::string &name, unsigned int nbrToSign, unsigned int nbrToExe );
	AForm& operator=(const AForm &object);
	AForm(const AForm &object);
	virtual void beSigned(Bureaucrat &object);

	std::string getName() const noexcept;
	bool getSignature() const noexcept;
	unsigned int getReGradeToSign() const noexcept;
	unsigned int getReGradeToExec() const noexcept;;
	virtual void getStatus() const noexcept;

	virtual void execute(Bureaucrat const & executor) const = 0; 
};




#endif