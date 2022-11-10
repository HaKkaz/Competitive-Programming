#include"bits/stdc++.h"
#define pb push_back
#define sz(x) (int)(x).size()
#define loli ios::sync_with_stdio(false),cin.tie(0);
using namespace std;struct stk
{
	int l , r , a[100005];
	inline void clear(){l=50006,r=50005;}
	inline void pop_back(){r--;}
	inline void pop_front(){l++;}
	inline int front(){return a[l];}
	inline int back(){return a[r];}
	inline int size(){return r-l+1;}
	inline void push_back(int x){a[++r]=x;}
	inline void push_front(int x){a[--l]=x;}
	inline void all(){
		for(int i=l ; i<=r ; ++i) cout << a[i] << ' ';
	}
};
vector<int> v;
stk big , small , dq;
int sum , n , ans;
bitset<5005> vis;
inline void latina(){
	int t; cin >> t;
	while(t--){
		ans = 0;
		cin >> n ;
		v.resize(n);
		for(int i=0 ; i<n ; ++i) cin >> v[i];
		for(int h=2 ; h<=n ; ++h){
			dq.clear() , big.clear() , small.clear() , sum = 0;
			vis.reset();
			for(int i=0 ; i<n ; ++i){
				//fixed
				vis[v[i]] = 1;
				if(sz(dq) >= h) vis[dq.front()]=0;
				while(sz(big) && (!vis[big.back()] or big.back() < v[i])) big.pop_back();
				while(sz(small) && (!vis[small.back()] or small.back() > v[i])) small.pop_back();
				while(sz(big) && (!vis[big.front()] or (sz(dq)>=h and big.front() == dq.front()))) big.pop_front();
				while(sz(small) && (!vis[small.front()] or (sz(dq)>=h and small.front() == dq.front()))) small.pop_front();
				//enqueue
				dq.push_back(v[i]);
				big.push_back(v[i]);
				small.push_back(v[i]);
				if(sz(dq) > h) dq.pop_front();
				//
				int mx = big.front() , mn = small.front();
				int MX = max(dq.front() , dq.back()) , MN = min(dq.front() , dq.back());
				int hh = mx - mn + 1;
				if(sz(dq) == h and h == hh and MX == mx and MN == mn){
					++ans;
				}
			}
		}
		cout << ans << '\n';
	}
}
signed main(){loli;latina();}