// DCQuantLib.cpp 
// Devin Cladingbowl Quant Library - A basic library for experimenting with and understanding quantitative finance concepts
// Author: Devin Cladingbowl 
// 



#include "DCQuantLib.h"
#include "MarketData/EqOption.cpp"
#include "MarketData/OptionChain.h"
#include "Assets/Equity.h"
#include "Math/Interpolators/LinearInterpolator.h"
#include "DerivedMarketData/DiscountCurve.h"
#include "DerivedMarketData/VolSurface.cpp"
#include "Tools/Tools.h"



int main()
{
	using namespace DCQL;

	double x = 1.5;
	double x1 = 1.2;
	double x2 = 3.4;
	double y1 = 7.2;
	double y2 = 65.6;
	double f = (x - x1) / (x2 - x1);

	double y = LinearInterpolator::Interpolate(x, x1, x2, y1, y2);
	std::cout << y << std::endl;

	y = LinearInterpolator::Interpolate(y1, y2, f);
	std::cout << y << std::endl;

	std::vector<double> mats = { 1.0,2.0,3.0,4.0,5.0 };
	std::pair<int, int> interp = Tools::SurroundingIndices(mats, 1.59);

	std::cout << interp.first << " " << interp.second << std::endl;

	DiscountCurve dc = DiscountCurve({ 1,30,90,180,365, 730, 1000 }, { 1,2,3,4,5,6,7 }, true);

	double rate = dc.GetZeroRate(100.0);

	std::cout << rate << std::endl;

	EqOption option = DCQL::EqOption("equity1", EqOption::ClaimType::Call, 10, 11, 14, 0.24, true);
	dc.SetLabel("equity1");
	option.SetPrice(dc);
	std::cout << option.GetPrice() << std::endl;

	std::vector<EqOption> optionList = { option };

	OptionChain chain("equity1", optionList);

	VolSurface volSurface("equity1", chain);

	volSurface.GenerateGrid(15, 15, 0.1);

	auto grid = volSurface.GetImpliedVolSurface();

	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[i].size(); j++)
		{
			std::cout << grid[i][j] << " ";
		}

		std::cout << std::endl;
	}
	

	return 0;
	}

