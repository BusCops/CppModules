#include "PhoneBook.hpp"

void PhoneBook::UpdateIndex()
{
	if (index < 7)
		index++;
	else
		index = 0;
}

void PhoneBook::SetIndex(int i)
{
	index = i;
}

bool VerifyInfo(std::string &info)
{
	int i = 0;
	int c = 0;

	while (info[i])
	{
		if (info[i] == '\t')
			info[i] = ' ';
		if (info[i] < 32 || info[i] == 127)
			return false;
		if (info[i] > 32 && info[i] < 127 && i < 10)
			c = 1;
		i++;
	}
	if (c == 0)
		return false;
	return true;
}

std::string GetInfo()
{
	std::string info;

	while (true)
	{
		if (!getline(std::cin, info))
			break;
		if (!info.empty() && VerifyInfo(info))
			break;
		else
			std::cout << "Please enter a valid information" << std::endl;
	}
	return info;
}

bool PrintMsg(std::string msg)
{
	if (std::cin.eof())
		return false;
	std::cout << msg << std::endl;
	return true;
}

void PhoneBook::AddContat()
{
	UpdateIndex();
	if (PrintMsg("enter first name :"))
		contact[index].SetFirstName(GetInfo());
	if (PrintMsg("enter last name :"))
		contact[index].SetLastName(GetInfo());
	if (PrintMsg("enter nick name :"))
		contact[index].SetNickName(GetInfo());
	if (PrintMsg("enter phone number :"))
		contact[index].SetPhoneNumber(GetInfo());
	if (PrintMsg("enter darkest secret :"))
		contact[index].SetDarkestSecret(GetInfo());
	PrintMsg("Your contact has been added successfully");
}

void PrintArrayHead()
{
	PrintMsg("---------------------------------------------");
	PrintMsg("|  index   |first name|last name | nickname |");
	PrintMsg("---------------------------------------------");
}

void PrintRowInfo(std::string info)
{
	std::cout << "|";
	if (info.length() > 10)
		std::cout << info.substr(0, 9) + ".";
	else
		std::cout << std::setw(10) << std::right << info;
}

void PhoneBook::SearchContact()
{
	int i = 0;
	std::string in;

	if (index == -1)
	{
		PrintMsg("No contact added yet");
		return;
	}
	PrintArrayHead();
	while (i < 8 && !contact[i].GetFirstName().empty())
	{
		std::cout << "|         " << i;
		PrintRowInfo(contact[i].GetFirstName());
		PrintRowInfo(contact[i].GetLastName());
		PrintRowInfo(contact[i].GetNickName());
		std::cout << "|" << std::endl;
		i++;
	}
	PrintMsg("---------------------------------------------");
	PrintMsg("Enter the index of the contact you’re looking for:");
	while (true)
	{
		if (!getline(std::cin, in))
			return;
		if (in.length() == 1 && isdigit(in[0]))
		{
			i = atoi(in.c_str());
			break;
		}
		PrintMsg("please enter a valid index from 0 to 7");
	}
	if (i > 7 || contact[i].GetFirstName().empty())
	{
		PrintMsg("there is no contact with this index!");
		return;
	}
	PrintArrayHead();
	std::cout << "|         " << i;
	PrintRowInfo(contact[i].GetFirstName());
	PrintRowInfo(contact[i].GetLastName());
	PrintRowInfo(contact[i].GetNickName());
	std::cout << "|" << std::endl;
	PrintMsg("---------------------------------------------");
}