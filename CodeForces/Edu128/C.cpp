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
	cin >> t;
	while(t--){
		string s; cin >> s;
		const int n = (int)s.size();
		deque<char> dq;
		int zero = 0;
		int one = count(ALL(s) , '1');
		int j = -1;
		int ans = 1e9;
		for(int i=0 ; i<n ; ++i){
			while(j + 1 < n && zero < one){
				one -= s[j+1] == '1';
				zero += s[j+1] == '0';
				++j;	
			}
			ans = min(ans , max(one , zero));
			one += s[i] == '1';
			zero -= s[i] == '0';
		}
		cout << ans << '\n';
	}
}