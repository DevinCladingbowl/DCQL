
#ifndef LINEARINTERPOLATOR_H
#define LINEARINTERPOLATOR_H

namespace DCQL
{
	class LinearInterpolator
	{
	public:
		//Interpolate  y(x) between x1 and x2
		static double Interpolate(const double& x, const double& x1, const double& x2, const double& y1, const double& y2)
		{
			if (x1 == x2) { return y1; }

			return y1 + (y2 - y1) * (x - x1) / (x2 - x1);
		}

		//Superior precision version given the fraction (x-x1)/(x2-x1)
		static double Interpolate(const double& y1, const double& y2, const double& f)
		{
			if (y1 == y2) { return y1; }

			return y1 * (1.0 - f) + y2 * f;
		}
	};
}

#endif // !LINEARINTERPOLATOR_H