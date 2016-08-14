#include "�Bank.h"



KURS::�Bank::�Bank()
{
	mAbout = std::make_shared<AboutBank>(AboutBank());
	AddUnit(CUnit(KURS::Currency::USD, 0.000, 0.000));
	AddUnit(CUnit(KURS::Currency::EUR, 0.000, 0.000));
	AddUnit(CUnit(KURS::Currency::RUB, 0.000, 0.000));
}

KURS::�Bank::�Bank(AboutBank& _ab)
{
	mAbout =std::make_shared<AboutBank>(AboutBank(_ab));
	AddUnit(CUnit(KURS::Currency::USD, 0.000, 0.000));
	AddUnit(CUnit(KURS::Currency::EUR, 0.000, 0.000));
	AddUnit(CUnit(KURS::Currency::RUB, 0.000, 0.000));
}

KURS::�Bank::�Bank(const �Bank & _copy)
{
	if (!mValuta.empty())
	{
		mValuta.clear();
	}
	for (auto iter = _copy.mValuta.begin(); iter != _copy.mValuta.end(); ++iter)
	{
		mValuta.push_back(std::make_shared<CUnit>(*(*iter)));
	}
	mAbout =std::make_shared<AboutBank>(AboutBank(*_copy.mAbout));
}

KURS::�Bank::�Bank(const �Bank && _copy)
{
}

KURS::�Bank::~�Bank()
{
}

KURS::�Bank & KURS::�Bank::operator=(const �Bank & _temp)
{
	if (!mValuta.empty())
	{
		mValuta.clear();
	}
	for (auto iter = _temp.mValuta.begin(); iter != _temp.mValuta.end(); ++iter)
	{
		mValuta.push_back(std::make_shared<CUnit>(*(*iter)));
	}
	mAbout = std::make_shared<AboutBank>(AboutBank(*_temp.mAbout));
	return *this;
}

KURS::TypeBuySell KURS::�Bank::GetUnitBuy(KURS::Currency _cur)
{
	for (auto &iter : mValuta)
	{
		if (iter->GetUnitValuta() == _cur)
		{
			return iter->GetBuyPrice();
		}
		else
		{
#ifdef _DEBUG
			std::cout << "�Bank::GetUnitBuy()->not have currency" << std::endl;
#endif
		}
	
	}
	return KURS::TypeBuySell{0};
}

KURS::TypeBuySell KURS::�Bank::GetUnitSell(KURS::Currency _cur)
{
	for (auto &iter : mValuta)
	{
		if (iter->GetUnitValuta() == _cur)
		{
			return iter->GetSellPrice();
		}
		else
		{
#ifdef _DEBUG
			std::cout << "�Bank::GetUnitSell()->not have currency" << std::endl;
#endif
		}
		
	}
	return KURS::TypeBuySell{ 0 };
}

void KURS::�Bank::SetUnitBuy(KURS::Currency _cur,KURS::TypeBuySell _buy)
{
	for (auto &iter : mValuta)
	{
		if (iter->GetUnitValuta() == _cur)
		{
			iter->SetBuyPrice(_buy);
		}
		else
		{
#ifdef _DEBUG
			std::cout << "�Bank::SetUnitBuy()->not have currency" << std::endl;
#endif
		}
	}
}

void KURS::�Bank::SetUnitSell(KURS::Currency _cur, KURS::TypeBuySell _sell)
{
	for (auto &iter : mValuta)
	{
		if (iter->GetUnitValuta() == _cur)
		{
			iter->SetBuyPrice(_sell);
		}
		else
		{
#ifdef _DEBUG
			std::cout << "CBank::SetUnitSell()->not have currency" << std::endl;
#endif
		}
	}
}

void KURS::�Bank::SetAbout(KURS::AboutBank & _ab)
{
	mAbout = std::make_shared<AboutBank>(AboutBank(_ab));
}

void KURS::�Bank::InitUnit(Iterator _begin, Iterator _end)
{
	if (!mValuta.empty())
	{
		mValuta.clear();
	}
	for (auto iter = _begin; iter != _end; ++iter)
	{
		mValuta.push_back(std::make_shared<CUnit>(*(*iter)));
	}
	
}

void KURS::�Bank::AddUnit(const CUnit & _temp)
{
	mValuta.push_back(std::make_shared<CUnit>(_temp));
}

void KURS::�Bank::DeleteUnit(KURS::Currency _cur)
{
	for (auto &iter : mValuta)
	{
		if (iter->GetUnitValuta() == _cur)
		{
			iter.reset();
			mValuta.remove(iter);
		}
	}
}

void KURS::�Bank::ClearUnit()
{
	mValuta.clear();
}

KURS::CUnit KURS::�Bank::GetUnit(KURS::Currency _cur)
{
	for (auto &iter : mValuta)
	{
		if (iter->GetUnitValuta() == _cur)
		{
			return *iter;
		}
	}
	return CUnit();  
}

void KURS::�Bank::PrintBank()
{
	std::cout <<"Name: "		<<mAbout->NameBank			<< std::endl;
	std::cout <<"WebSite: "		<<mAbout->WebSaite			<< std::endl;
	std::cout << "Email: "		<<mAbout->Email				<< std::endl;
	std::cout << "Adress: "		<< mAbout->Adress			<< std::endl;
	std::cout << "Tel.number: " << mAbout->TelephoneNumber	<< std::endl;
	std::cout << "Code(MFO): "  << mAbout->CodeMFO			<< std::endl;
	std::cout << "NBU License: "<< mAbout->NBULicense		<< std::endl;
	std::cout << "EGRPOU: "		<< mAbout->EGRPOU			<< std::endl;
	std::cout << "             Currencys: "<<std::endl;
	for (auto &iter : mValuta)
	{
		iter->PrintUnit();
	}
	std::cout << "##########################################################" << std::endl;
}

