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
const int maxn = 1005;
int bit[1005] , ans[10005];
void upd(int x){
	for(;x<maxn;x+=(x&(-x)))
		bit[x]++;
}
int qry(int x){
	int res = 0;
	for(;x;x-=(x&(-x)))
		res += bit[x];
	return res;
}
struct T
{
	int x , y , id;
	bool operator < (const T &a)const{
		return x < a.x;
	}
};
vector<pii> v[1005];
inline void latina(){
	//loli;
	int n; 
	while(cin >> n){
		fill(bit,bit+maxn,0);
		for(int i=0 ; i<=1000 ; ++i) v[i].clear();
		for(int i = 0,x,y ; i<n  ; ++i){
			cin >> x >> y;
			v[x].push_back({y , i});
		}
		for(int i=1 ; i<=1000 ; ++i){
			for(auto &c : v[i]){
				ans[c.S] = qry(c.F-1);
			}
			for(auto &c : v[i]){
				upd(c.F);
			}
		}
		for(int i=0 ; i<n ; ++i) cout << ans[i] <<'\n';
	}
}
signed main(){latina();}