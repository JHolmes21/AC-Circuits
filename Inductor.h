#ifndef INDUCTOR_H
#define INDUCTOR_H
#include "Component.h"
class Inductor : public Component {
private:
    double inductance;
    double frequency;
public:
    Inductor(double inductance, double frequency) : inductance(inductance), frequency(frequency) {}

    void set_frequency(double frequency) override;
    double get_frequency() const override;
    std::complex<double> get_impedance() const;
    double get_magnitude() const override;
    double get_phase_difference() const override;
    std::string representation() const override;
};

#endif
