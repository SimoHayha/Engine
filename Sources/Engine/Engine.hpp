#pragma once

#include <cstdint>
#include <chrono>

#include "SystemRegister.hpp"
#include "SystemUpdater.hpp"

namespace Ngine
{
	class ENGINE_EXPORT Engine
	{
	private:
		typedef std::chrono::high_resolution_clock HighResolutionClock;
		typedef std::chrono::duration<float, std::milli> MillisecondsType;

		static Engine* INSTANCE;

		std::chrono::time_point<HighResolutionClock> m_start;
		float m_timeOffset;

		SystemRegister m_systemRegister;
		SystemUpdater m_systemUpdater;

		float m_fpsLimit;

		bool m_initialized;
		bool m_running;
		bool m_error;

	public:
		static Engine* Get();

		explicit Engine(const bool& emptyRegister = false);

		~Engine();

		int32_t Run();

		float GetFpsLimit() const;

		float GetTimeMs() const;

		float GetTime() const;
	};
}