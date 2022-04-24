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
	int n , m ; cin >> n >> m;
	vector<int> h(n) , w(m);
	for(int i=0 ; i<n ; ++i) cin >> h[i];
	for(int i=0 ; i<m ; ++i) cin >> w[i];
	int l = 1 , r = 1000000001;
	while(l < r){
		int mid = (l+r)/2;
		int cnt = 0 , top = 0;
		for(int i=0 ; i<n ; ++i){
			if(h[i]>=mid)++cnt;
			else cnt=0;
			if(top < m and cnt == w[top]) ++top , cnt=0;
		}
		if(top == m) l = mid+1;
		else r = mid;
	}
	cout << l-1 << '\n';
}