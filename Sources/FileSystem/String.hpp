#pragma once

#include <cstring>
#include <locale>
#include <sstream>
#include <string>
#include <typeinfo>
#include <vector>

#include "Engine/Exports.hpp"

namespace Ngine
{
	class ENGINE_EXPORT String
	{
	public:
		static std::vector<std::string> Split(const std::string& str, const std::string& sep, const bool& trim = false);

		static bool StartsWith(const std::string& str, const std::string& token);

		static bool Contains(const std::string& str, const std::string& token);

		static bool IsInteger(const std::string& str);

		static int32_t FindCharPos(const std::string& str, const char& c);

		static std::string Trim(const std::string& str, const std::string& whitespace = " \t\n\r");

		static std::string SubString(const std::string& str, const uint32_t& start, const uint32_t& end);

		static std::string RemoveAll(const std::string& str, const char& token);

		static std::string RemoveLast(const std::string& str, const char& token);

		static std::string ReplaceAll(const std::string& str, const std::string& token, const std::string& to);

		static std::string ReplaceFirst(const std::string& str, const std::string& token, const std::string& to);

		static std::string LowerCase(const std::string& str);

		static std::string Uppercase(const std::string& str);

		template <typename T>
		static std::string To(const T& val)
		{
			if constexpr (std::is_enum_v<T>)
			{
				return std::to_string(static_cast<int32_t>(val));
			}
			else if constexpr (std::is_same_v<bool, T>)
			{
				return val ? "true" : "false";
			}

			return std::to_string(val);
		}

		template <typename T>
		static T From(const std::string& str)
		{
			if constexpr (std::is_enum_v<T>)
			{
				return static_cast<T>(From<int32_t>(str));
			}
			else if constexpr (std::is_same_v<bool, T>)
			{
				return LowerCase(str) == "true" || From<int32_t>(str) == 1;
			}

			std::istringstream ss(str);
			T num;
			ss >> num;
			return num;
		}
	};
}