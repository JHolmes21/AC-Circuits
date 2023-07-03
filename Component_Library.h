#ifndef COMPLIB_H
#define COMPLIB_H
#include "Component.h"
class ComponentLibrary {
private:
    std::map<std::string, std::shared_ptr<Component>> library;

public:
    void add_component(const std::string& name, const std::shared_ptr<Component>& component);

    std::shared_ptr<Component> get_component(const std::string& name) const;
};

#endif
