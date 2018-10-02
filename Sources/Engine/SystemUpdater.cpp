#include "SystemUpdater.hpp"

#include "Engine/Engine.hpp"
#include "Math/Maths.hpp"

namespace Ngine
{
	SystemUpdater::SystemUpdater() :
		m_deltaUpdate(Delta()),
		m_deltaRender(Delta()),
		m_timerUpdate(Timer(1.0f / 66.0f)),
		m_timerRender(Timer(1.0f / -1.0f))
	{
	}

	void SystemUpdater::Update(const SystemRegister& systemRegister)
	{
		m_timerRender.SetInterval(1.0f / Engine::Get()->GetFpsLimit());

		systemRegister.RunUpdate(UPDATE_ALWAYS);

		if (m_timerUpdate.IsPassedTime())
		{
			m_timerUpdate.ResetStartTime();

			systemRegister.RunUpdate(UPDATE_PRE);

			systemRegister.RunUpdate(UPDATE_NORMAL);

			systemRegister.RunUpdate(UPDATE_POST);

			m_deltaUpdate.Update();
		}

		if (!Maths::AlmostEqual(m_timerUpdate.GetInterval(), m_deltaUpdate.GetChange(), 5.0f))
		{
			return;
		}

		if (m_timerRender.IsPassedTime() || Engine::Get()->GetFpsLimit() <= 0.0f)
		{
			m_timerRender.ResetStartTime();

			systemRegister.RunUpdate(UPDATE_RENDER);

			m_deltaRender.Update();
		}
	}

	float SystemUpdater::GetDelta() const
	{
		return m_deltaUpdate.GetChange();
	}

	float SystemUpdater::GetDeltaRender() const
	{
		return m_deltaRender.GetChange();
	}
}