#pragma once


#include "File.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <string>



namespace KURS
{
	class CParsePage:public CFile
	{
	public:
		CParsePage();
		~CParsePage();	

		void SearchInFileToFile(std::string& _nameOpenFile, std::string& _nameSaveFile,
			std::string& _regex);
		void SearchInStringToFile(std::string& _searchString, std::string& _nameSaveFile,
			std::string& _regex);
		std::string SearchStringToString(std::string& _searchString, std::string& _regex);

	private:
		std::ostringstream mOSS;
		std::string mBuffer;
		std::regex mRegex;					//регул€рное выражение
	};
}