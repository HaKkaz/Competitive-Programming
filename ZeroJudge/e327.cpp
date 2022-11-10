#include<bits/stdc++.h>
using namespace std;
int main(){
string str;
getline(cin , str);
int ans = 0;
for(int i=0; i<str.size() ; ++i) if(str[i]!=' ') ++ans;
cout <<ans<<'\n';
}