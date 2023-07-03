//This header file declares the component base class
#ifndef COMPONENT_H
#define COMPONENT_H
#include <iostream>
#include <complex>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <algorithm>
class Component {
public:
    virtual void set_frequency(double frequency) = 0;
    virtual double get_frequency() const = 0;
    virtual std::complex<double> get_impedance() const = 0;
    virtual double get_magnitude() const = 0;
    virtual double get_phase_difference() const = 0;
    virtual ~Component() = default;
    virtual std::string representation() const = 0;
};
#endif
