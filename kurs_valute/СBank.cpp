#include "ÑBank.h"



KURS::ÑBank::ÑBank()
{
	mAbout = std::make_shared<AboutBank>(AboutBank());
	AddUnit(CUnit(KURS::Currency::USD, 0.000, 0.000));
	AddUnit(CUnit(KURS::Currency::EUR, 0.000, 0.000));
	AddUnit(CUnit(KURS::Currency::RUB, 0.000, 0.000));
}

KURS::ÑBank::ÑBank(AboutBank& _ab)
{
	mAbout =std::make_shared<AboutBank>(AboutBank(_ab));
	AddUnit(CUnit(KURS::Currency::USD, 0.000, 0.000));
	AddUnit(CUnit(KURS::Currency::EUR, 0.000, 0.000));
	AddUnit(CUnit(KURS::Currency::RUB, 0.000, 0.000));
}

KURS::ÑBank::ÑBank(const ÑBank & _copy)
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

KURS::ÑBank::ÑBank(const ÑBank && _copy)
{
}

KURS::ÑBank::~ÑBank()
{
}

KURS::ÑBank & KURS::ÑBank::operator=(const ÑBank & _temp)
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

KURS::TypeBuySell KURS::ÑBank::GetUnitBuy(KURS::Currency _cur)
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
			std::cout << "ÑBank::GetUnitBuy()->not have currency" << std::endl;
#endif
		}
	
	}
	return KURS::TypeBuySell{0};
}

KURS::TypeBuySell KURS::ÑBank::GetUnitSell(KURS::Currency _cur)
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
			std::cout << "ÑBank::GetUnitSell()->not have currency" << std::endl;
#endif
		}
		
	}
	return KURS::TypeBuySell{ 0 };
}

void KURS::ÑBank::SetUnitBuy(KURS::Currency _cur,KURS::TypeBuySell _buy)
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
			std::cout << "ÑBank::SetUnitBuy()->not have currency" << std::endl;
#endif
		}
	}
}

void KURS::ÑBank::SetUnitSell(KURS::Currency _cur, KURS::TypeBuySell _sell)
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

void KURS::ÑBank::SetAbout(KURS::AboutBank & _ab)
{
	mAbout = std::make_shared<AboutBank>(AboutBank(_ab));
}

void KURS::ÑBank::InitUnit(Iterator _begin, Iterator _end)
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

void KURS::ÑBank::AddUnit(const CUnit & _temp)
{
	mValuta.push_back(std::make_shared<CUnit>(_temp));
}

void KURS::ÑBank::DeleteUnit(KURS::Currency _cur)
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

void KURS::ÑBank::ClearUnit()
{
	mValuta.clear();
}

KURS::CUnit KURS::ÑBank::GetUnit(KURS::Currency _cur)
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

void KURS::ÑBank::PrintBank()
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

