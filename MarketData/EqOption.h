
#include <iostream>
#include "MarketData.h"

namespace DCQL
{
	class EqOption : MarketData
	{
	public:

		enum ClaimType
		{
			Call = 0,
			Put = 1
		};

		// using option price
		EqOption(std::string equityName, ClaimType claimType, double price);

		// using implied vol of option
		EqOption(std::string equityName, ClaimType claimType, double impliedVol, bool usingImpliedVol);

		std::string GetEquityName() { return m_equityName; }
		ClaimType GetClaimType() { return m_claimType; }

		double GetImpliedVol() { return m_impliedVol; }
		double GetPrice() { return m_price; }
		bool UsingImpliedVol() { return m_usingImpliedVol; }

		double GetTimeToMaturity() { return m_timeToMaturity; }


	private:
		std::string m_equityName;
		ClaimType m_claimType;
		double m_impliedVol;
		double m_price;
		double m_timeToMaturity;
		bool m_usingImpliedVol;
		//Date m_maturity   	//TO DO: Add Date class to have proper maturities
	};
}