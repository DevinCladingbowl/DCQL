#include <vector>

#ifndef TOOLS_H
#define TOOLS_H

namespace DCQL
{
	class Tools
	{
	public:
		// Function to find the indices to use for linear interpolation. Returns index above and below.
		// Assumes vector is ordered
		// TODO: Make more efficient and safer etc.
		template <class T>
		static std::pair<int, int> SurroundingIndices(std::vector<T> &vec , T element)
		{
			int i = 0;
			while (element > vec[i])
			{
				i++;
			}

			return std::make_pair(i - 1, i);
		}
	};
}
#endif
