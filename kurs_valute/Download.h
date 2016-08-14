#pragma once
#include "File.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <boost/asio/ip/tcp.hpp>

using namespace boost;


namespace KURS
{
	class CDownloadFile:public CFile										//класс для скачки файла через http протокол
	{
	public:
		CDownloadFile();
		CDownloadFile(const CDownloadFile& copy);
		CDownloadFile(std::string& _nameFileSave);
		~CDownloadFile();
		
		void DownloadToFile(std::string& _urlToFile);
		std::string DownloadToString(std::string& _urlToFile);
			
#ifdef _DEBUG
		
#endif

	private:
		unsigned int Download(std::string& _urlToFile);
		void Request(std::string& _get, std::string& _host);	//послать запрос
		unsigned int Response();								//принять обработать

		void SaveInFile();										//скопировать файл с буфера потока в файл	
		std::string SaveInString();								//скопировать файл с буфера потока в string

		void GenerateHostGet(std::string& _url);				//генерация коректной сылки для boost

		std::string mHost;
		std::string mGet;
		boost::asio::ip::tcp::iostream mIOs;					//поток принятия и отправки запрос/ответ
		long mDurationConnect{ 60 };							//интервал открытого соединения
	};
}