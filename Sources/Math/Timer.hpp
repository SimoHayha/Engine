#pragma once

#include "Engine/Exports.hpp"

namespace Ngine
{
	class ENGINE_EXPORT Timer
	{
	private:
		float m_startTime;
		float m_interval;

	public:
		explicit Timer(const float& interval);

		bool IsPassedTime() const;

		void ResetStartTime();

		float GetInterval() const;

		void SetInterval(const float& interval);
	};
}