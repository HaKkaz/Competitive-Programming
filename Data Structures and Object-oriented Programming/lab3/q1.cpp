#include <cstdio>
#include <vector>
#include <iostream>
#include <string> 
using namespace std;
//TODO:Finish the class, you can add thing you need
class Student {
public:
    Student(string _name , string _text){
        WriteBlackboard(_name , _text);
    };
    static string SeeBlackBoard(){
        return _BlackBoard;
    };
private:
    static string _BlackBoard;
    static void WriteBlackboard(string x , string y){
        _BlackBoard  += x + ":" + y + "\n";
    };
};
string Student::_BlackBoard = "";
int main() {  
    string name,text;
    vector<Student> Students;
    while(cin>>name>>text){
    //TODO
        Students.push_back(Student(name , text));
    } 
    cout <<Students.size()<<endl<<Student::SeeBlackBoard();
    return 0;
}