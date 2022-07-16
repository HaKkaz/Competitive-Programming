#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
// #define int long long
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define _ <<' '<<
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
#define tiii tuple<int,int,int>
using ll = long long;
using ld = long double;
using pii = pair<int,int>;

signed main(){
	fast;
	int n , q;
	cin >> n >> q;
	string s; cin >> s;

	int st = 0 ;
	int sz = s.size();
	while(q--){
		int opt , x; cin >> opt >> x;
		if(opt == 1){
			st = (st - x + sz) % sz ;
		}
		else{
			cout << s[(st + x - 1 + sz)%sz] << '\n'; 
		}
	}
}