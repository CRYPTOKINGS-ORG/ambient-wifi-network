#pragma once
#include "../telemetry/TelemetryEngine.h"
#include "../optimizer/Optimizer.h"
#include "../spectrum/SpectrumAnalyzer.h"
#include "../interference/InterferenceClassifier.h"
#include "../digital_twin/DigitalTwin.h"
#include "../scheduler/Scheduler.h"

class Orchestrator {
public:
    void initialize();
    void run();
};
