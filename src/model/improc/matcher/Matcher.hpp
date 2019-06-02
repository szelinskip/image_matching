#pragma once

#include <utility>
#include <vector>

#include <helpers/Point.hpp>

namespace model {
namespace improc {
namespace matcher {

using helpers::Point;
using Points = std::vector<Point>;
using MatchingPointsPairs = std::vector<std::pair<Point, Point>>;

class Matcher
{
public:
    Matcher();
    virtual ~Matcher();

    Matcher(const Matcher&) = delete;
    Matcher& operator=(const Matcher&) = delete;
    Matcher(Matcher&&) = delete;
    Matcher& operator=(Matcher&&) = delete;

    virtual MatchingPointsPairs matchPoints(const MatchingPointsPairs& pointsPairs) = 0;
};

} // namespace matcher
} // namespace improc
} // namespace model
