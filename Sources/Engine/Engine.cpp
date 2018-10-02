#include <cstdlib>

#include "Engine.hpp"

namespace Ngine
{
	Engine* Engine::INSTANCE = nullptr;

	Engine* Engine::Get()
	{
		return INSTANCE;
	}

	Engine::Engine(const bool& emptyRegister) :
		m_start(HighResolutionClock::now()),
		m_timeOffset(0.0f),
		m_systemRegister(SystemRegister()),
		m_systemUpdater(SystemUpdater()),
		m_fpsLimit(-1.0f),
		m_initialized(false),
		m_running(true),
		m_error(false)
	{
		INSTANCE = this;

		if (!emptyRegister)
		{
			m_systemRegister.FillRegister();
		}
	}

	Engine::~Engine()
	{
	}

	int32_t Engine::Run()
	{
		while (m_running)
		{
			m_systemUpdater.Update(m_systemRegister);
		}

		return EXIT_SUCCESS;
	}

	float Engine::GetFpsLimit() const
	{
		return m_fpsLimit;
	}

	float Engine::GetTimeMs() const
	{
		return std::chrono::duration_cast<MillisecondsType>(HighResolutionClock::now() - m_start).count() + (m_timeOffset / 1000.0f);
	}

	float Engine::GetTime() const
	{
		return GetTimeMs() / 1000.0f;
	}
}