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
	int n,q ; cin >> n >> q;
	vector<int> a(n+1);
	for(int i=1 ; i<=n ; ++i) cin >> a[i];

	int sum = accumulate(ALL(a) , 0ll);
	int all=0;
	set<int> st;
	for(int i=1 ; i<=n ; ++i) st.insert(st.end() , i);
	while(q--){
		int opt; cin >> opt;
		if(opt == 1){
			int i , k; cin >> i >> k;
			if(st.count(i)){
				sum -= a[i];
				sum += k;
				a[i] = k;
			}
			else{
				sum -= all;
				sum += k;
				a[i] = k;
				st.emplace(i);
			}
		}
		else{
			cin >> all;
			st.clear();
			sum = all * n;
		}
		cout << sum << '\n';
	}
}