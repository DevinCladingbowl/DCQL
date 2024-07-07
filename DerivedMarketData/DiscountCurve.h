#include <vector>

// discount curve class
// we use piece constant on the log scale(?)

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

	private:
		std::vector<double> m_maturities;
		std::vector<double> m_discountFactors;
		std::vector<double> m_zeroRates;


	};
}

#endif 