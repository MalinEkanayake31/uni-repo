#include <iostream>

using namespace std;

class Area {
private:
    double length, breadth;

public:
    void setDim(double l, double b) {
        length = l;
        breadth = b;
    }

    double getArea() {
        return length * breadth;
    }
};

int main() {
    Area rectangle;

    double userLength, userBreadth;
    cout << "Enter length of the rectangle: ";
    cin >> userLength;
    cout << "Enter breadth of the rectangle: ";
    cin >> userBreadth;

    rectangle.setDim(userLength, userBreadth);

    cout << "Area of the rectangle: " << rectangle.getArea() << " square units" << endl;

    return 0;
}
