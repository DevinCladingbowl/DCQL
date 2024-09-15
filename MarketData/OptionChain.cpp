
#include "OptionChain.h"
namespace DCQL
{
	OptionChain::OptionChain(std::string assetName, std::vector<EqOption> options) : m_assetName(assetName), m_options(options)
	{
		;
	}
}