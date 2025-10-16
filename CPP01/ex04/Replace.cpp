#include "Replace.hpp"

Replace::Replace(std::string &string1, std::string &string2, std::string &file):
	s1(string1),
	s2(string2),
	file(file)
{
}

void	Replace::ReplaceStrings()
{
	std::ifstream file(this->file.c_str());
	if (file.fail())
	{
		std::cerr << "Error opening file" << std::endl;
		return ;
	}
	std::ofstream newfile("newfile");
	if (!newfile.is_open())
	{
		std::cerr << "Error creating file" << std::endl;
		file.close();
		return ;
	}
	size_t pos;
	std::string	line;
	while (getline(file, line))
	{
		pos = line.find(s1);
		while(pos != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos = line.find(s1, pos + s2.length());
		}
		newfile << line << std::endl;
	}
	file.close();
	newfile.close();
}
