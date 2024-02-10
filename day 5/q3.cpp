#include <iostream>
#include <cmath>

using namespace std;

class Triangle {
private:
    double side1, side2, side3;

public:
    Triangle(double a, double b, double c) : side1(a), side2(b), side3(c) {}

    double calculateArea() {
        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double calculatePerimeter() {
        return side1 + side2 + side3;
    }

    void printDetails() {
        cout << "Area of the Triangle: " << calculateArea() << " square units" << endl;
        cout << "Perimeter of the Triangle: " << calculatePerimeter() << " units" << endl;
    }
};

int main() {
    Triangle triangleObject(3.0, 4.0, 5.0);

    triangleObject.printDetails();

    return 0;
}
