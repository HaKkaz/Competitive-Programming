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

set<int> pos[100005];
signed main(){
	fast;
	int n; cin >> n; 
	vector<int> a(n) , b(n);
	for(int i=0 ; i<n ; ++i){
		cin >> a[i];
	}
	for(int i=0 ; i<n ; ++i){
		cin >> b[i];
		pos[b[i]].insert(i);
	}
	for(int i=0 ; i<n ; ++i){
		int x = a[i];
		auto it = pos[x].lower_bound(i);
		int mn = 1e9;
		if(it != pos[x].end()){
			mn = min(mn , *it - i);
		}
		if(it != pos[x].begin()){
			mn = min(mn , i - *prev(it));
		}
		if(mn == 1e9) mn = -1;
		cout << mn << " \n"[i==n-1];
	}
}
