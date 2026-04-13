#include "Config.h"
#include <fstream>

Config::Config(const std::string& path) {
    std::ifstream file(path);
    std::string line;

    while (getline(file, line)) {
        auto pos = line.find('=');
        if (pos != std::string::npos) {
            data[line.substr(0, pos)] = line.substr(pos + 1);
        }
    }
}

std::string Config::get(const std::string& key) {
    return data[key];
}

int Config::getInt(const std::string& key) {
    return std::stoi(data[key]);
}
