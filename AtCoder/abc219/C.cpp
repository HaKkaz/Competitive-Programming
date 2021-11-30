#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
 	string s; cin >> s;
 	int order[256];
 	for(int i=0 ; i<s.size() ; ++i) order[s[i]] = i;
 	int n; cin >> n ;
 	vector< string > v(n);
 	for(auto &x : v) cin >> x;
 	sort(v.begin() , v.end() , )
}