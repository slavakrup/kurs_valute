#pragma once
//#include <atltrace.h>
#include <iostream>
#include <tchar.h>
#include "Currencys.h"


namespace KURS
{
	using TypeBuySell = long double;

	class CUnit
	{
		
		TypeBuySell mBuy{ 0 };
		TypeBuySell mSell{ 0 };
		Currency mValuta{ Currency::UNW };

	public:
		CUnit();
		CUnit(const CUnit& _copy);
		CUnit(Currency _valuta, TypeBuySell _buy, TypeBuySell _sell);

		~CUnit();

		CUnit& operator=(const CUnit& _temp);
		bool operator > (CUnit const & _temp);
		bool operator < (CUnit const & _temp);
		bool operator == (CUnit const & _temp);

		void SetBuyPrice(TypeBuySell _buy);
		void SetSellPrice(TypeBuySell _sell);
		void SetUnitValuta(Currency& _valuta);

		Currency GetUnitValuta()const;
		long double GetBuyPrice()const;
		long double GetSellPrice()const;

#ifdef _DEBUG
		void PrintUnit();
#endif
	};

}