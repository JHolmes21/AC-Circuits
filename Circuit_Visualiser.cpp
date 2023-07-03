#include "Circuit_Visualiser.h"
//This code creates the visual representation of the circuit

void CircuitVisualiser::add_component_serial(std::shared_ptr<Component> component) {
    if (circuit_representation.empty()) {
        circuit_representation += " ";
    }
    else {
        circuit_representation += " --- ";
    }
    circuit_representation += component->representation();
}

void CircuitVisualiser::add_component_parallel(std::shared_ptr<Component> component) {
    std::string parallel_bar = "|";
    std::string new_representation;
    std::istringstream iss(circuit_representation);
    std::string line;

    // Add parallel bars to the existing representation
    while (std::getline(iss, line)) {
        new_representation += parallel_bar + line + parallel_bar + "\n";
    }

    // Add the new component in parallel
    new_representation += parallel_bar + component->representation() + parallel_bar;

    circuit_representation = new_representation;
}
void CircuitVisualiser::display() const {
    std::cout << circuit_representation << std::endl;
}
