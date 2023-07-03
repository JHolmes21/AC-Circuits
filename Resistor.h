#ifndef RESISTOR_H
#define RESISTOR_H
#include "Component.h"
class Resistor : public Component {
private:
    double resistance;
public:
    Resistor(double resistance) : resistance(resistance) {}

    void set_frequency(double frequency) override;
    double get_frequency() const override;
    std::complex<double> get_impedance() const override;
    double get_magnitude() const override;
    double get_phase_difference() const override;
    std::string representation() const override;
};

#endif
