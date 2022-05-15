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
	int n ;
	cin >> n ; 
	vector<int> a(n);
	set<int> st;

	int zero = 0;
	for(int i=0 ; i<n ; ++i){
		cin >> a[i];
		zero += (a[i] == 0);
		st.insert(a[i]);
	}
	if(zero == 0 && (int)st.size() == n){
		cout << n + 1 << '\n';
	}
	else{
		cout << n - zero << '\n';
	}

}

signed main(){
	fast;
	int t=1;
	cin >> t;
	while(t--){
		solve();
	}
}