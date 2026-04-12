#pragma once
#include <string>

class AuthService {
public:
    std::string generateToken(const std::string& deviceId);
};
