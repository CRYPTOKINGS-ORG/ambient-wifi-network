# WiFi 5 RF Front-End (2×2 MIMO)

This module models a WiFi‑5 RF front‑end for use inside the Edge Node.

## Components Modeled
- Antenna
- 2.4 GHz SAW filter
- 5 GHz BAW filter
- LNA (Low‑Noise Amplifier)
- PA (Power Amplifier)
- RF Switch (TX/RX)
- 2×2 MIMO front‑end

## Files
- `rf_frontend.h` — unified header containing all RF structures and classes
- `rf_frontend.cpp` — implementation placeholder
- `main.cpp` — example usage and test harness

## Example

```cpp
RfChainConfig cfg {
    {"dipole", 3.0},
    {"2.4GHz", 2412, 20},
    {"5GHz", 5180, 80},
    {15.0, 1.2},
    {23.0, 18.0},
    {true, true}
};

RfFrontEnd2x2 fe(cfg, cfg);
fe.print();
