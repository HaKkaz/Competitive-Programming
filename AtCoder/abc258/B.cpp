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
int a[10][10];
int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,-1,-1,-1,0,1,1,1};
signed main(){
	fast;
	int n; cin >> n ; 
	for(int i=0 ; i<n ; ++i)
		for(int j=0 ; j<n ; ++j){
			char c; cin >> c;
			a[i][j] = c - '0';
		}

	int mx = 0 ;
	for(int i=0 ; i<n ; ++i){
		for(int j=0 ; j<n ; ++j){
			for(int k=0 ; k<8 ; ++k){
				int x = i , y = j , ret = 0;
				for(int z = 0 ; z < n ; ++z){
					ret = ret * 10 + (a[x][y]);
					x = (x + dx[k] + n) % n ;
					y = (y + dy[k] + n) % n ;
				}
				mx = max(mx , ret);
			}
		}
	}
	cout << mx << '\n';
}