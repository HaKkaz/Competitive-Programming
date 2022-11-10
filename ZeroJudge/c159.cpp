#include"bits/stdc++.h"
#define pb push_back
#define mp make_pair
#define int long long
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define rz(x) resize(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define endl cout<<'\n';
#define LINE cout<<"--------------------------\n";
#define loli ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
vector<int> v;
int ans;
inline void latina(){
	loli;
	int n; cin >> n ;
	v.resize(n);
	for(int i=0 ; i<n ; ++i) cin >> v[i];
	for(int i=0 ; i<n ; ++i){
		bool tag = 1;
		for(int j=0 ; j<n and tag ; ++j){
			for(int k=j+1 ; k<n and tag ; ++k){
				if(j==i or i==k) continue;
				if(v[i] == v[k]+v[j]) ++ans,tag=0;
			}
		}
	}
	cout << ans << '\n';
}
signed main(){latina();}