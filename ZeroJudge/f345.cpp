#include<bits/stdc++.h>
using namespace std;
int main(){vector<int> v; int n; cin >> n; for(int i=0,x ; i<n ; ++i) cin >> x , v.push_back(x); reverse(v.begin(),v.end()); for(int c : v) cout << c << ' '; cout << '\n';}