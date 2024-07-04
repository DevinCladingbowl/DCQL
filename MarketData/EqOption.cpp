#include "EqOption.h"

namespace DCQL
{
	EqOption::EqOption(std::string equityName, EqOption::ClaimType claimType, double price) :
		m_equityName(equityName), m_claimType(claimType), m_price(price), m_usingImpliedVol(false)
	{
		; //implement implied vol from price.
	}

	EqOption::EqOption(std::string equityName, EqOption::ClaimType claimType, double impliedVol, bool usingImpliedVol) :
		m_equityName(equityName), m_claimType(claimType), m_impliedVol(m_impliedVol), m_usingImpliedVol(usingImpliedVol)
	{
		; //implement price from implied vol - need rates and stuff!
	}
}

