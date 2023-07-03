#pragma once
#ifndef CIRCUIT_H
#define CIRCUIT_H
#include "Component.h"
//This is the circuit base class
//components are stored, and the total impedance is calculated through this

class Circuit {
private:
    std::vector<std::shared_ptr<Component>> components;
    std::complex<double> impedance;
public:
    void add_component_serial(const std::shared_ptr<Component>& component);
    void print_impedances() const;
    void add_component_parallel(const std::shared_ptr<Component>& component);
    std::complex<double> get_impedance() const;
    double get_magnitude() const;
    double get_phase_difference() const;
};
#endif