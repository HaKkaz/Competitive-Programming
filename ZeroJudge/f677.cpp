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
int f[1000005] ;
int Find(int x){
	return x == f[x] ? f[x] : f[x] = Find(f[x]);
}
void U(int a , int b){
	a = Find(a) , b = Find(b);
	if(a == b) return;
	f[b] = a;
}
signed main(){
	IOS;
	int n , m; cin >> n >> m;
	for(int i=0 ; i<n ; ++i) f[i]=i;
	while(m--){
		int a,b; cin >> a >> b;
		U(a,b);
	}
	int ans=0;
	for(int i=0 ; i<n ; ++i){
		if(Find(i) == Find(0)) ans++;
	}
	cout << ans << '\n';
}