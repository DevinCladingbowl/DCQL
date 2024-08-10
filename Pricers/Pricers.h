#include <cmath>
#include <random>
#include "../Math/Probability/Distributions.h"

#ifndef PRICERS_H
#define PRICERS_H

namespace DCQL
{
	class Pricers
	{
		//Collection of static simple pricers
	public:
		static double BSPricer(double spot, double strike, double maturity, double rate, double vol) //make it return forward instead - more accurate(?)
		{
			maturity /= 365.0;
			double d1 = std::log(spot / strike) + (rate + vol * vol / 2) * maturity;
			d1 /= vol * std::sqrt(maturity);
			
			double d2 = d1 - vol * maturity;

			double N1 = Distribitions::StandardNormalCDF(d1);
			double N2 = Distribitions::StandardNormalCDF(d2);

			return spot * N1 - strike * std::exp(-rate * maturity) * N2;

		}

	};
}
#endif // PRICERS_H