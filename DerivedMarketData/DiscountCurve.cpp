#include <vector>
#include "../Math/Interpolators/LinearInterpolator.h"

namespace DCQL
{

	double GetDiscountFactor(double& maturity)
	{
		std::pair<int, int> x = { 1, 1 }; //Place holder until implemented way to get nearest discount factors to the maturity

		return LinearInterpolator::Interpolate()
	}
}