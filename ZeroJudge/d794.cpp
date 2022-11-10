#include"bits/stdc++.h"
#define pb push_back
#define int unsigned long long
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
const int maxn = 1e5+500;
int bit[maxn],top,n;
map<int,int> mp;
void upd(int i){
	for(;i<=n;i+=(i&(-i))) bit[i]++;
}
int qry(int i){
	int res = 0 ;
	for(;i;i-=(i&(-i))) res += bit[i];
	return res;
}
vector<int> v,ori;
inline void latina(){
	loli;
	while(cin >> n){
		top=1;
		mp.clear(),v.clear(),ori.clear();
		fill(bit,bit+maxn,0);
		for(int i=0,x ; i<n ; ++i){
			cin >> x;
			v.push_back(x);
		}
		ori=v;
		sort(all(v));
		for(auto &c : v) if(mp[c]==0) mp[c]=top++;
		for(int i=0 ; i<n ; ++i){
			upd(mp[ori[i]]);
			//cout << ori[i] << ' ' << mp[ori[i]] << '\n';
			cout << (i+1) - qry(mp[ori[i]]-1) << '\n';
		}
	}
}
signed main(){latina();}