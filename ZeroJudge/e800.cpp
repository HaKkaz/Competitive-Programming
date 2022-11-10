#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n; cin >> n;
    vector< pair<long double,string> > v(n);
    for(int i=0 ; i<n ; ++i){
    	string s; cin >> s;
    	long double a,b,c,d;
    	cin >> a >> b >> c >> d;
    	v[i] = make_pair(-a*c*d/b,s);
    }
    stable_sort(v.begin(),v.end());
    for(auto &c : v) cout << c.second << '\n';
}