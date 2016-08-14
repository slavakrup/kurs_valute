#pragma once
#include"Currencys.h"
#include "Unit.h"

#include <string>
#include <tchar.h>
#include <memory>
#include <list>

namespace KURS
{
	struct AboutBank
	{
		std::string NameBank;
		std::string Adress;
		std::string WebSaite;
		std::string TelephoneNumber;
		std::string Email;
		std::string NBULicense;
		long long CodeMFO;
		long long EGRPOU;
		std::string Reserve;
	};

	class �Bank
	{
	public:
		using pCUnit = std::shared_ptr<CUnit>;
		using Iterator = std::list<pCUnit>::iterator;

		�Bank();
		�Bank(AboutBank& _ab);
		�Bank(const �Bank& _copy);
		�Bank(const �Bank&& _copy);
		~�Bank();
		
		�Bank& operator=(const �Bank& _temp);

		KURS::TypeBuySell GetUnitBuy(KURS::Currency _cur);
		KURS::TypeBuySell GetUnitSell(KURS::Currency _cur);
		void SetUnitBuy(KURS::Currency _cur, KURS::TypeBuySell _buy);
		void SetUnitSell(KURS::Currency _cur, KURS::TypeBuySell _sell);
		void SetAbout(KURS::AboutBank& _ab);

		void InitUnit(Iterator _begin,Iterator _end);
		void AddUnit(const CUnit& _temp);
		void AddUnit(CUnit& _temp);
		void DeleteUnit(KURS::Currency _cur);
		void ClearUnit();
		CUnit GetUnit(KURS::Currency _cur);
		
		std::shared_ptr<AboutBank> mAbout;          //���������-��������� � �����
#ifdef _DEBUG
		void PrintBank();
#endif
	private:

		std::list<pCUnit> mValuta;
	};
}