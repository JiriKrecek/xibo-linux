#include "HardwareKeyGenerator.hpp"

#include "common/system/System.hpp"

#include <string>

HardwareKey HardwareKeyGenerator::generate()
{
    auto key = static_cast<std::string>(System::macAddress());

    return HardwareKey{Md5Hash::fromString(key)};
}