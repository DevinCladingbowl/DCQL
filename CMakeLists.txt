# CMakeList.txt : CMake project for DCQuantLib, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (DCQuantLib "DCQuantLib.cpp" "DCQuantLib.h" "Assets/Equity.cpp" "Assets/Equity.h" "Assets/Asset.cpp" "Assets/Asset.h" "MarketData/MarketData.cpp" "MarketData/MarketData.h" "MarketData/OptionChain.h" "MarketData/OptionChain.cpp" "DerivedMarketData/DiscountCurve.h" "DerivedMarketData/DiscountCurve.cpp" "Math/Interpolators/LinearInterpolator.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DCQuantLib PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
