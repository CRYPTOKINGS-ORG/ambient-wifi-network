#include "Gateway.h"
#include <iostream>

void Gateway::start() {
    std::cout << "Gateway running..." << std::endl;

    while (true) {
        // Simulated RF decoding loop
        std::vector<int> samples = {1,0,1,1,0};

        std::string decoded;
        for (auto s : samples) {
            decoded += (s > 0) ? "1" : "0";
        }

        std::cout << "Decoded backscatter: " << decoded << std::endl;
    }
}
