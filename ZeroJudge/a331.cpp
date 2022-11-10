#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define pb push_back
#define mp make_pair
#define Sz(x) (int)(x).size()
#define pii pair<int,int>
#define all(X) (X).begin(),(X).end()
#define F first
#define S second
#define endl cout<<'\n';
#define __IO ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
const int maxn = 1e6+5;
struct mo{
	int block , l , r , k , id; 
	bool operator<(const mo &a)const{
		if(block != a.block) return block < a.block;
		return r < a.r;
	}
};
vector<int> decc;
vector<mo> v;
vector<int> num , v2;
vector<pair<int,int> > ans;
int n , q , x , k , K , blockK;
int cnt[maxn] , cnt2[maxn];
void init(int MAXN){
	for(int i=0 ; i<MAXN ; ++i) cnt[i] = 0 , cnt2[i] = 0;
		decc.clear() , v.clear() , num.clear() , v2.clear() , ans.clear();
}
void run(int &l , int &r , int L , int R){
	while(l > L){
		--l;
		++cnt[decc[l]/blockK];
		++cnt2[decc[l]];
	}
	while(l < L){
		--cnt[decc[l]/blockK];
		--cnt2[decc[l]];
		++l;
	}
	while(r < R){
		++r;
		++cnt[decc[r]/blockK];
		++cnt2[decc[r]];
	}
	while(r > R){
		--cnt[decc[r]/blockK];
		--cnt2[decc[r]];
		--r;
	}
}

inline void findmax(int l , int r , int k , int id){
	for(int i=0 ; i<blockK ; ++i){
		if(cnt[i] < k) k -= cnt[i];
		else{
			for(int j=blockK*i ; j<=blockK*(i+1) ; ++j){
				if(cnt2[j] < k) k -= cnt2[j];
				else{
					ans.pb({id , v2[j]});
					return;
				}
			}
		}
	}
}

inline void solve(){
	int l= v[0].l , r = v[0].r ;
	for(int i=l ; i<=r ; ++i){
		++cnt[decc[i]/blockK];
		++cnt2[decc[i]];
	}
	findmax(l , r , v[0].k , v[0].id);
	for(int i=1 ; i<Sz(v) ; ++i){
		run(l , r , v[i].l , v[i].r);
		findmax(l , r , v[i].k , v[i].id);
	}
}

inline void discretization(int n){
	sort(all(v2)) , v2.resize(unique(all(v2))-v2.begin());
	for(int ii=0 ; ii<n ; ++ii){
		int pos = upper_bound(all(v2) , num[ii])-v2.begin();
		decc.pb(pos-1);
	}
}

signed main(){__IO
	int n  , q;
	blockK = sqrt(maxn)/2;
	while(cin >> n >> q){
		init(n);
		K = sqrt(n+100);
		for(int i=0 ; i<n ; ++i) cin >> x , num.pb(x) , v2.pb(x);
		discretization(n);
		for(int qq= 0 ; qq<q ; ++qq){
			int L , R , k;
			cin >> L >> R >> k;
			v.pb({L/K , --L , --R , k , qq});
		}
		sort(all(v));
		solve();
		sort(all(ans));
		for(auto &c : ans) cout << c.S << '\n';
	}
}