//This class defines the diode, a derived component class
#ifndef DIODE_H
#define DIODE_H
#include "Component.h"
class Diode : public Component {
private:
    double forward_voltage;
public:
    Diode(double forward_voltage): forward_voltage(forward_voltage) {}
    void set_frequency(double frequency) override;
    double get_frequency() const override;
    std::complex<double> get_impedance() const;
    double get_magnitude() const override;
    double get_phase_difference() const override;
    std::string representation() const override;
};

#endif
