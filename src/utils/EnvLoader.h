#pragma once
#include <unordered_map>
#include <string>

class EnvLoader {
public:
    EnvLoader(const std::string& path);
    std::string get(const std::string& key);
private:
    std::unordered_map<std::string, std::string> env;
};
