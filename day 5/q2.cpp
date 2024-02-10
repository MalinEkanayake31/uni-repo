#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    string name;
    int roll_no;
};

int main() {
    Student studentObject;
    studentObject.name = "John";
    studentObject.roll_no = 2;

    cout << "Name: " << studentObject.name << endl;
    cout << "Roll No: " << studentObject.roll_no << endl;

    return 0;
}
