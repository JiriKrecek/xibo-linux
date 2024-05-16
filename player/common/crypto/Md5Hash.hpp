#pragma once

#include "common/fs/FilePath.hpp"
#include "common/types/internal/StrongType.hpp"

#include <string>

#define MD5_DIGEST_LENGTH 16

struct Md5Hash : StrongType<std::string> {
  using StrongType::StrongType;

  static Md5Hash fromString(std::string_view data);
  static Md5Hash fromFile(const FilePath &path);
};

bool operator==(const Md5Hash &first, const Md5Hash &second);
bool operator!=(const Md5Hash &first, const Md5Hash &second);
std::ostream &operator<<(std::ostream &out, const Md5Hash &hash);
