#include "Timer.hpp"

#include "Engine/Engine.hpp"

namespace Ngine
{
	Timer::Timer(const float& interval) :
		m_startTime(0.0f),
		m_interval(interval * 1000.0f)
	{
		if (Engine::Get() != nullptr)
		{
			m_startTime = Engine::Get()->GetTimeMs();
		}
	}

	bool Timer::IsPassedTime() const
	{
		return Engine::Get()->GetTimeMs() - m_startTime >= m_interval;
	}

	void Timer::ResetStartTime()
	{
		m_startTime = Engine::Get()->GetTimeMs();
	}

	float Timer::GetInterval() const
	{
		return m_interval / 1000.0f;
	}

	void Timer::SetInterval(const float& interval)
	{
		if (m_interval == interval * 1000.0f)
		{
			return;
		}

		m_interval = interval * 1000.0f;
		m_startTime = Engine::Get()->GetTimeMs();
	}
}