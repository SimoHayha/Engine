#include <iostream>

#include "SystemRegister.hpp"

#include "Display/Renderer.hpp"

namespace Ngine
{
	SystemRegister::SystemRegister() :
		m_systems(std::map<float, std::unique_ptr<ISystem>>())
	{
	}

	void SystemRegister::FillRegister()
	{
		RegisterSystem<Renderer>(UPDATE_POST);
	}

	bool SystemRegister::ContainsSystem(ISystem* system) const
	{
		for (auto& system1 : m_systems)
		{
			if (system1.second.get() == system)
			{
				return true;
			}
		}

		return false;
	}

	ISystem* SystemRegister::RegisterSystem(ISystem* system, const SystemUpdate& update)
	{
		if (ContainsSystem(system))
		{
			std::cerr << "Module " << system << " is already registered\n";
			return nullptr;
		}

		float key = static_cast<float>(update) + (0.01f * static_cast<float>(m_systems.size()));
		m_systems.emplace(key, system);
		return system;
	}

	bool SystemRegister::UnregisterSystem(ISystem* system)
	{
		for (auto it = --m_systems.end(); it != m_systems.begin(); --it)
		{
			if ((*it).second.get() != system)
			{
				continue;
			}

			m_systems.erase(it);
			return true;
		}

		return false;
	}

	void SystemRegister::RunUpdate(const SystemUpdate& update) const
	{
		for (auto&[key, system] : m_systems)
		{
			if (static_cast<int32_t>(std::floor(key)) == update)
			{
				system->Update();
			}
		}
	}

	uint32_t SystemRegister::GetModuleCount() const
	{
		return static_cast<uint32_t>(m_systems.size());
	}
}