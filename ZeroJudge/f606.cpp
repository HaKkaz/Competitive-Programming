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
	int n,m,k;
	cin >> n >> m >> k ;
	vector< vector<int> > w(n , vector<int> (m , 0));
	for(int i=0 ; i<n ; ++i)for(int j=0 ; j<m ; ++j) cin >> w[i][j];
	long long ans = 2e18;
	while(k--){
		int cnt = 0;
		vector<int> pos(n);
		for(int i=0 ; i<n ; ++i) cin >> pos[i];
		vector< vector<int> > tot(m , vector<int> (m , 0));
		for(int i=0 ; i<n ; ++i){
			for(int j=0 ; j<m ; ++j){
				tot[pos[i]][j] += w[i][j];
			}
		}
		for(int i=0 ; i<m ; ++i){
			for(int j=0 ; j<m ; ++j){
				if(i == j) cnt += tot[i][j];
				else if(tot[i][j] >= 1000) cnt += 3000 + (tot[i][j]-1000)*2;
				else cnt += tot[i][j] * 3;
			}
		}
		ans = min(ans , cnt);
	}
	cout << ans << '\n';
}