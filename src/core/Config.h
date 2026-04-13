#pragma once
#include <unordered_map>
#include <string>

class Config {
public:
    Config(const std::string& path);
    std::string get(const std::string& key);
    int getInt(const std::string& key);

private:
    std::unordered_map<std::string, std::string> data;
};
