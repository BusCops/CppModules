#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{

private:
	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string PhoneNumber;
	std::string DarkestSecret;

public:
	void SetFirstName(std::string name);
	void SetLastName(std::string name);
	void SetNickName(std::string name);
	void SetPhoneNumber(std::string PNumber);
	void SetDarkestSecret(std::string DSecret);
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetNickName();
	std::string GetPhoneNumber();
	std::string GetDarkestSecret();
};

#endif