
#ifndef LINEARINTERPOLATOR_H
#define LINEARINTERPOLATOR_H

namespace DCQL
{
	class LinearInterpolator
	{
	public:
		//Interpolate to y(x) between x1 and x2
		static double Interpolate(double x, double x1, double x2, double y1, double y2)
		{
			if (x1 == x2) { return y1; }

			return y1 + (y2 - y1) * (x - x1) / (x2 - x1);
		}

		//Superior precision version given the fraction (x-x1)/(x2-x1)
		static double Interpolate(double y1, double y2, double f)
		{
			if (y1 == y2) { return y1; }

			return y1 * (1.0 - f) + y2 * f;
		}
	};
}

#endif // !LINEARINTERPOLATOR_H