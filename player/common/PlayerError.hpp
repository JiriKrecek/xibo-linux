#pragma once

#include <fmt/core.h>
#include <string>

class PlayerError
{
public:
    PlayerError() = default;
    PlayerError(std::string_view domain, std::string_view message);

    explicit operator bool() const noexcept;
    const std::string& domain() const;
    const std::string& message() const;

    friend std::ostream& operator<<(std::ostream& out, const PlayerError& error);

private:
    std::string domain_;
    std::string message_;
};

template <typename T>
struct fmt::formatter<T, std::enable_if_t<std::is_base_of<PlayerError, T>::value, char>> : fmt::formatter<std::string>
{
    auto format(const PlayerError& e, format_context& ctx) const
    {
        return fmt::formatter<std::string>::format("[" + e.domain() + "] ", ctx);
    }
};
