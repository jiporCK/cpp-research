// C++ does not have a built-in interface keyword like java or c#,
// but an interface can be simulated using a pure abstract class (a class that only has pure virtual
// functions and no data members or implemented methods).

#include <iostream>
using namespace std;

class IShape {  // Naming convention: Prefix "I" to indicate an interface
public:
    virtual void draw() = 0;  // Pure virtual function
    virtual ~IShape() {}  // Virtual destructor to avoid memory leaks
};

class Circle : public IShape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

class Square : public IShape {
public:
    void draw() override {
        cout << "Drawing Square" << endl;
    }
};

int main() {
    IShape* shape1 = new Circle();
    IShape* shape2 = new Square();

    shape1->draw();  // Output: Drawing Circle
    shape2->draw();  // Output: Drawing Square

    delete shape1; // Free memory
    delete shape2;
}
