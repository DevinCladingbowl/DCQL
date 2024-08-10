#include "EqOption.h"
#include <iostream>
#include "../Pricers/Pricers.h"

namespace DCQL
{
	EqOption::EqOption(std::string equityName, ClaimType claimType, double spot, double strike, double maturity, double price) :
		m_equityName(equityName), m_claimType(claimType), m_spot(spot), m_strike(strike), m_maturity(maturity), m_price(price), m_usingImpliedVol(false)
	{
		;//implement implied vol from price.
	}

	EqOption::EqOption(std::string equityName, ClaimType claimType, double spot, double strike, double maturity, double impliedVol, bool usingImpliedVol) :
		m_equityName(equityName), m_claimType(claimType), m_spot(spot), m_strike(strike),m_maturity(maturity), m_impliedVol(impliedVol), m_usingImpliedVol(usingImpliedVol)
	{
		;//implement price from implied vol - need rates and stuff!
	}

	void EqOption::SetPrice(DiscountCurve& discountCurve)
	{
		if (discountCurve.GetLabel() != m_equityName)
		{
			std::cout << "The equity name does not match the asset label of the discount curve";
		}

		double rate = discountCurve.GetDiscountFactor(m_maturity);

		m_price = Pricers::BSPricer(m_spot, m_strike, m_maturity, rate, m_impliedVol);

	}
}

