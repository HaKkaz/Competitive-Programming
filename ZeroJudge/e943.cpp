#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#define int long long
#define pb push_back
#define MP make_pair
#define pii pair<int,int>
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = "  << x << '\n';
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
const int maxn=22;
int ok[maxn][maxn];
signed main(){
	IOS;
	int n , m; cin >> n >> m;
	int ans = 0 ;
	while(m--){
		int a,b; cin >> a >> b , --a , --b;
		ok[a][b] = ok[b][a] = 1;
	}
	for(int i=1 ; i<(1<<n) ; ++i){
		bool tag=1;
		int cnt = 0 ;
		for(int j=0 ; j<n && tag ; ++j){
			if(i>>j&1) ++cnt;
			for(int k=j+1 ; k<n && tag ; ++k){
				if((i>>j&1) and (i>>k&1) and !ok[j][k]) tag=0;
			}
		}
		if(tag) ans = max(ans , cnt);
	}
	cout << ans << '\n';
}