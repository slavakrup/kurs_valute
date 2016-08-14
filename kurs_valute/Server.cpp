#include "Server.h"


KURS::FinanceServer::FinanceServer()
{
}

KURS::FinanceServer::FinanceServer(KURS::AboutServer _ab)
{
	mAboutServer = std::make_shared<AboutServer>(AboutServer(_ab));
}

KURS::FinanceServer::~FinanceServer()
{

}

void KURS::FinanceServer::InitServer()
{
	std::stringstream ss,ss2;
	std::string adress = "http://organizations.finance.ua/ru/-/ua/banks";
	std::string banks_regex = ("\"b - org - attribute_value\">  ([^<]+)");
	std::string bank_adress("normal-org\" href=\"([^\"]+)");
	std::string buffer;
	GenerateNameForFile();

	CDownloadFile df(std::string("page_banks.bank"));
	df.DownloadToFile(adress);									//скачал страницу со всеми банками
	CParsePage parse;

	buffer=parse.OpenFile(std::string("page_banks.bank"));	
	
	ss<<parse.SearchStringToString(buffer, bank_adress);

	std::string url_bank;

	while (std::getline(ss, buffer))
	{
		std::size_t found = buffer.find("info/");
		buffer.insert(found+5,"currency/");
		url_bank += buffer + "\n";
		ss2<<df.DownloadToString(url_bank);
		parse.SearchInStringToFile(ss2.str(), std::string("repka.bank"), banks_regex);
		ss2.str("");
	}
	

	std::cout << url_bank << std::endl;
	
}

void KURS::FinanceServer::SetAboutServer(AboutServer & _ab)
{
	mAboutServer = std::make_shared<AboutServer>(AboutServer(_ab));
}

void KURS::FinanceServer::AddBank(KURS::СBank & _bank)
{
	mBanks.push_back( std::make_shared<СBank>(KURS::СBank(_bank)));
}

void KURS::FinanceServer::DeleteBank(long long _codeMFO)
{
	for (auto &iter : mBanks)
	{
		if (iter->mAbout->CodeMFO == _codeMFO)
		{
			iter.reset();
			mBanks.remove(iter);
		}
		else
		{
#ifdef _DEBUG
			std::cout << "FinanceServer::DeleteBank()-> not have bank" << std::endl;
#endif
		}
	}
}

void KURS::FinanceServer::ClearBank()
{
	mBanks.clear();
}

KURS::СBank KURS::FinanceServer::GetBank(long long _codeMFO)
{
	for (auto &iter : mBanks)
	{
		if (iter->mAbout->CodeMFO == _codeMFO)
		{
			return *iter;
		}
		else
		{
#ifdef _DEBUG
			std::cout << "FinanceServer::GetBank()-> not have bank" << std::endl;
#endif
		}
	}
	return KURS::СBank();
}

void KURS::FinanceServer::GenerateNameForFile()
{
	std::stringstream ss;
	for (int i = 0; i < mNumberOfBank; i++)
	{
		ss << "bank_"<<i;
		mArrayNameNumber[i] = std::make_shared<std::string>(ss.str());
		std::stringstream().swap(ss);	//очищаю поток через конструктор перемещения
	}
}

