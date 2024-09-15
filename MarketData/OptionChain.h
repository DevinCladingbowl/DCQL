
#include "MarketData.h"
#include "EqOption.h"

#ifndef OPTIONCHAIN_H
#define OPTIONCHAIN_H

namespace DCQL
{
	class OptionChain : MarketData
	{
	public:

		OptionChain(std::string assetName, std::vector<EqOption> options);

		std::string GetMarketDataType() { return "OptionChain"; }
		std::vector<EqOption> GetOptions() { return m_options; }

	private:
		std::string m_assetName;
		std::vector<EqOption> m_options;

	};
}
#endif // !OPTIONCHAIN_H
