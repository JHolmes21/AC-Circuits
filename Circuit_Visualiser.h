#ifndef CIRCUITVIS_H
#define CIRCUITVIS_H
#include "Component.h"
class CircuitVisualiser {
public:
    void add_component_serial(std::shared_ptr<Component> component);
    void add_component_parallel(std::shared_ptr<Component> component);
    void display() const;
private:
    std::string circuit_representation;
};

#endif
