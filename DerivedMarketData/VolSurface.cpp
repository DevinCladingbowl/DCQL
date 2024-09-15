
#include "VolSurface.h"
namespace DCQL
{

	void VolSurface::GenerateGrid(int maxMaturity, double maxStrike, double strikeStep, bool fillWithKnown)
	{
		int T = 0;
		double K = 0;
		while (T < maxMaturity)
		{
			m_expiries.push_back(T);
			T++;
		}

		while (K < maxStrike) // Has to be a better way of doing this.
		{
			m_strikes.push_back(K);
			K += strikeStep;
		}


		int dim1 = m_strikes.size();
		m_numberOfStrikes = dim1;
		int dim2 = m_expiries.size();

		std::vector<std::vector<double>> volSurfaceGrid(dim1, std::vector<double>(dim2)); //2d array of zeroes


		if (!fillWithKnown)
		{
			m_impliedVolSurface = volSurfaceGrid;
			return;  //Premature exit if we aren't filling the grid with known values
		}

		std::vector<std::vector<double>> optionChainData = DecomposeOptionChain(); // (K,T,vol)

		for (std::vector<double> vec : optionChainData)
		{
			double K = vec[0];
			double T = vec[1];
			double vol = vec[2];

			volSurfaceGrid[StrikeValueToIndex(K, strikeStep)][T] = vol;
		}

		m_impliedVolSurface = volSurfaceGrid;

	}

	
}