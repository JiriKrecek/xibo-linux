#include "AppConfig.hpp"

#include <boost/algorithm/string/predicate.hpp>

#include "common/PlayerRuntimeError.hpp"
#include "common/fs/FileSystem.hpp"

#include <filesystem>
#include <linux/limits.h>
#include <unistd.h>

FilePath AppConfig::resourceDirectory_;

std::string AppConfig::version()
{
    return releaseVersion() + "." + codeVersion();
}

std::string AppConfig::releaseVersion()
{
    // Update this with each release.
    return std::string{"1.1"};
}

std::string AppConfig::codeVersion()
{
    // Update this with each release
    return "1";
}

FilePath AppConfig::resourceDirectory()
{
    return resourceDirectory_;
}

void AppConfig::resourceDirectory(const FilePath& directory)
{
    if (!FileSystem::exists(directory))
        throw PlayerRuntimeError{
            "AppConfig", "Resource directory doesn't exist. Create or use exsiting one in the player options app."};

    resourceDirectory_ = directory;
}

FilePath AppConfig::configDirectory()
{
    return FilePath{std::filesystem::path("/var/lib/xibo")};
}

FilePath AppConfig::publicKeyPath()
{
    return configDirectory() / "id_rsa.pub";
}

FilePath AppConfig::privateKeyPath()
{
    return configDirectory() / "id_rsa";
}

FilePath AppConfig::cmsSettingsPath()
{
    return configDirectory() / "cmsSettings.xml";
}

FilePath AppConfig::playerSettingsPath()
{
    return configDirectory() / "playerSettings.xml";
}

FilePath AppConfig::schedulePath()
{
    return configDirectory() / "schedule.xml";
}

FilePath AppConfig::cachePath()
{
    return configDirectory() / "cacheFile.xml";
}

FilePath AppConfig::statsCache()
{
    return configDirectory() / "stats.sqlite";
}

FilePath AppConfig::additionalResourcesDirectory()
{
    return FilePath{std::filesystem::path("/usr/share/xibo")};
}

FilePath AppConfig::splashScreenPath()
{
    return additionalResourcesDirectory() / "splash.jpg";
}

FilePath AppConfig::uiFile()
{
    return additionalResourcesDirectory() / "ui.glade";
}

FilePath AppConfig::execDirectory()
{
    return FilePath{std::filesystem::path("/usr/bin")};
}

std::string AppConfig::playerBinary()
{
    return (execDirectory() / "xibo-player").string();
}

std::string AppConfig::optionsBinary()
{
    return (execDirectory() / "xibo-options").string();
}
