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
	vector<int> ans;
	for(int i=1 ; i<100 ; ++i){
		ans.push_back(i);
		ans.push_back(i*100);
		ans.push_back(i*10000);
	}
	cout << ans.size() << '\n';
	sort(ALL(ans));
	for(int &x : ans) cout << x << ' ' ;
}