#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define cerr if(0);else cerr
#define _ << ' ' << 
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
using ll = long long ;
using ld = long double ;
using pii = pair<int,int> ;

signed main(){
	fast;

    string s; cin >> s;
    s.pop_back();
    s.pop_back();
    if(s.back() >= '5') s.pop_back() , s.pop_back() , cout << (stoi(s) + 1);
    else s.pop_back() , s.pop_back() , cout << s ;
    ;
}

