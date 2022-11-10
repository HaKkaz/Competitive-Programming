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
	int n; cin >> n;
	char a[n][n];
	bool vis[n][n];
	for(int i=0 ; i<n ; ++i)
		for(int j=0 ; j<n ; ++j)
			cin >> a[i][j] , vis[i][j] = a[i][j] == '*';

	for(int i=0 ; i<n ; ++i)
		for(int j=0 ; j<n ; ++j){
			if(vis[i][j] == 1){
				for(int k=0 ; k<n ; ++k){
					a[i][k] = a[k][j] = '*';
				}
			}
		}

	for(int i=0 ; i<n ; ++i){
		for(int j=0 ; j<n ; ++j){
			cout << a[i][j];
		}		
		cout << '\n';
	}
}