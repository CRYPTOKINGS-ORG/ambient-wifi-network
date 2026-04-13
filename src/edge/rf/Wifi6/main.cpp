#include "rf_frontend6.h"

int main() {
    RfChainConfig6 cfg {
        .antenna = { "patch", 4.0, true },
        .filter2g = { "2.4GHz", 2412, 20, 1.2 },
        .filter5g = { "5GHz", 5180, 80, 1.0 },
        .lna = { 17.0, 0.9, -5.0 },
        .pa  = { 24.0, 20.0, 32.0 },
        .sw  = { true, true, 35.0 }
    };

    RfFrontEnd2x2_6 fe(cfg, cfg);
    fe.print();
    return 0;
}
