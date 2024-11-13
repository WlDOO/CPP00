/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:57:10 by najeuneh          #+#    #+#             */
/*   Updated: 2024/11/07 15:30:16 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string	Contact::getfirstname(void)
{
	return firstname;
}

std::string	Contact::getlastname(void)
{
	return lastname;
}

std::string	Contact::getnickname(void)
{
	return nickname;
}

std::string	Contact::getdarksecret(void)
{
	return darksecret;
}

std::string	Contact::getphonenumber(void)
{
	return phone_number;
}

bool	Contact::setfirstname(std::string str)
{
	if (str.empty())
		return false;
	for (int i = 0; str[i]; i++)
	{
		if (isalpha(str[i]) == false)
			return false;
	}
	firstname = str;
	return true; 
}

bool	Contact::setlastname(std::string str)
{
	if (str.empty())
		return false;
	for (int i = 0; str[i]; i++)
	{
		if (isalpha(str[i]) == false)
			return false;
	}
	lastname = str;
	return true; 
}

bool	Contact::setnickname(std::string str)
{
	if (str.empty())
		return false;
	for (int i = 0; str[i]; i++)
	{
		if (isalpha(str[i]) == false)
			return false;
	}
	nickname = str;
	return true;
}

bool Contact::setdarksecret(std::string str)
{
	if (str.empty())
		return false;
	darksecret = str;
	return true;
}

bool	Contact::setphonenumber(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (isalnum(str[i]) == false)
			return false;
	}
	phone_number = str;
	return true;
}