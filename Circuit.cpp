#include "Circuit.h"
#include "Nested_Circuit.h"

void Circuit::add_component_serial(const std::shared_ptr<Component>& component) {
    components.push_back(component);
    impedance += component->get_impedance();
}

void Circuit::add_component_parallel(const std::shared_ptr<Component>& component) {
    components.push_back(component);
    impedance = (impedance * component->get_impedance()) / (impedance + component->get_impedance());
}

std::complex<double> Circuit::get_impedance() const {
    return impedance;
}

double Circuit::get_magnitude() const {
    return std::abs(impedance);
}

double Circuit::get_phase_difference() const {
    return std::arg(impedance);
}

void Circuit::print_impedances() const {
    int component_count = 1;
    for (const auto& component : components) {
        std::cout << "-------------------------------------------------------------\n";
        std::cout << "Impedance of component " << component_count << ":\n";
        std::cout << "   Impedance: " << component->get_magnitude() << " Ohms\n";
        std::cout << "   Phase Difference: " << component->get_phase_difference() << " Radians\n";
        component_count++;

        // Check if this component is a nested circuit
        auto nested_circuit = std::dynamic_pointer_cast<NestedCircuit>(component);
        if (nested_circuit) {
            nested_circuit->print_impedances();
        }
    }
}