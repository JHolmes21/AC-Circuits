#ifndef NESTED_CIRCUIT_H
#define NESTED_CIRCUIT_H
#include "circuit.h"
class NestedCircuit : public Component {
public:
    NestedCircuit() {}

    void add_component_serial(const std::shared_ptr<Component>& component);

    void add_component_parallel(const std::shared_ptr<Component>& component);

    std::complex<double> get_impedance() const override;

    double get_magnitude() const override;

    double get_phase_difference() const override;

    void set_frequency(double frequency) override;

    double get_frequency() const override;
    void print_impedances() const;
    std::string representation() const override;

private:
    Circuit circuit;
    std::vector<std::shared_ptr<Component>> components;
};
#endif
