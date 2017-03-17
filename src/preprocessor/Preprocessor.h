
#pragma once

#include <string>

class Preprocessor {
public:
    Preprocessor(std::string source_code) : source(std::move(source_code)) {

    }

    std::string preprocess_source();

private:
    std::string source;
};

