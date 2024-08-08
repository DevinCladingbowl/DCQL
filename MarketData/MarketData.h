#include <iostream>

#ifndef MARKETDATA_H
#define MARKETDATA_H
namespace DCQL {

	class MarketData
	{
	public:
		virtual std::string GetMarketDataType() = 0;
	};
}
#endif