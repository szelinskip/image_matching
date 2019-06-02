#pragma once

#include <memory>
#include <utility>
#include <vector>

#include <improc/algorithm/Ransac.hpp>
#include <helpers/Point.hpp>
#include "Matcher.hpp"

namespace model {
namespace improc {
namespace matcher {

using helpers::Point;
using Points = std::vector<Point>;
using MatchingPointsPairs = std::vector<std::pair<Point, Point>>;

class RansacMatcher : public Matcher
{
public:
    RansacMatcher(std::unique_ptr<algorithm::Ransac>&& ransac);

    virtual MatchingPointsPairs matchPoints(const MatchingPointsPairs& pointsPairs) override;

private:
    std::unique_ptr<algorithm::Ransac> ransac;
};

} // namespace matcher
} // namespace improc
} // namespace model
