#pragma once

#include <iostream>
#include <fstream>
#include <string>


namespace KURS
{
	class CFile
	{
	public:
		CFile();
		~CFile();

		void SetSaveFileName(std::string& _name);
		void SetOpenFileName(std::string& _name);

		std::string OpenFile();
		std::string OpenFile(std::string& _name);
		void SaveFile(std::string& _data);
		void SaveFile(std::string& _name, std::string& _data);

	private:
		std::fstream mFS;
		std::string mSaveFileName;
		std::string mOpenFileName;
	};
}
