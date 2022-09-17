#include<bits/stdc++.h>
#define F first
#define S second
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(false),cin.tie(0);
#define endl cout<<'\n';
using namespace std;
int ans[15][15] , tmp[15][15] , n , m , q ;
vector<bool> v;
inline void copy(){
	for(int i=0 ; i<n ; ++i){
		for(int j=0 ; j<m ; ++j)
			ans[i][j] = tmp[i][j];
	}
}
inline void ze(){
	for(int i=0 ; i<n ; ++i){
		for(int j=0 ; j<m ; ++j){
			tmp[m-j-1][i] = ans[i][j];
		}
	}
	swap(n , m);
	copy();
}
inline void on(){
	for(int i=0  ; i<n ; ++i){
		for(int j=0 ; j<m ; ++j){
			tmp[n-i-1][j] = ans[i][j];
		}
	}
	copy();
}
signed main(){IOS;
	while(cin >> n >> m >> q){
		v.clear();
		for(int i=0 ; i<n ; ++i) 
			for(int j=0 ; j<m ; ++j) 
				cin >> ans[i][j];
		while(q--){
			int k; cin >> k;
			v.push_back(k);
		}
		for(int i=v.size()-1 ; i>=0 ; --i){
			if(v[i]) on();
			else ze();
		}
		cout << n << ' ' << m << '\n';
		for(int i=0 ; i<n ; ++i){
			for(int j=0 ; j<m ; ++j){
				cout << ans[i][j] <<" \n"[j==m-1];
			}
		}
	}
}