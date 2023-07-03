#include "Capacitor.h"
#include "Constants.h"

void Capacitor:: set_frequency(double frequency) { 
    this->frequency = frequency; 
}

double Capacitor:: get_frequency() const {
    return frequency;
}
std::complex<double> Capacitor:: get_impedance() const {
    double reactance = -1.0 / (2 * pi * frequency * capacitance);
    return std::complex<double>(0, reactance);
}
double Capacitor:: get_magnitude() const { 
    return std::abs(get_impedance()); 
}
double Capacitor:: get_phase_difference() const {
    return std::arg(get_impedance()); 
}
std::string Capacitor:: representation() const  {
    return "[C]";
}