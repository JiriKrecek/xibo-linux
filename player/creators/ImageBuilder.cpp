#include "ImageBuilder.hpp"
#include "adaptors/GtkImageAdaptor.hpp"

#include <boost/optional/optional.hpp>

std::unique_ptr<Image> ImageBuilder::build()
{
    ImageProperties props{m_scaleType, m_align, m_valign};
    auto image = std::make_unique<Image>(m_id, m_width, m_height, m_path, props, createAdaptor());
    prepareCommonParams(*image);
    return image;
}

std::unique_ptr<IImageAdaptor> ImageBuilder::createAdaptor()
{
    return std::make_unique<GtkImageAdaptor>();
}

ImageBuilder& ImageBuilder::width(int width)
{
    m_width = width;
    return *this;
}

ImageBuilder& ImageBuilder::height(int height)
{
    m_height = height;
    return *this;
}

ImageBuilder& ImageBuilder::mediaOptions(const ResourcesXlf::ImageOptions& opts)
{
    m_scaleType = getScaleTypeOption(opts.scaleType());
    m_align = getAlignOption(opts.align());
    m_valign = getValignOption(opts.valign());
    return *this;
}

ImageProperties::ScaleType ImageBuilder::getScaleTypeOption(const boost::optional<std::string>& scaleTypeOpt)
{
    auto scaleType = scaleTypeOpt.value_or(DEFAULT_SCALE_TYPE);

    if(scaleType == "center")
        return ImageProperties::ScaleType::Scaled;
    else if(scaleType == "stretch")
        return ImageProperties::ScaleType::Stretch;

    throw std::invalid_argument("ScaleType is not valid");
}

ImageProperties::Align ImageBuilder::getAlignOption(const boost::optional<std::string>& alignOpt)
{
    auto align = alignOpt.value_or(DEFAULT_ALIGN);

    if(align == "left")
        return ImageProperties::Align::Left;
    else if(align == "center")
        return ImageProperties::Align::Center;
    else if(align == "right")
        return ImageProperties::Align::Right;

    throw std::invalid_argument("Align is not valid");
}

ImageProperties::Valign ImageBuilder::getValignOption(const boost::optional<std::string>& valignOpt)
{
    auto valign = valignOpt.value_or(DEFAULT_VALIGN);

    if(valign == "top")
        return ImageProperties::Valign::Top;
    else if(valign == "middle")
        return ImageProperties::Valign::Middle;
    else if(valign == "bottom")
        return ImageProperties::Valign::Bottom;

    throw std::invalid_argument("Valign is not valid");
}
