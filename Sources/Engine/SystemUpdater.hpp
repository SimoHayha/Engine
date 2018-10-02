#pragma once

#include "Exports.hpp"
#include "Math/Delta.hpp"
#include "Math/Timer.hpp"
#include "SystemRegister.hpp"

namespace Ngine
{
	class ENGINE_EXPORT SystemUpdater
	{
	private:
		Delta m_deltaUpdate;
		Delta m_deltaRender;
		Timer m_timerUpdate;
		Timer m_timerRender;

	public:
		SystemUpdater();

		void Update(const SystemRegister& systemRegister);

		float GetDelta() const;

		float GetDeltaRender() const;
	};
}