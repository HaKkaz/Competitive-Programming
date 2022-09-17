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
	const int inf = 1e9;
	int s , t , n , m , r , cnt = 0 , mn = inf , SUM = 0;
	cin >> s >> t >> n >> m >> r;
	vector< vector<int> > a(s , vector<int>(t)) , b(n , vector<int>(m));
	for(int i=0 ; i<s ; ++i)for(int j=0 ; j<t ; ++j) cin >> a[i][j] , SUM += a[i][j];
	for(int i=0 ; i<n ; ++i)for(int j=0 ; j<m ; ++j) cin >> b[i][j];

	for(int i=0 ; i<n && i+s<=n ; ++i){
		for(int j=0 ; j<m && j+t<=m  ; ++j){
			//sub-matrix
			int dif = 0 , sum = 0;
			for(int ii=i ; ii<i+s ; ++ii){
				for(int jj=j ; jj<j+t ; ++jj){
					if(a[ii-i][jj-j] != b[ii][jj]){
						++dif;
					}
					sum += b[ii][jj];
				}
			}
			if(dif <= r){
				++cnt;
				if(abs(sum - SUM) < mn){
					mn = abs(sum - SUM);
				}
			}
		}
	}
	cout << cnt << '\n';
	cout << (cnt == 0 ? -1 : mn) << '\n';
}