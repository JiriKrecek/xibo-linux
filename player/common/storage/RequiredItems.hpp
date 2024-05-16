#pragma once

#include "common/crypto/Md5Hash.hpp"
#include "common/dt/DateTime.hpp"

// #include <format>
#include <fmt/core.h>
#include <string>
#include <vector>

class RegularFile {
public:
  enum class DownloadType { HTTP, XMDS, Invalid };

  RegularFile(int id, size_t size, const Md5Hash &hash, const std::string &url,
              const std::string &name, const std::string &type,
              DownloadType downloadType);

  int id() const;
  size_t size() const;
  Md5Hash hash() const;
  std::string url() const;
  std::string name() const;
  std::string type() const;
  DownloadType downloadType() const;

private:
  friend std::ostream &operator<<(std::ostream &out, const RegularFile &file);

private:
  int id_;
  size_t size_;
  Md5Hash hash_;
  std::string url_;
  std::string name_;
  std::string type_;
  DownloadType downloadType_;
};
// template <> struct std::formatter<RegularFile> : std::formatter<std::string>
// {
//   auto format(RegularFile file, format_context &ctx) const {
//     stringstream stream;
//     stream << file;
//     return formatter<string>::format(std::format("{}", stream.str()), ctx);
//   }
// };
template <typename T>
struct fmt::formatter<
    T, std::enable_if_t<std::is_base_of<RegularFile, T>::value, char>>
    : fmt::formatter<std::string> {
  auto format(const RegularFile &file, format_context &ctx) const {
    std::stringstream stream;
    stream << file;
    return fmt::formatter<std::string>::format(stream.str(), ctx);
  }
};

class ResourceFile {
public:
  ResourceFile(int layoutId, int regionId, int mediaId,
               const DateTime &lastUpdate);

  int layoutId() const;
  int regionId() const;
  int mediaId() const;
  DateTime lastUpdate() const;
  std::string name() const;

private:
  friend std::ostream &operator<<(std::ostream &out, const ResourceFile &res);

private:
  int layoutId_;
  int regionId_;
  int mediaId_;
  DateTime lastUpdate_;
};

// template <> struct std::formatter<ResourceFile> : std::formatter<std::string>
// {
//   auto format(ResourceFile file, format_context &ctx) const {
//     stringstream stream;
//     stream << file;
//     return formatter<string>::format(std::format("{}", stream.str()), ctx);
//   }
// };

template <typename T>
struct fmt::formatter<
    T, std::enable_if_t<std::is_base_of<ResourceFile, T>::value, char>>
    : fmt::formatter<std::string> {
  auto format(const ResourceFile &file, format_context &ctx) const {
    std::stringstream stream;
    stream << file;
    return fmt::formatter<std::string>::format(stream.str(), ctx);
  }
};

std::ostream &operator<<(std::ostream &out, const RegularFile &file);
std::ostream &operator<<(std::ostream &out, const ResourceFile &res);

template <typename RequriedFile>
using RequiredFilesSet = std::vector<RequriedFile>;
