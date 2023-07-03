#ifndef CAPACITOR_H
#define CAPACITOR_H
#include "Component.h"
class Capacitor : public Component {
private:
    double capacitance;
    double frequency;
public:
    Capacitor(double capacitance, double frequency) : capacitance(capacitance), frequency(frequency) {}

    void set_frequency(double frequency) override;
    double get_frequency() const override;
    std::complex<double> get_impedance() const;
    double get_magnitude() const override;
    double get_phase_difference() const override;
    std::string representation() const override;
};

#endif
