#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
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
	int n , w; cin >> n >> w;
	vector<int> arr(n);
	for(int &x : arr) cin >> x;

	vector<int> st;

	for(int i=0 ; i<n ; ++i){
		if(arr[i] <= w)
			st.emplace_back(arr[i]);
		for(int j=i+1 ; j<n ; ++j){
			if(arr[i] + arr[j] <= w)
				st.emplace_back(arr[i] + arr[j]);
			for(int k=j+1 ; k<n ; ++k){
				if(arr[i] + arr[j] + arr[k] <= w)
					st.emplace_back(arr[i] + arr[j] + arr[k]);
			}
		}
	}

	sort(ALL(st)) , st.resize(unique(ALL(st)) - st.begin());

	int ans = 0  ;
	for(auto &x : st) ans += x <= w;
	cout << ans << '\n';
}