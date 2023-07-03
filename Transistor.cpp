#include "Transistor.h"
void Transistor::set_frequency(double frequency) {
    // Transistor's impedance is independent of frequency. So, nothing to do here.
}

double Transistor::get_frequency() const {
    // Transistor's impedance is independent of frequency. So, return 0.
    return 0;
}

std::complex<double> Transistor::get_impedance() const {
    // Simplified model: Transistor impedance is considered infinite (open circuit) when off
    // and a constant Vbe_on voltage drop when on.
    // Actual impedance would depend on the operating point of the transistor.
    // Modelled here by a user-inputted effective resistance
    return std::complex<double>(effective_resistance, 0);
}

double Transistor::get_magnitude() const {
    return effective_resistance;
}

double Transistor::get_phase_difference() const {
    return 0;
}

std::string Transistor::representation() const {
    return "[T]";
}