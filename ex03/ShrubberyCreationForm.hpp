/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:12:06 by poverbec          #+#    #+#             */
/*   Updated: 2025/11/21 14:49:01 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>

#include "AForm.hpp"

#include "Bureaucrat.hpp"
#include <fstream> 

class ShrubberyCreationForm : public AForm
{
	private:
	std::string target;


	public:
	ShrubberyCreationForm();
	~ShrubberyCreationForm();
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &object);
	ShrubberyCreationForm( const ShrubberyCreationForm &object);
	ShrubberyCreationForm(std::string target);

	void execute(Bureaucrat const & executor) const override;
};