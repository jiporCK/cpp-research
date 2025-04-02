#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
private:
    std::string name;
    std::string type;
public:
    Shape(std::string name, std::string type);
    Shape();

    std::string getName() const;
    std::string getType() const;

    void setName(std::string name);
    void setType(std::string type);

    void display() const;

    // ~Shape();
};

#endif