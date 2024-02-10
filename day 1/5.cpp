#include <iostream>

using namespace std;

int main() {
    const float PI = 3.14f; // Define the value of pi

    float radius, area, volume;

    // Prompt the user to input the radius of the sphere
    cout << "Enter the radius of the sphere: ";
    cin >> radius;

    // Calculate the area and volume of the sphere using the provided formulas
    area = 4 * PI * radius * radius;
    volume = (4.0f / 3.0f) * PI * radius * radius * radius;

    // Display the calculated area and volume
    cout << "\nArea of the sphere: " << area << endl;
    cout << "Volume of the sphere: " << volume << endl;

    return 0;
}
