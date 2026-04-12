#include "EnvLoader.h"
#include <fstream>
#include <sstream>

EnvLoader::EnvLoader(const std::string& path) {
    std::ifstream file(path);
    std::string line;

    while (getline(file, line)) {
        size_t pos = line.find("=");
        if (pos != std::string::npos) {
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
            env[key] = value;
        }
    }
}

std::string EnvLoader::get(const std::string& key) {
    return env[key];
}
