#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#define int long long
#define F first
#define S second
using namespace std;
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n , l , r , ans; 
	while(cin >> n){
		vector<pair<int,int>> p;
		for(int i=0 ; i<n ; ++i){
			cin >> l >> r;
			if(l>r) swap(l , r);
			p.push_back({l,r});
		}
		sort(p.begin(),p.end());
		l = 0, r = 0 , ans = 0;
		for(int i=0 ; i<(int)p.size() ; ++i){
			if(p[i].F > r) ans += (r-l) , l = p[i].F , r = p[i].S;
			else if(p[i].S > r) r = p[i].S;
		}
		ans += (r-l);
		cout << ans <<'\n';
	}
}