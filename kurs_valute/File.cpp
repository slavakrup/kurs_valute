#include "File.h"

KURS::CFile::CFile()
{
}

KURS::CFile::~CFile()
{
}

void KURS::CFile::SetSaveFileName(std::string & _name)
{
	mSaveFileName = _name;
}

void KURS::CFile::SetOpenFileName(std::string & _name)
{
	mOpenFileName = _name;
}

std::string  KURS::CFile::OpenFile()
{
	if (!mOpenFileName.empty())
	{
		return OpenFile(mOpenFileName);
	}
	return std::string("empty file name");
}

std::string KURS::CFile::OpenFile(std::string & _name)
{
	std::string buffer;

	mFS.open(_name, std::ios::in | std::ios::binary);
	if (mFS.is_open())
	{
		std::getline(mFS, buffer, '\0');
	}
	mFS.close();
	return buffer;
}

void KURS::CFile::SaveFile(std::string & _data)
{
	if (!mSaveFileName.empty())
	{
		SaveFile(mSaveFileName, _data);
	}
}

void KURS::CFile::SaveFile(std::string & _name, std::string & _data)//data-have all file
{
	if (!_data.empty())
	{
		mFS.open(_name, std::ios::out | std::ios::binary);
		if (mFS.is_open())
		{
			mFS << _data;
		}
		mFS.close();
	}
	else
	{
#ifdef _DEBUG
		std::cout << "Function: CFile::SaveFile ->data is empty" << std::endl;
#endif
	}
}
