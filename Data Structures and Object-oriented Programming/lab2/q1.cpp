#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Student {
public:
    Student() { }
    Student(string _first_name , string _last_name , string _dormitory , string _ID):
        first_name(_first_name) , last_name(_last_name) , dormitory(_dormitory) , ID(_ID){}

    string generate_address(){
        return "1001 University Road, Hsinchu, Taiwan 300, ROC, dorm " + dormitory + ", (" + ID + ") " + first_name + " " + last_name ;
    }

    //Please implement the remain class
private:
    string first_name;
    string last_name;
    string dormitory;
    string ID;
};


int main() {
    Student mStudent;
    /* Enter your code here. Read input from STDIN */
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    mStudent = Student(a,b,c,d);
    cout << mStudent.generate_address() << endl;
    return 0;
}