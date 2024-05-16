#pragma once

#include <filesystem>
// #include <format>
#include <fmt/core.h>
#include <string>

class FilePath : public std::filesystem::path {
public:
  FilePath() : path() {}
  FilePath(const path &p) : path(p) {}
  FilePath(const std::string &p) : path(p) {}
  FilePath(const char *p) : path(p) {}
};

// template <>
// struct std::formatter<std::filesystem::path> : std::formatter<std::string> {
//   auto format(std::filesystem::path file, format_context &ctx) const {
//     return formatter<string>::format(std::format("{}", file.c_str()), ctx);
//   }
// };

// template <> struct std::formatter<FilePath> : std::formatter<std::string> {
//   auto format(FilePath file, format_context &ctx) const {
//     return formatter<string>::format(std::format("{}", file.c_str()), ctx);
//   }
// };

template <typename T>
struct fmt::formatter<
    T, std::enable_if_t<std::is_base_of<FilePath, T>::value, char>>
    : fmt::formatter<std::string> {
  auto format(const FilePath &file, format_context &ctx) const {
    std::stringstream stream;
    stream << file;
    return fmt::formatter<std::string>::format(stream.str(), ctx);
  }
};