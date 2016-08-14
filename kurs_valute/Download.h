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
	class CDownloadFile:public CFile										//����� ��� ������ ����� ����� http ��������
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
		void Request(std::string& _get, std::string& _host);	//������� ������
		unsigned int Response();								//������� ����������

		void SaveInFile();										//����������� ���� � ������ ������ � ����	
		std::string SaveInString();								//����������� ���� � ������ ������ � string

		void GenerateHostGet(std::string& _url);				//��������� ��������� ����� ��� boost

		std::string mHost;
		std::string mGet;
		boost::asio::ip::tcp::iostream mIOs;					//����� �������� � �������� ������/�����
		long mDurationConnect{ 60 };							//�������� ��������� ����������
	};
}