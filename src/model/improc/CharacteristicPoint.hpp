#pragma once

#include <cstdint>
#include <vector>

#include <helpers/Point.hpp>

namespace model {
namespace improc {

using helpers::Point;

class CharacteristicPoint
{
public:
    CharacteristicPoint();
    explicit CharacteristicPoint(const Point point);
    CharacteristicPoint(const Point point, std::vector<int32_t>&& features);
    ~CharacteristicPoint();
    CharacteristicPoint(const CharacteristicPoint&);
    CharacteristicPoint& operator=(const CharacteristicPoint&);
    CharacteristicPoint(CharacteristicPoint&&);
    CharacteristicPoint& operator=(CharacteristicPoint&&);

    const std::vector<int32_t>& getFeatures() const;
    void setFeatures(std::vector<int32_t>&& features);
    Point getPoint() const;
    void setPoint(const Point point);

private:
    std::vector<int32_t> features;
    Point point;

};

} // namespace improc
} // namespace model
