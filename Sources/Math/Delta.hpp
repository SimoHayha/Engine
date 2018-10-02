#pragma once

#include "Engine/Exports.hpp"

namespace Ngine
{
	class ENGINE_EXPORT Delta
	{
	private:
		float m_currentFrameTime;
		float m_lastFrameTime;
		float m_change;
		float m_time;

	public:
		Delta();

		void Update();

		float GetChange() const;
		float GetTime() const;
	};
}