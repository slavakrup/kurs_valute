#include "Unit.h"


using namespace KURS;

CUnit::CUnit()
{
}

CUnit::CUnit(const CUnit & _copy)
{
	this->mBuy = _copy.mBuy;
	this->mSell = _copy.mSell;
	this->mValuta = _copy.mValuta;
}

CUnit::CUnit(Currency _valuta, TypeBuySell _buy, TypeBuySell _sell)
{
	this->mBuy = _buy;
	this->mSell = _sell;
	this->mValuta = _valuta;
}

CUnit::~CUnit()
{
/*#ifdef _DEBUG
	std::wcout << _T("Call Distructor Unit:") << this<<_T("/") << 
		static_cast<typename std::underlying_type<Currency>::type>(this->mValuta) << std::endl;
#endif*/
}

CUnit & CUnit::operator=(const CUnit & _temp)
{
	this->mBuy = _temp.mBuy;
	this->mSell = _temp.mSell;
	this->mValuta = _temp.mValuta;
	return *this;
}

bool CUnit::operator>(CUnit const & _temp)
{
	if (mBuy > _temp.mBuy || mSell > _temp.mSell)return true;
	return false;
}

bool CUnit::operator<(CUnit const & _temp)
{
	if (mBuy < _temp.mBuy || mSell < _temp.mSell)return true;
	return false;
}

bool CUnit::operator==(CUnit const & _temp)
{
	if (mBuy ==_temp.mBuy || mSell ==_temp.mSell)return true;
	return false;
}

void CUnit::SetBuyPrice(TypeBuySell _buy)
{
	if (_buy < 0)this->mBuy = 0;
	this->mBuy = _buy;
}

void CUnit::SetSellPrice(TypeBuySell _sell)
{
	if (_sell < 0)this->mSell = 0;
	this->mSell = _sell;
}

void CUnit::SetUnitValuta(Currency& _valuta)
{
	this->mValuta = _valuta;
}


Currency KURS::CUnit::GetUnitValuta() const
{
	return mValuta;
}

long double CUnit::GetBuyPrice() const
{
	return this->mBuy;
}

long double CUnit::GetSellPrice() const
{
	return this->mSell;
}
#ifdef _DEBUG

void CUnit::PrintUnit()
{
	std::wcout << _T("Valuta->") << this << _T(" code: ") << 
		static_cast<typename std::underlying_type<Currency>::type>(this->mValuta)
		<< _T("/ Buy: ") <<
		this->mBuy << _T("/ Sell: ") <<this->mSell<< std::endl;
}
#endif 