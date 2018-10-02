#pragma once

#include <map>
#include <memory>

#include "ISystem.hpp"

namespace Ngine
{
	class ENGINE_EXPORT SystemRegister
	{
	private:
		std::map<float, std::unique_ptr<ISystem>> m_systems;

	public:
		SystemRegister();
		SystemRegister(const SystemRegister&) = delete;
		SystemRegister(SystemRegister&&) = delete;
		SystemRegister& operator=(const SystemRegister&) = delete;
		SystemRegister& operator=(SystemRegister&&) = delete;

		void FillRegister();

		bool ContainsSystem(ISystem* system) const;

		template <typename T>
		T* GetModule() const
		{
			for (auto&[key, system] : m_systems)
			{
				auto casted = dynamic_cast<T*>(system.get());

				if (casted != nullptr)
				{
					return casted;
				}
			}

			return nullptr;
		}

		ISystem* RegisterSystem(ISystem* system, const SystemUpdate& update);

		template <typename T>
		T* RegisterSystem(const SystemUpdate& update)
		{
			auto system = static_cast<T*>(malloc(sizeof(T)));
			RegisterSystem(system, update);
			new(system) T();
			return system;
		}

		bool UnregisterSystem(ISystem* system);

		template <typename T>
		bool UnregisterModule()
		{
			for (auto it = --m_systems.end(); it != m_systems.begin(); --it)
			{
				auto casted = dynamic_cast<T*>((*it).second.get());

				if (casted != nullptr)
				{
					m_systems.erase(it);
					return true;
				}
			}

			return false;
		}

		void RunUpdate(const SystemUpdate& update) const;

		uint32_t GetModuleCount() const;
	};
}