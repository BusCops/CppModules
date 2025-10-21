#include "Replace.hpp"

Replace::Replace(std::string &string1, std::string &string2, std::string &file)
	: s1(string1), s2(string2), file(file)
{
}

void Replace::ReplaceStrings()
{
	std::ifstream file(this->file.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error opening file" << std::endl;
		return;
	}
	std::ofstream newfile((this->file + ".replace").c_str());
	if (!newfile.is_open())
	{
		std::cerr << "Error creating file" << std::endl;
		file.close();
		return;
	}
	std::stringstream buffer;
	buffer << file.rdbuf();
	size_t pos;
	std::string content;
	content = buffer.str();
	pos = content.find(s1);
	while (pos != std::string::npos)
	{
		content.erase(pos, s1.length());
		content.insert(pos, s2);
		pos = content.find(s1, pos + s2.length());
	}
	newfile << content << std::endl;
	file.close();
	newfile.close();
}
