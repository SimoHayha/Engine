#pragma once

#include <cstring>
#include <optional>
#include <string>
#include <vector>

#include "Engine/Exports.hpp"
#include "Engine/Log.hpp"

namespace Ngine
{
	class ENGINE_EXPORT FileSystem
	{
	public:
		static const char SEPARATOR;
		static const char ALT_SEPARATOR;

		static std::string GetWorkingDirectory();

		static bool Exists(const std::string& path);

		static bool IsFile(const std::string& path);

		static bool IsDirectory(const std::string& path);

		static bool IsReadable(const std::string& path);

		static bool IsWriteable(const std::string& path);

		static std::vector<std::string> FilesInPath(const std::string& path);

		static bool Create(const std::string& path);

		static bool Delete(const std::string& path);

		static std::optional<std::string> ReadTextFile(const std::string& filename);

		static bool WriteTextFile(const std::string& filename, const std::string& data);

		static std::optional<std::vector<char>> ReadBinaryFile(const std::string& filename, const std::string& mode = "rb");

		static bool WriteBinaryFile(const std::string& filename, const std::vector<char>& data, const std::string& mode = "wb");

		static bool ClearFile(const std::string& filename);

		static std::string ParentDirectory(const std::string& path);

		static std::string Filename(const std::string& path);

		static std::string FileSuffix(const std::string& path);

		static std::string JoinPath(const std::vector<std::string>& parts);

		static std::vector<std::string> SplitPath(const std::string& path, const char& delim = SEPARATOR);
	};
}