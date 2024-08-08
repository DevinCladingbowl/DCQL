#include <random>
#include <cmath>

#ifndef DISTRIBUTIONS_H
#define DISTRIBUTIONS_H

namespace DCQL
{	
	//TO DO: Make base class distributions and derived proper classes. e.g normal dist.
	class Distribitions
	{
	public:
		static double NormalCDF(double x, double mu, double sigma)
		{
			double z = (x - mu) / sigma;

			return 0.5 * (1 + std::erf(z / std::sqrt(2)));
		}

		static double StandardNormalCDF(double x)
		{
			return NormalCDF(x, 0.0, 1.0);
		}
	};
}

#endif