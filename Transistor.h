#ifndef TRANSISTOR_H
#define TRANSISTOR_H
#include "Component.h"
class Transistor : public Component {
private:
    double effective_resistance;
public:
    Transistor(double effective_resistance) : effective_resistance(effective_resistance) {}

    void set_frequency(double frequency) override;
    double get_frequency() const override;
    std::complex<double> get_impedance() const override;
    double get_magnitude() const override;
    double get_phase_difference() const override;
    std::string representation() const override;
};

#endif