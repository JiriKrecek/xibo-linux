#include "common/fs/FilePath.hpp"
#include "common/fs/FileSystem.hpp"
#include "config/AppConfig.hpp"
#include "config/CmsSettings.hpp"

#include "ProcessWatcher.hpp"

#include <boost/program_options.hpp>

int main(int argc, char** argv)
{
    try
    {
        boost::program_options::options_description desc{"Options"};
        desc.add_options()("disable-restart", "Don't restart player (disable watchdog)");
        desc.add_options()("config-app", "Run config application");

        boost::program_options::variables_map vm;
        store(parse_command_line(argc, argv, desc), vm);


        if (FileSystem::exists(AppConfig::cmsSettingsPath()) && vm.count("config-app") == 0)
        {
            ProcessWatcher playerWatcher{AppConfig::playerBinary(), vm.count("disable-restart") > 0};
            playerWatcher.run();
        }
        else
        {
            boost::process::child optionsBin{AppConfig::optionsBinary()};
            optionsBin.wait();
        }
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
