
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
		
//		VolSurface() { ; }
		VolSurface(std::string assetName, OptionChain optionChain) : m_assetName(assetName), m_optionChain(optionChain)
		{
			;
		}

		void GenerateGrid(int maxMaturity, double maxStrike, double strikeStep, bool fillWithKnown = true);
		void FitVolSurface(std::string fittingMethod); //Function to take the option chain data and fit a vol surface using a given fitting type.

		std::vector<std::vector<double>> GetImpliedVolSurface() { return m_impliedVolSurface; }

		

	
	protected:

		std::vector<std::vector<double>> DecomposeOptionChain() //returns array with each element as (K, T,vol)
		{

			std::vector<EqOption> options = m_optionChain.GetOptions();

			std::vector<std::vector<double>> expiryVolStrike;//(options.size(), std::vector<double>(3));

			for (EqOption option : options)
			{
				double K = option.GetStrike();
				double T = option.GetMaturity();
				double vol = option.GetImpliedVol();
				std::vector<double> optionData = { K, T, vol };

				expiryVolStrike.push_back(optionData);
			}

			return expiryVolStrike;
		}

		//void FillGrid(std::vector<std::vector<double>>& optionChainData);
		//void FillGrid() { FillGrid(DecomposeOptionChain(); }

		double StrikeIndexToValue(int index, double strikeStep) { return strikeStep * index; }
		int StrikeValueToIndex(double K, double strikeStep) { return std::floor(K / strikeStep); }

	private:
		std::string m_assetName;
		OptionChain m_optionChain;
		std::vector<double> m_strikes;
		int m_numberOfStrikes;
		std::vector<double> m_expiries;
		std::vector<std::vector<double>> m_impliedVolSurface; // indexed like surface[K][T]
		
		

	};
}

#endif