#pragma once

#include <memory>
#include <sstream>
#include <string>

#include "Exports.hpp"

namespace Ngine
{
	class ENGINE_EXPORT Log
	{
	private:
		static std::ostringstream STREAM;

	public:
		static void Out(const std::string& string);

		template <typename... Args>
		static void Out(const std::string& format, Args&&... args)
		{
			Out(StringFormat(format, std::forward<Args>(args)...));
		}

		static void Error(const std::string& string);

		template <typename... Args>
		static void Error(const std::string& format, Args&&... args)
		{
			Error(StringFormat(format, std::forward<Args>(args)...));
		}

		static void CreateLog(const std::string& filename);

	private:
		template <typename... Args>
		static std::string StringFormat(const std::string& format, Args&&... args)
		{
			size_t size = snprintf(nullptr, 0u, format.c_str(), args...) + 1u; // For \0
			std::unique_ptr<char[]> buf(new char[size]);
			snprintf(buf.get(), size, format.c_str(), args...);
			return std::string(buf.get(), buf.get() + size - 1u);
		}
	};
}