#pragma once

#include "Exports.hpp"

namespace Ngine
{
	enum SystemUpdate
	{
		UPDATE_ALWAYS = 0,
		UPDATE_PRE = 1,
		UPDATE_NORMAL = 2,
		UPDATE_POST = 3,
		UPDATE_RENDER = 4
	};

	class ENGINE_EXPORT ISystem
	{
	public:
		virtual void Update() = 0;
	};
}