#pragma once

#include <filesystem>
#include <fmt/core.h>
#include <string>

class FilePath : public std::filesystem::path
{
public:
    FilePath() : path() {}
    FilePath(const path& p) : path(p) {}
    FilePath(const std::string& p) : path(p) {}
    FilePath(const char* p) : path(p) {}
};

template <typename T>
struct fmt::formatter<T, std::enable_if_t<std::is_base_of<FilePath, T>::value, char>> : fmt::formatter<std::string>
{
    auto format(const FilePath& file, format_context& ctx) const
    {
        std::stringstream stream;
        stream << file;
        return fmt::formatter<std::string>::format(stream.str(), ctx);
    }
};
