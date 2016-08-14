#pragma once
#include <iostream>
#include "ÑBank.h"
#include "Download.h"
#include "Parser.h"
#include <string>
#include <array>
#include <list>
#include <memory>
#include <sstream>


namespace KURS
{
	class IServer
	{
	public:
		IServer(){};
		virtual ~IServer(){};

		virtual  void InitServer() {};

		
		
	private:
		virtual void GenerateNameForFile() {};
		bool IsActive;
	};

	using AboutServer = KURS::AboutBank;

	class FinanceServer:public IServer
	{
	public:
		using PointString = std::shared_ptr<std::string>;
		using pCBank = std::shared_ptr<KURS::ÑBank>;
		using AboutServer = KURS::AboutBank;
		FinanceServer();
		FinanceServer(AboutServer _ab);
		~FinanceServer();
	
		void InitServer()override;
	
		std::shared_ptr<AboutServer> mAboutServer;
		void SetAboutServer(AboutServer& _ab);

		void AddBank(KURS::ÑBank& _bank);
		void AddBank(const KURS::ÑBank& _bank);
		void DeleteBank(long long _codeMFO);
		void ClearBank();
		KURS::ÑBank GetBank(long long _codeMFO);

	private:

		std::list<pCBank> mBanks;
		void GenerateNameForFile()override;

		const static int mNumberOfBank{200};
		std::array<PointString, 200> mArrayNameNumber;
	 };
}