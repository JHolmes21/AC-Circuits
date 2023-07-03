#include "Nested_Circuit.h"

void NestedCircuit::add_component_serial(const std::shared_ptr<Component>& component) {
    circuit.add_component_serial(component);
}

void NestedCircuit::add_component_parallel(const std::shared_ptr<Component>& component) {
    circuit.add_component_parallel(component);
}

std::complex<double> NestedCircuit::get_impedance() const {
    return circuit.get_impedance();
}

double NestedCircuit::get_magnitude() const {
    return std::abs(get_impedance());
}

double NestedCircuit::get_phase_difference() const {
    return std::arg(get_impedance());
}


void NestedCircuit::set_frequency(double frequency) {
    for (auto& component : components) {
        component->set_frequency(frequency);
    }
}

double NestedCircuit::get_frequency() const {
    // This assumes all components in the nested circuit have the same frequency.
    return components.empty() ? 0 : components[0]->get_frequency();
}

void NestedCircuit::print_impedances() const {
    circuit.print_impedances();
}

std::string NestedCircuit::representation() const {
    return "[N]";
}