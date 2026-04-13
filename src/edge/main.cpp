#include "rf_frontend.h"

int main() {
    RfChainConfig chainCfg {
        .antenna = { "dipole", 3.0 },
        .filter2g = { "2.4GHz", 2412.0, 20.0 },
        .filter5g = { "5GHz",   5180.0, 80.0 },
        .lna = { 15.0, 1.2 },
        .pa  = { 23.0, 18.0 },
        .sw  = { true, true }
    };

    RfFrontEnd2x2 fe(chainCfg, chainCfg);
    fe.print();
    return 0;
}
