#pragma once

#include <memory>

#include "Matcher.hpp"
#include <model/ImageMatchingParams.hpp>

namespace model {
namespace improc {
namespace matcher {

class MatcherFactory
{
public:
    MatcherFactory();
    ~MatcherFactory();

    MatcherFactory(const MatcherFactory&) = delete;
    MatcherFactory& operator=(const MatcherFactory&) = delete;
    MatcherFactory(MatcherFactory&&) = delete;
    MatcherFactory& operator=(MatcherFactory&&) = delete;

    std::unique_ptr<Matcher> make(const ImageMatchingParams& params);
};

} // namespace matcher
} // namespace improc
} // namespace model
