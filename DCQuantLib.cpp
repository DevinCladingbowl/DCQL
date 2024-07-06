// DCQuantLib.cpp 
// Devin Cladingbowl Quant Library - A basic library for experimenting with and understanding quantitative finance concepts
// Author: Devin Cladingbowl 
// 



#include "DCQuantLib.h"
#include "MarketData/EqOption.cpp"
#include "Math/Interpolators/LinearInterpolator.h"





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

	return 0;
	}

