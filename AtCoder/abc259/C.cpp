#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
#define int long long
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
	int t=1;
	// cin >> t;
	while(t--){
		string s,t;
		cin >> s >> t;
		string ans = "Yes";

		while(s.size() && t.size()){
			if(s.back() == t.back()){
				char x = s.back();
				int i = 0;
				int j = 0;
				while(s.size() && s.back() == x) s.pop_back() , ++i;
				while(t.size() && t.back() == x) t.pop_back() , ++j;
				if((i == 1 && j != 1) || i > j) ans = "No";
			}
			else{
				ans = "No";
				break;
			}
		}
		if(s.size() || t.size()) ans = "No";

		cout << ans << '\n';
	}
}