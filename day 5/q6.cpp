#include<iostream>
#include<string>

using namespace std;

class Employee
{
private:
    string name;
    int year;
    string address;

public:
    void setDetails(string empName,int joinYear,string empAd)
    {
        name = empName;
        year = joinYear;
        address = empAd;
    }

    void printInfo()
    {
       cout << name << "\t";
       cout << year << "\t";
       cout << address << endl;
    }
    
};

int main() {
    Employee employee1, employee2, employee3;

    employee1.setDetails("Robert", 1994, "64C- WallsStreat");
    employee2.setDetails("Sam", 2000, "68D- WallsStreat");
    employee3.setDetails("John", 1999, "26B- WallsStreat");


    cout << "Name\tYear\tAddress" << endl;

    employee1.printInfo();
    employee2.printInfo();
    employee3.printInfo();

    return 0;
}

