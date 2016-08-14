#include "Download.h"




KURS::CDownloadFile::CDownloadFile():CFile()
{
}

KURS::CDownloadFile::CDownloadFile(const CDownloadFile & copy)
{
}

KURS::CDownloadFile::CDownloadFile(std::string & _nameFileSave):CFile()
{
	SetSaveFileName(_nameFileSave);
}

KURS::CDownloadFile::~CDownloadFile()
{
}

void KURS::CDownloadFile::DownloadToFile(std::string& _urlToFile)
{
	auto status = Download(_urlToFile);
	if (status == 200U)
	{
		SaveInFile();
	}
	else
	{
#ifdef _DEBUG
		std::cout << "Response returned with status code " << status << std::endl;
#endif // _DEBUG
	}
}

std::string KURS::CDownloadFile::DownloadToString(std::string & _urlToFile)
{
	auto status = Download(_urlToFile);
	if (status == 200U)
	{
		return SaveInString();
	}
	else
	{
#ifdef _DEBUG
		std::cout << "Response returned with status code " << status << std::endl;
#endif // _DEBUG
	}
	return std::string("error");
}


unsigned int KURS::CDownloadFile::Download(std::string & _urlToFile)
{
	GenerateHostGet(_urlToFile);
#ifdef _DEBUG
	std::cout << "Host in: " << mHost << "  " << "Patch in: " << mGet << std::endl;
#endif

	this->Request(mHost, mGet);
	return Response();//получаем код от сервера
	
}

void KURS::CDownloadFile::Request(std::string & _host, std::string & _get)//отправка http запроса
{
	
	this->mIOs.expires_from_now(boost::posix_time::seconds(mDurationConnect));

	mIOs.connect(_host,"http");
	if (!mIOs)
	{
#ifdef _DEBUG
		std::cout << "unable to connect:" << mIOs.error().message() << std::endl;
#endif
		return;
	}
	mIOs << "GET " << _get << " HTTP/1.0\r\n";
	mIOs << "Host: " << _host << "\r\n";
	mIOs << "Accept: */*\r\n";
	mIOs << "Connection: close\r\n\r\n";
#ifdef _DEBUG
	std::cout << "server<- " << _get << " : " << _host << std::endl;
#endif
}

unsigned int KURS::CDownloadFile::Response()//считуем ответ
{
	std::string http_version;
	mIOs >> http_version;
	unsigned int status_code;
	mIOs >> status_code;
	std::string status_message;
	std::getline(mIOs, status_message);
	if (!mIOs || http_version.substr(0, 5) != "HTTP/")
	{
		return 666U;
	}
#ifdef _DEBUG
	std::cout <<"server->"<< status_code<<":"<<status_message<<std::endl;
#endif
	return status_code;
}

void KURS::CDownloadFile::SaveInFile()
{
	std::string header;
	while (std::getline(mIOs, header) && header != "\r") {}//std::cout << header << std::endl;

	std::getline(mIOs, header, '\0');
	SaveFile(header);

	mIOs.clear();
	
}

std::string KURS::CDownloadFile::SaveInString()
{
	std::string header;
	while (std::getline(mIOs, header) && header != "\r") {}//std::cout << header << std::endl;

	std::getline(mIOs, header, '\0');
	mIOs.clear();
	mIOs.close();
	return header;

}

void KURS::CDownloadFile::GenerateHostGet(std::string & _url)
{
	if (_url.compare(0, 8, "https://") == 0)//delete https:// from link
	{
		_url = _url.substr(8);
	}
	if (_url.compare(0, 7, "http://") == 0)//delete http:// from link
	{
		_url = _url.substr(7);
	}

	std::size_t found = _url.find_first_of("/");
	if (found != std::string::npos)
	{
		mHost = _url.substr(0, found);
		mGet = _url.substr(found);
		std::cout << "in generate:" << mHost << " " << mGet << std::endl;
	}
	else
	{
#ifdef _DEBUG
		std::cout << "CDownload::GenerateHostGet->bad url link" << std::endl;
#endif // _DEBUG
	}
}



