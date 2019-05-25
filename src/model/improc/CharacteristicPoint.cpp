#include "CharacteristicPoint.hpp"

namespace model {
namespace improc {

CharacteristicPoint::CharacteristicPoint() = default;

CharacteristicPoint::CharacteristicPoint(const Point point)
    : point(point)
{
}

CharacteristicPoint::CharacteristicPoint(const Point point, std::vector<int32_t>&& features)
    : features(std::move(features))
    , point(point)
{
}

CharacteristicPoint::~CharacteristicPoint() = default;
CharacteristicPoint::CharacteristicPoint(const CharacteristicPoint&) = default;
CharacteristicPoint& CharacteristicPoint::operator=(const CharacteristicPoint&) = default;
CharacteristicPoint::CharacteristicPoint(CharacteristicPoint&&) = default;
CharacteristicPoint& CharacteristicPoint::operator=(CharacteristicPoint&&) = default;

const std::vector<int32_t>& CharacteristicPoint::getFeatures() const
{
    return features;
}

void CharacteristicPoint::setFeatures(std::vector<int32_t>&& features)
{
    this->features = std::move(features);
}

Point CharacteristicPoint::getPoint() const
{
    return point;
}

void CharacteristicPoint::setPoint(const helpers::Point point)
{
    this->point = point;
}


} // namespace improc
} // namespace model
