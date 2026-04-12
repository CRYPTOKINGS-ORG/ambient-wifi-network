#pragma once
#include <string>

class Jwt {
public:
    static std::string sign(const std::string& payload);
};
