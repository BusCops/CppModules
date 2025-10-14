#include "Contact.hpp"

void Contact :: SetFirstName(std :: string name)
{
	FirstName = name;
}

void Contact :: SetLastName(std :: string name)
{
	LastName = name;
}

void Contact :: SetNickName(std :: string name)
{
	NickName = name;
}

void Contact :: SetPhoneNumber(std :: string PNumber)
{
	PhoneNumber = PNumber;
}

void Contact :: SetDarkestSecret(std :: string DSecret)
{
	DarkestSecret = DSecret;
}

std :: string Contact :: GetFirstName()
{
	return FirstName;
}

std :: string Contact :: GetLastName()
{
	return LastName;
}

std :: string Contact :: GetNickName()
{
	return NickName;
}

std :: string Contact :: GetPhoneNumber()
{
	return PhoneNumber;
}

std :: string Contact :: GetDarkestSecret()
{
	return DarkestSecret;
}
