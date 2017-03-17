
#include "Preprocessor.h"
#include <regex>
#include <iterator>

// http://stackoverflow.com/a/3418285/6591463
bool str_replace(std::string &str, const std::string &from, const std::string &to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

std::string Preprocessor::preprocess_source() {
    // replace coments
    std::regex comment_regex("\\/\\/.*$");
    source = std::regex_replace(source, comment_regex, "");

    // TODO: Includes

    // TODO: apply ifdefs
    return source;
}
