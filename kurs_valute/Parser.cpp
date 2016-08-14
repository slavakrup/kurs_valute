#include "Parser.h"

KURS::CParsePage::CParsePage()
{
}

KURS::CParsePage::~CParsePage()
{
}

void KURS::CParsePage::SearchInFileToFile(std::string & _nameOpenFile, std::string & _nameSaveFile, 
	std::string & _regex)
{
	mBuffer=OpenFile(_nameOpenFile);


	mRegex = std::regex(_regex);

	
	std::regex_iterator<std::string::iterator> iterBegin(mBuffer.begin(), mBuffer.end(), mRegex);
	std::regex_iterator<std::string::iterator> iterEnd;

	while (iterBegin != iterEnd)
	{
		mOSS << iterBegin->str(1) << std::endl;
		++iterBegin;
	}
	SaveFile(_nameSaveFile, mOSS.str());
}

void KURS::CParsePage::SearchInStringToFile(std::string & _searchString, std::string & _nameSaveFile,
	std::string & _regex)
{
	mRegex = std::regex(_regex);

	std::regex_iterator<std::string::iterator> iterBegin(_searchString.begin(),
		_searchString.end(), mRegex);
	std::regex_iterator<std::string::iterator> iterEnd;

	while (iterBegin != iterEnd)
	{
		mOSS << iterBegin->str(1) << std::endl;
		++iterBegin;
	}
	SaveFile(_nameSaveFile, mOSS.str());
}


std::string  KURS::CParsePage::SearchStringToString(std::string & _searchString, std::string & _regex)
{
	mRegex = std::regex(_regex);

	std::regex_iterator<std::string::iterator> iterBegin(_searchString.begin(),
		_searchString.end(), mRegex);
	std::regex_iterator<std::string::iterator> iterEnd;

	while (iterBegin != iterEnd)
	{
		for (int i = 1; i < iterBegin->size(); i++)
		{
			mOSS << iterBegin->str(i) << std::endl;
		}
		++iterBegin;
	}
	return mOSS.str();
}
