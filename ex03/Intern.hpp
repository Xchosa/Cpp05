/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:31:14 by poverbec          #+#    #+#             */
/*   Updated: 2025/11/22 12:48:57 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <string>
#include <iostream>


class Intern
{

	public:
	Intern();
	~Intern();
	Intern(const Intern &object);
	Intern& operator=(const Intern &object);

	AForm* makeForm(const std::string &FromName, const std::string &TargetofForm);
};
