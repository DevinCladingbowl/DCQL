#include <iostream>
#include "Asset.h"

class Equity : Asset
{
public:
	std::string GetAssetType() override { return "Equity"; }
	std::string GetEquityName() { return m_equityName; }


private:
	std::string m_equityName;

};