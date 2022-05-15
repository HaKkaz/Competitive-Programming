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

void solve(){
	int n ; cin >> n ;
	string s; cin >> s;
	vector<int> dp(n,0);
	int diff = 0 ;
	char lst = '2';
	int ans = 1;
	for(int i=0 ; i<n ; i+=2){
		if(s[i] != s[i+1]){
			diff++;
		}
		else{
			if(lst != '2' && s[i] != lst) ++ans , lst = s[i];
			else lst = s[i];
		} 
	}
	cout << diff << ' ' << ans << '\n';
}

signed main(){
	fast;
	int t=1;
	cin >> t;
	while(t--){
		solve();
	}
}