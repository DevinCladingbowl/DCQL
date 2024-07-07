
#include <vector>
#include <cmath>
#include "DiscountCurve.h"
#include "../Math/Interpolators/LinearInterpolator.h"
#include "../Tools/Tools.h"
namespace DCQL
{

	DiscountCurve::DiscountCurve(std::vector<double> maturities, std::vector<double> zeroRates, bool usingZeroRates) : m_maturities(maturities), m_zeroRates(zeroRates)
	{
		;
	}

	double DiscountCurve::GetDiscountFactor(double maturity) // maturity in days
	{
		return std::exp(-maturity * GetZeroRate(maturity) / 365.0);
	}

	double DiscountCurve::GetZeroRate(double maturity)
	{
		std::pair<int, int> indices = Tools::SurroundingIndices(m_maturities, maturity); // Find indices of maturities that are closest to maturity
		int i1 = indices.first;
		int i2 = indices.second;

		double m1 = m_maturities[i1];
		double m2 = m_maturities[i2];;

		double r1 = m_zeroRates[i1];
		double r2 = m_zeroRates[i2];

		double f = (maturity - m1) / (m2 - m1); // Interpolation fraction

		return LinearInterpolator::Interpolate(r1, r2, f);
	}
}