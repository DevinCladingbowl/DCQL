
#include <iostream>
#include "MarketData.h"
#include "../DerivedMarketData/DiscountCurve.h"

#ifndef EQOPTION_H
#define EQOPTION_H

namespace DCQL
{
	// We treat equity options as market data that we can process them into e.g vol surfaces.
	class EqOption : MarketData
	{
	public:

		enum ClaimType
		{
			Call = 0,
			Put = 1
		};
		
		std::string GetMarketDataType() override { return "EqOption"; }

		// using option price
		EqOption(std::string equityName, ClaimType claimType, double spot, double strike, double price);

		// using implied vol of option
		EqOption(std::string equityName, ClaimType claimType, double spot, double strike, double impliedVol, bool usingImpliedVol);

		std::string GetEquityName() { return m_equityName; }
		ClaimType GetClaimType() { return m_claimType; }

		double GetImpliedVol() { return m_impliedVol; }
		double GetPrice() { return m_price; }
		void SetPrice(DiscountCurve& discountCurve);
		bool UsingImpliedVol() { return m_usingImpliedVol; }

		double GetMaturity() { return m_maturity; }
		double GetSpot() { return m_spot; }
		double GetStrike() { return m_strike; }


	private:
		std::string m_equityName;
		ClaimType m_claimType;
		double m_impliedVol;
		double m_price;
		double m_maturity;
		bool m_usingImpliedVol;
		double m_spot; // Until we are more sophistiated we need spot here.
		double m_strike;
		//Date m_maturity   	//TO DO: Add Date class to have proper maturities
	};
}

#endif // !EQOPTION