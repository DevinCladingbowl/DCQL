#include <cmath>

#ifndef BSPRICER_H
#define BSPRICER_H

namespace DCQL
{
	class Pricers
	{
		//Collection of static simple pricers
	public:
		static double BSPricer(double spot, double strike, double maturity, double rate, double vol) //make it return forward instead - more accurate(?)
		{
			double d1 = std::log(spot / strike) + (rate + vol * vol / 2) * maturity;
			d1 /= vol * std::sqrt(maturity);
			
			double d2 = d1 - vol * maturity;

		}

	};
}
#endif // BSPRICER_H