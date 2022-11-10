#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
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

signed main(){
	fast;
	int n,m,q; cin >> n >> m >> q;
	deque< deque<int> > seats(n , deque<int>(m));
	for(int i=0,id=1 ; i<n ; ++i){
		for(int j=0 ; j<m ; ++j,++id){
			seats[i][j] = id;
		}
	}

	for(int j=2 ; j<=q ; ++j){
		if(j % 2 == 1){
			seats.push_front(seats.back());
			seats.pop_back();
		}
		else{
			for(int i=0 ; i<n ; ++i){
				seats[i].push_front(seats[i].back());
				seats[i].pop_back();
			}
		}
	}
	for(int i=0 ; i<n ; ++i){
		for(int j=0 ; j<m ; ++j){
			cout<<seats[i][j]<<' ';
		}
		cout << '\n';
	}

}