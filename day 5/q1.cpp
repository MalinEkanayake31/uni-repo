#include<iostream>

using namespace std;

class Shape
{
protected:
    float width,height;

public:

    Shape(float a=0,float b=0) : width(a) , height(b) {}

    void set_data(float a, float b)
    {
        width = a;
        height = b;
    }

    float calculateTriangleArea()
    {
        return 0.5 * width * height;
    }

    float calculateRectangleArea()
    {
        return width * height;
    }
};

int main()
{
    Shape shapeObject(5.0, 8.0);

    cout << "Area of Triangle: " << shapeObject.calculateTriangleArea() << std::endl;
    cout << "Area of Rectangle: " << shapeObject.calculateRectangleArea() << std::endl;

    return 0;
}
