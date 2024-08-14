#pragma once

#include "common/types/internal/StrongType.hpp"
#include <fmt/core.h>
#include <sstream>
#include <string>

class XmlDocVersion : public StrongType<std::string>
{
public:
    using StrongType::StrongType;

    friend std::istream& operator>>(std::istream& in, XmlDocVersion& version);
    friend std::ostream& operator<<(std::ostream& out, const XmlDocVersion& version);
};

bool operator==(const XmlDocVersion& first, const XmlDocVersion& second);
bool operator!=(const XmlDocVersion& first, const XmlDocVersion& second);

std::istream& operator>>(std::istream& in, XmlDocVersion& version);
std::ostream& operator<<(std::ostream& out, const XmlDocVersion& version);

template <typename T>
struct fmt::formatter<T, std::enable_if_t<std::is_base_of<XmlDocVersion, T>::value, char>> : fmt::formatter<std::string>
{
    auto format(const XmlDocVersion& file, format_context& ctx) const
    {
        std::stringstream stream;
        stream << file;
        return fmt::formatter<std::string>::format(stream.str(), ctx);
    }
};
