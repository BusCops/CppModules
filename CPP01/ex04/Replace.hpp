#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>

class Replace
{
	private:
		std::string s1;
		std::string s2;
		std::string file;
	public:
		Replace(std::string &string1, std::string &string2, std::string &file);
		void	ReplaceStrings();
};

#endif