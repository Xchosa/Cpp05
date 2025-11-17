/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:07:00 by poverbec          #+#    #+#             */
/*   Updated: 2025/11/17 12:21:20 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
	protected:
	std::string const name;
	int grade;

	public:
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat& operator=(Bureaucrat const object);
	
};

#endif