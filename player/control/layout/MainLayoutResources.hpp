#pragma once

#include "common/parsing/Parsing.hpp"

namespace XlfResources::MainLayout {
const std::string SchemaVersion = Parsing::xmlAttr("schemaVersion");
const std::string Width = Parsing::xmlAttr("width");
const std::string Height = Parsing::xmlAttr("height");
const std::string StatsEnabled = Parsing::xmlAttr("enableStat");
const std::string BackgroundPath = Parsing::xmlAttr("background");
const std::string BackgroundColor = Parsing::xmlAttr("bgcolor");
} // namespace XlfResources::MainLayout
