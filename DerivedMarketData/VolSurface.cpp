
#include "VolSurface.h"
namespace DCQL
{

	void VolSurface::GenerateGrid(int maxMaturity, double maxStrike, double strikeStep, bool fillWithKnown = true)
	{
		int T = 0;
		int K = 0;
		while (T < maxMaturity)
		{
			m_expiries.push_back(T);
			T++;
		}

		while (K < maxStrike) // Has to be a better way of doing this.
		{
			m_strikes.push_back(K);
			K += strike_step;
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


	}

	void VolSurface::FillGrid(std::vector<std::vector<double>>& optionChainData)
	{

	}
	
}