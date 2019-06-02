#include "RansacFactory.hpp"

namespace model {
namespace improc {
namespace algorithm {

std::unique_ptr<Ransac> RansacFactory::make(const RansacParams& params)
{
    std::unique_ptr<Ransac> ransac;
    if(params.ransacMethod == "RANSAC Affine")
    {
        ransac = makeAlgo<AffineTransformationRansac>(params);
    }
    else if(params.ransacMethod == "RANSAC Perspective")
    {
        ransac = makeAlgo<PerspectiveTransformationRansac>(params);
    }
    else
    {
        throw std::runtime_error("Unknown ransac method: " + params.ransacMethod);
    }

    return ransac;
}

} // namespace algorithm
} // namespace improc
} // namespace model
