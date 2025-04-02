#include <iostream>

#include "Shape.h"

Shape::Shape() : name(""), type("") {}

Shape::Shape(std::string name, std::string type) : name(name), type(type) {}

std::string Shape::getName() const {
    return name;
}

std::string Shape::getType() const {
    return type;
}

void Shape::setName(std::string name) {
    this->name = name;
}

void Shape::setType(std::string type) {
    this->type = type;
}

void Shape::display() const {
    std::cout << "Shape name: " << name << ", and Shape type: " << type << std::endl;
}