#include "Component_Library.h"

void ComponentLibrary:: add_component(const std::string& name, const std::shared_ptr<Component>& component) {
    library[name] = component;
}

std::shared_ptr<Component> ComponentLibrary:: get_component(const std::string& name) const {
    auto it = library.find(name);
    if (it == library.end()) {
        throw std::runtime_error("Component not found in the library.");
    }
    return it->second;
}