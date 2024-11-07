/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:39:58 by najeuneh          #+#    #+#             */
/*   Updated: 2024/11/05 14:56:54 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact	{
	private :
		std::string	contact;
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	darksecret;
		std::string phone_number;
	public :
		std::string	getfirstname(void);
		std::string	getlastname(void);
		std::string	getnickname(void);
		std::string	getdarksecret(void);
		std::string	getphonenumber(void);
		bool		setfirstname(std::string str);
		bool		setlastname(std::string str);
		bool		setnickname(std::string str);
		bool		setdarksecret(std::string str);
		bool		setphonenumber(std::string str);
};

#endif