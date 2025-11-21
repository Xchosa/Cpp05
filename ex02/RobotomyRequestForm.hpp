/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:47:24 by poverbec          #+#    #+#             */
/*   Updated: 2025/11/21 15:31:19 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>

#include "AForm.hpp"

#include "Bureaucrat.hpp"


class RobotomyRequestForm : public AForm
{
	private:
	std::string target;

	public:
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &object);
	RobotomyRequestForm& operator=(const RobotomyRequestForm &object);

	RobotomyRequestForm(const std::string& target);
	

	void execute(Bureaucrat const & executor) const override;
};