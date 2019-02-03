#pragma once

#include "constants.hpp"
#include <boost/optional/optional.hpp>

namespace ResourcesXlf
{
    class LayoutOptions
    {
    public:
        LayoutOptions(const xml_node& node);

        int schemaVersion() const;
        int width() const;
        int height() const;

    private:
        int m_schemaVersion;
        int m_width;
        int m_height;
    };
}
