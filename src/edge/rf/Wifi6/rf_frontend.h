#pragma once
#include <string>
#include <array>
#include <iostream>

struct RfFilter6 {
    std::string band;          // "2.4GHz" or "5GHz"
    double centerFreqMHz;      // e.g. 2412, 5180
    double bandwidthMHz;       // 20, 40, 80, 160 MHz
    double insertionLossDb;    // tighter spec for WiFi 6
};

struct LnaConfig6 {
    double gainDb;             // e.g. 17.0
    double noiseFigureDb;      // e.g. 0.9 (lower NF for WiFi 6)
    double linearityDbm;       // improved linearity
};

struct PaConfig6 {
    double maxOutputDbm;       // e.g. 24.0
    double linearRegionDbm;    // e.g. 20.0 (higher linearity for 1024-QAM)
    double efficiencyPercent;  // PA efficiency
};

struct RfSwitchConfig6 {
    bool txEnabled;
    bool rxEnabled;
    double isolationDb;        // improved isolation for OFDMA
};

struct AntennaConfig6 {
    std::string type;          // "dipole", "pcb", "patch"
    double gainDb;             // e.g. 4.0
    bool supportsMuMimo;       // WiFi 6 MU-MIMO
};

struct RfChainConfig6 {
    AntennaConfig6 antenna;
    RfFilter6      filter2g;
    RfFilter6      filter5g;
    LnaConfig6     lna;
    PaConfig6      pa;
    RfSwitchConfig6 sw;
};

class RfChain6 {
public:
    explicit RfChain6(const RfChainConfig6& cfg) : config(cfg) {}

    void print() const {
        std::cout << "[WiFi 6 RF Chain]\n"
                  << "  Antenna: " << config.antenna.type
                  << " (" << config.antenna.gainDb << " dBi, MU-MIMO="
                  << (config.antenna.supportsMuMimo ? "yes" : "no") << ")\n"
                  << "  2.4GHz filter @ " << config.filter2g.centerFreqMHz
                  << " MHz, BW " << config.filter2g.bandwidthMHz
                  << " MHz, IL " << config.filter2g.insertionLossDb << " dB\n"
                  << "  5GHz filter @ " << config.filter5g.centerFreqMHz
                  << " MHz, BW " << config.filter5g.bandwidthMHz
                  << " MHz, IL " << config.filter5g.insertionLossDb << " dB\n"
                  << "  LNA: gain " << config.lna.gainDb
                  << " dB, NF " << config.lna.noiseFigureDb
                  << " dB, linearity " << config.lna.linearityDbm << " dBm\n"
                  << "  PA: max " << config.pa.maxOutputDbm
                  << " dBm, linear " << config.pa.linearRegionDbm
                  << " dBm, eff " << config.pa.efficiencyPercent << "%\n"
                  << "  Switch: TX=" << (config.sw.txEnabled ? "on" : "off")
                  << ", RX=" << (config.sw.rxEnabled ? "on" : "off")
                  << ", isolation=" << config.sw.isolationDb << " dB\n";
    }

private:
    RfChainConfig6 config;
};

class RfFrontEnd2x2_6 {
public:
    RfFrontEnd2x2_6(const RfChainConfig6& c0, const RfChainConfig6& c1)
        : chains{ RfChain6(c0), RfChain6(c1) } {}

    void print() const {
        std::cout << "=== WiFi 6 RF Front-End (2x2 MIMO) ===\n";
        chains[0].print();
        chains[1].print();
    }

private:
    std::array<RfChain6, 2> chains;
};
