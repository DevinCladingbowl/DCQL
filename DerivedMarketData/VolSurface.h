
#include <iostream>
#include "../MarketData/OptionChain.h"

#ifndef VOLSURFACE_H
#define VOLSURFACE_H

/*
Plan:
Class that, given an option chain (list of options with differing expiries etc.) can call functions to get the IV for a given (K,T). Also make it so can generate a vol surface on a given grid.

To consider:
	- Using moneyness everywhere?
	- Better matrix class as std::array isn't the best for run time dimension
*/
namespace DCQL
{
	class VolSurface
	{
	public:

		enum fittingMethod
		{
			// TO DO
		};
		
		VolSurface(std::string assetName, OptionChain optionChain);

		void FitVolSurface(std::string fittingMethod); //Function to take the option chain data and fit a vol surface using a given fitting type.

		void GenerateGrid(int maxMaturity, double maxStrike, double strikeStep)
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
			int dim2 = m_expiries.size();
		}

	
	protected:

		void DecomposeOptionGrid()
		{
			for each(EqOption option in m_optionChain.GetOptions())
			{
				double K = option.GetStrike();
				double T = option.GetMaturity();
				double vol = option.GetImpliedVol();
			}
			
		}

	private:
		std::string m_assetName;
		OptionChain m_optionChain;
		std::vector<double> m_strikes;
		std::vector<double> m_expiries;
		std::array<double, 2> impliedVolSurface;

	};
}

#endif