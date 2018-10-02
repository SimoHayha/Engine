#include "Maths.hpp"

namespace Ngine
{
	bool Maths::AlmostEqual(const float& a, const float& b, const float& eps)
	{
		return std::fabs(a - b) < eps;
	}
}