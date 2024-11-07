/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:49:46 by najeuneh          #+#    #+#             */
/*   Updated: 2024/11/05 17:43:56 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	parser(std::string str)
{
	if (str.empty())
		return (0);
	for (int i = 0; str[i]; i++)
	{
		if (isnumber(str[i]) == false)
			return (0);
	}
	if (stoi(str) > 7 && stoi(str) < 0)
		return 0;
	return 1;
}

void	ten_caracter(std::string str)
{
	if (str.length() > 10)
	{
		for (int i = 0; i < 9; i++)
			std::cout << str[i];
		std::cout << ".";
		std::cout << "|";
	}
	else
	{
		int lengt;
		lengt = str.length();
		while (lengt < 10)
		{
			std::cout << " ";
			lengt++;
		}
		std::cout << str;
		std::cout << "|";
	}
}

void	PhoneBook::Search(void)
{
	int	y = 0;
	std::cout << "     index|first name| last name|  nickname|\n";
	for (int i = 0; i < 8; i++)
	{
		if (this->contact[i].getfirstname().empty())
			break;
		std::cout << "         ";
		std::cout << y;
		std::cout << "|";
		ten_caracter(this->contact[i].getfirstname());
		ten_caracter(this->contact[i].getlastname());
		ten_caracter(this->contact[i].getnickname());
		std::cout << "\n";
		y++;
	}
	std::cout << "which contact ? : ";
	std::string str;
	while (parser(str) == 0)
	{
		std::getline(std::cin, str);
		if (parser(str) == 0)
			std::cout << "please pick a good number";
	}
	y = std::stoi(str);
	if (this->contact[y].getfirstname() == "")
		return ;
	std::cout << "First Name is   : ";
	std::cout << this->contact[y].getfirstname();
	std::cout << "\nLast Name is    : ";
	std::cout << this->contact[y].getlastname();
	std::cout << "\nNickName is     : ";
	std::cout << this->contact[y].getnickname();
	std::cout << "\nPhone Number is : ";
	std::cout << this->contact[y].getphonenumber();
	std::cout << "\nDark Secret is  : ";
	std::cout << this->contact[y].getdarksecret();
	std::cout << "\n";
}

void	PhoneBook::Add(void)
{
	int	i;

	i = g_count % 8;
	std::string	str;
	while (this->contact[i].getfirstname().empty())
	{
		std::cout << "First Name is   : ";
		std::getline(std::cin, str);
		this->contact[i].setfirstname(str);
	}
	
	while (this->contact[i].getlastname().empty())
	{
		std::cout << "Last Name is    : ";
		std::getline(std::cin, str);
		this->contact[i].setlastname(str);
	}
	while (this->contact[i].getnickname().empty())
	{
		std::cout << "NickName is     : ";
		std::getline(std::cin, str);
		this->contact[i].setnickname(str);
	}
	while (this->contact[i].getphonenumber().empty())
	{
		std::cout << "Phone Number is : ";
		std::getline(std::cin, str);
		this->contact[i].setphonenumber(str);
	}
	while (this->contact[i].getdarksecret().empty())
	{
		std::cout << "Dark Secret is  : ";
		std::getline(std::cin, str);
		this->contact[i].setdarksecret(str);
	}
	g_count++;
}

int	main(int ac, char **av)
{
	std::string	str;
	PhoneBook pb;
	int		result;
	int			i = 0;

	g_count = 0;
	while (1)
	{
		std::cout << "Command : ";
		std::getline(std::cin, str);
		if (std::cin.eof())
			break ;
		if (str == "ADD")		
		{
			pb.Add();
		}
		else if (str == "SEARCH")
			pb.Search();
		else if (str == "EXIT")
		{
			std::cout<< "EXIT\n";
			exit(0);
		}
	}
}
