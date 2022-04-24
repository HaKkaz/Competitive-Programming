#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#define int long long
#define pb push_back
#define MP make_pair
#define pii pair<int,int>
#define F first
#define S second
#define SZ(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = "  << x << '\n';
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
signed main(){
	IOS;
	int n ;
	cin >> n ;
	vector<pii> v(n);
	for(int i=0 ; i<n ; ++i){
		cin >> v[i].F >> v[i].S;
	}
	sort(all(v));
	vector<int> LIS;
	for(int i=0 ; i<n ; ++i){
		auto it = upper_bound(all(LIS),v[i].S);
		if(it == LIS.end()) LIS.push_back(v[i].S);
		else *it = v[i].S;
	}
	cout << SZ(LIS) << '\n';
}