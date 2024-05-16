#pragma once

#include <boost/optional/optional.hpp>
#include <string>

namespace Stats {
enum class RecordType { Layout, Media };

std::string recordTypeToString(RecordType t);
boost::optional<RecordType> recordTypeFromSting(const std::string &t);
} // namespace Stats
