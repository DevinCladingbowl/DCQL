
#include "MarketData.h"
#include "EqOption.h"

#ifndef OPTIONCHAIN_H
#define OPTIONCHAIN_H

namespace DCQL
{
	class OptionChain : MarketData
	{
	public:
		std::string GetMarketDataType() { return "OptionChain"; }
	};
}
#endif // !OPTIONCHAIN_H
