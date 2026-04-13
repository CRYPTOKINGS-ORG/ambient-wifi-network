#pragma once
#include <string>
#include <array>
#include <iostream>

struct RfFilter {
    std::string band;      // "2.4GHz" or "5GHz"
    double centerFreqMHz;  // e.g. 2412, 5180
    double bandwidthMHz;   // e.g. 20, 40, 80
};

struct LnaConfig {
    double gainDb;         // e.g. 15.0
    double noiseFigureDb;  // e.g. 1.2
};

struct PaConfig {
    double maxOutputDbm;   // e.g. 23.0
    double linearRegionDbm;// e.g. 18.0
};

struct RfSwitchConfig {
    bool txEnabled;
    bool rxEnabled;
};

struct AntennaConfig {
    std::string type;      // "dipole", "pcb"
    double gainDb;         // e.g. 3.0
};

struct RfChainConfig {
    AntennaConfig antenna;
    RfFilter      filter2g;
    RfFilter      filter5g;
    LnaConfig     lna;
    PaConfig      pa;
    RfSwitchConfig sw;
};

class RfChain {
public:
    explicit RfChain(const RfChainConfig& cfg) : config(cfg) {}

    void print() const {
        std::cout << "[RF Chain]\n"
                  << "  Antenna: " << config.antenna.type
                  << " (" << config.antenna.gainDb << " dBi)\n"
                  << "  2.4GHz filter @ " << config.filter2g.centerFreqMHz
                  << " MHz, BW " << config.filter2g.bandwidthMHz << " MHz\n"
                  << "  5GHz filter @ " << config.filter5g.centerFreqMHz
                  << " MHz, BW " << config.filter5g.bandwidthMHz << " MHz\n"
                  << "  LNA: gain " << config.lna.gainDb
                  << " dB, NF " << config.lna.noiseFigureDb << " dB\n"
                  << "  PA: max " << config.pa.maxOutputDbm
                  << " dBm, linear " << config.pa.linearRegionDbm << " dBm\n"
                  << "  Switch: TX=" << (config.sw.txEnabled ? "on" : "off")
                  << ", RX=" << (config.sw.rxEnabled ? "on" : "off") << "\n";
    }

private:
    RfChainConfig config;
};

class RfFrontEnd2x2 {
public:
    RfFrontEnd2x2(const RfChainConfig& chain0, const RfChainConfig& chain1)
        : chains{ RfChain(chain0), RfChain(chain1) } {}

    void print() const {
        std::cout << "=== WiFi 5 RF Front-End (2x2 MIMO) ===\n";
        chains[0].print();
        chains[1].print();
    }

private:
    std::array<RfChain, 2> chains;
};
