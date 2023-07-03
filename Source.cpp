#include <iostream>
#include <complex>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <algorithm>
#include "Constants.h"
#include "Component.h"
#include "Circuit.h"
#include "Nested_Circuit.h"
#include "Resistor.h"
#include "Capacitor.h"
#include "Inductor.h"
#include "Component_Library.h"
#include "Diode.h"
#include "Circuit_Visualiser.h"
#include "Input_Validation.h"
#include "Display_Complex.h"
#include "Transistor.h"


int main() {
    // Create a component library
    ComponentLibrary library;
    Circuit circuit;
    CircuitVisualiser visualiser;

    while (true) {
        std::cout << "\nOptions:\n"
            << "1. Add a component in series\n"
            << "2. Add a component in parallel\n"
            << "3. Show circuit impedance\n"
            << "4. Display Circuit\n"
            << "5. Exit\n"
            << "Type the number corresponding to the option you want to select\n";
        int choice = get_menu_option();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore any leftover input

        if (choice == 5) {
            break;
        }
        if (choice == 4) {
            visualiser.display();
        }

        if (choice == 1 || choice == 2) {
            std::cout << "\nChoose the component type:\n"
                << "1. Resistor\n"
                << "2. Capacitor\n"
                << "3. Inductor\n"
                << "4. Diode\n"
                << "5. Transistor\n"
                << "6. Nested Circuit\n"
                << "Type the number corresponding to the option you want to select\n";
            int component_type = get_menu_option();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore any leftover input

            std::shared_ptr<Component> component;

            if (component_type == 1) {
                std::cout << "Enter the resistance value (ohms): ";
                double resistance = get_positive_number();
                component = std::make_shared<Resistor>(resistance);
            }
            else if (component_type == 2) {
                std::cout << "Enter the capacitance value (farads): ";
                double capacitance = get_positive_number();
                std::cout << "Enter the frequency (Hz): ";
                double frequency = get_positive_number();
                component = std::make_shared<Capacitor>(capacitance, frequency);
            }
            else if (component_type == 3) {
                std::cout << "Enter the inductance value (henrys): ";
                double inductance = get_positive_number();
                std::cout << "Enter the frequency (Hz): ";
                double frequency = get_positive_number();
                component = std::make_shared<Inductor>(inductance, frequency);
            }
            else if (component_type == 4) {
                double forward_voltage;
                std::cout << "Enter the diode forward voltage (volts): ";
                std::cin >> forward_voltage;
                component = std::make_shared<Diode>(forward_voltage);
            }
            else if (component_type == 5) {
                double R_eff;
                std::cout << "Enter the transistor's effective resistance: ";
                std::cin >> R_eff;
                component = std::make_shared<Transistor>(R_eff);
            }
            if (component_type == 6) {
                std::shared_ptr<NestedCircuit> nested_circuit = std::make_shared<NestedCircuit>();

                while (true) {
                    std::cout << "\nOptions for nested circuit:\n"
                        << "1. Add a component in series\n"
                        << "2. Add a component in parallel\n"
                        << "3. Finish nested circuit\n"
                        << "Enter your choice: ";
                    int nested_choice;
                    std::cin >> nested_choice;

                    if (nested_choice == 3) {
                        break;
                    }

                    if (nested_choice == 1 || nested_choice == 2) {
                        std::cout << "\nChoose the component type:\n"
                            << "1. Resistor\n"
                            << "2. Capacitor\n"
                            << "3. Inductor\n"
                            << "4. Diode\n"
                            << "5. Transistor\n"
                            << "Enter your choice: ";
                        int nested_component_type;
                        std::cin >> nested_component_type;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore any leftover input

                        std::shared_ptr<Component> component;

                        if (nested_component_type == 1) {
                            std::cout << "Enter the resistance value (ohms): ";
                            double resistance = get_positive_number();
                            component = std::make_shared<Resistor>(resistance);
                        }
                        else if (nested_component_type == 2) {
                            std::cout << "Enter the capacitance value (farads): ";
                            double capacitance = get_positive_number();
                            std::cout << "Enter the frequency (Hz): ";
                            double frequency = get_positive_number();
                            component = std::make_shared<Capacitor>(capacitance, frequency);
                        }
                        else if (nested_component_type == 3) {
                            std::cout << "Enter the inductance value (henrys): ";
                            double inductance = get_positive_number();
                            std::cout << "Enter the frequency (Hz): ";
                            double frequency = get_positive_number();
                            component = std::make_shared<Inductor>(inductance, frequency);
                        }
                        else if (nested_component_type == 4) {
                            double forward_voltage;
                            std::cout << "Enter the diode forward voltage (volts): ";
                            std::cin >> forward_voltage;
                            component = std::make_shared<Diode>(forward_voltage);
                        }
                        else if (nested_component_type == 5) {
                            double R_eff;
                            std::cout << "Enter the transistor's effective resistance: ";
                            std::cin >> R_eff;
                            component = std::make_shared<Transistor>(R_eff);
                        }

                        if (nested_choice == 1) {
                            nested_circuit->add_component_serial(component);
                            std::cout << "Component added in series.\n";
                        }
                        else {
                            nested_circuit->add_component_parallel(component);
                            std::cout << "Component added in parallel.\n";
                        }
                    }
                    else {
                        std::cout << "Invalid choice. Please try again.\n";
                    }
                }

                component = nested_circuit;
            }
            if (choice == 1) {
                circuit.add_component_serial(component);
                visualiser.add_component_serial(component);
                std::cout << "Component added in series.\n";
            }
            else {
                circuit.add_component_parallel(component);
                visualiser.add_component_parallel(component);
                std::cout << "Component added in parallel.\n";
            }
        }
        else if (choice == 3) {
        std::cout << "The components are listed in the order you created them:\n";
        circuit.print_impedances();
        std::cout << "-------------------------------------------------------------\n";
        std::cout << "-------------------------------------------------------------\n";
        std::cout << "Total circuit complex impedance: ("; 
        print_complex(circuit.get_impedance());
        std::cout << ") Ohms\n";
        std::cout << "   Impedance magnitude: " << circuit.get_magnitude() << " Ohms\n";
        std::cout << "   Phase Difference: " << circuit.get_phase_difference() << " Radians\n";
        std::cout << "-------------------------------------------------------------\n";
        std::cout << "-------------------------------------------------------------\n";
        }
        else if (choice != 4) {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
