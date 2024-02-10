#include <iostream>
#include <string>

using namespace std;

int main(){
    int age,height;
    string name,gender;

    cout << "Enter your name : " << endl;
    getline(cin,name);

    cout << "Enter your gender : " << endl;
    getline(cin,gender);

    cout << "Enter your age : " << endl;
    cin >> age;

    cout << "Enter your height : " << endl;
    cin >> height;

    cout << "name :" << name <<endl;
    cout << "gender :" << gender <<endl;
    cout << "age :" << age <<endl;
    cout << "height :" << height <<endl;

    return 0;
}