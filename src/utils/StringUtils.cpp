#include "StringUtils.hpp"

namespace utils {
namespace str {

std::string replace(const std::string& target, const std::string& search, const std::string& replace)
{
    std::string result(target);
    for(size_t pos = 0; ; pos += replace.length())
    {
        // Locate the substring to replace
        pos = result.find( search, pos );
        if(pos == std::string::npos)
            break;
        // Replace by erasing and inserting
        result.erase(pos, search.length());
        result.insert(pos, replace);
    }
    return result;
}

} // namespace str
} // namespace utils
