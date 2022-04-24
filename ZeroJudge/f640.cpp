#include<bits/stdc++.h>
#define int long long
using namespace std;
string str;
stringstream ss;
int f();
int g();
int h();
void do_what(int &who){
    ss >> str;
    if(str == "f") who = f();
    else if(str == "g") who = g();
    else if(str == "h") who = h();
    else who = stoi(str);
}
int f(){
    int x;
    do_what(x);
    return 2 * x - 3;
}
int g(){
    int x , y;
    do_what(x);
    do_what(y);
    return 2 * x + y - 7;
}
int h(){
    int x , y , z;
    do_what(x);
    do_what(y);
    do_what(z);
    return 3 * x - 2 * y + z;
}
signed main(){
    getline(cin , str) , ss << str , ss >> str;
    if(str == "f") cout << f() << '\n';
    if(str == "g") cout << g() << '\n';
    if(str == "h") cout << h() << '\n';
}