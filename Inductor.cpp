#include "Inductor.h"
#include "Constants.h"
void Inductor::set_frequency(double frequency) {
    this->frequency = frequency;
}

double Inductor::get_frequency() const {
    return frequency;
}
std::complex<double> Inductor::get_impedance() const {
    double reactance = 2 * pi * frequency * inductance;
    return std::complex<double>(0, reactance);
}
double Inductor::get_magnitude() const {
    return std::abs(get_impedance());
}
double Inductor::get_phase_difference() const {
    return std::arg(get_impedance());
}
std::string Inductor::representation() const {
    return "[L]";
}