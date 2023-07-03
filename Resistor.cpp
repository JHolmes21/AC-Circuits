#include "Resistor.h"
void Resistor::set_frequency(double frequency) {
    // Resistor's impedance is independent of frequency. So, nothing to do here.
}

double Resistor::get_frequency() const {
    // Resistor's impedance is independent of frequency. So, return 0.
    return 0;
}

std::complex<double> Resistor::get_impedance() const {
    return std::complex<double>(resistance, 0);
}

double Resistor::get_magnitude() const {
    return resistance;
}

double Resistor::get_phase_difference() const {
    return 0;
}

std::string Resistor::representation() const {
    return "[R]";
}