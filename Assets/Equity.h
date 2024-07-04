#include <iostream>
#include "Asset.h"

class Equity : Asset
{
public:
	std::string GetAssetType() { return "Equity"; }
	std::string GetEquityName() { return equityName; }


private:
	std::string equityName;

};