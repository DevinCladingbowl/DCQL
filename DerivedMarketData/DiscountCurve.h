#include <vector>
#include <iostream>

#ifndef DISCOUNTCURVE_H
#define DISCOUNTCURVE_H

namespace DCQL
{
	class DiscountCurve
	{
	public:
	
		DiscountCurve(std::vector<double> maturities, std::vector<double> discountFactors);

		DiscountCurve(std::vector<double> maturities, std::vector<double> zeroRates, bool usingZeroRates);

		double GetDiscountFactor(double maturity);

		double GetZeroRate(double maturity);

		void SetLabel(std::string label) { m_assetLabel = label; }
		std::string GetLabel() { return m_assetLabel; }

	private:
		std::vector<double> m_maturities;
		std::vector<double> m_discountFactors;
		std::vector<double> m_zeroRates;
		std::string m_assetLabel;


	};
}

#endif 