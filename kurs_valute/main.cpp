#include "Unit.h"

#include "Currencys.h"
#include"Download.h"
#include "ÑBank.h"
#include "Parser.h"
#include "Server.h"
#include <sstream>
//#define _UNICODE

using namespace KURS;
//using boost::asio::ip::tcp;
std::string adress("http://organizations.finance.ua/ru/-/ua/banks");
std::string bank_adress("normal-org\" href=\"([^\"]+)");


int main()
{
	KURS::FinanceServer serv;
	serv.InitServer();
	KURS::ÑBank b;
	b.PrintBank();

	return 0;
}