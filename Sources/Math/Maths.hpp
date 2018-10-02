#pragma once

#include <algorithm>
#include <cstdint>
#include <cmath>
#include <cstdlib>

#include "Engine/Exports.hpp"

namespace Ngine
{
	static const float PI = 3.14159265358979323846264338f;
	static const float DEG_TO_RAD = PI / 180.0f;
	static const float RAD_TO_DEG = 360.0f / PI;

	class ENGINE_EXPORT Maths
	{
	public:
		static bool AlmostEqual(const float& a, const float& b, const float& eps);
	};
}