#include<bits/stdc++.h>	
#pragma GCC optimize ("Ofast")
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int,int>
#define all(X) (X).begin(),(X).end()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define et cout<<'\n';
#define __IO ios::sync_with_stdio(false),cin.tie(0);
#define rep(a , b , c) for(int c = a ; c < b ; ++c)
using namespace std;
struct T
{
	int a , b , w;
	bool operator<(const T &x)const{
		return w > x.w;
	}
};
const int maxn = 1e6+5;
int f[maxn] , child[maxn];
int F(int x){
	if(x == f[x]) return x;
	return f[x] = F(f[x]);
}
bool U(int a , int b){
	a = F(a) , b = F(b);
	if(a == b) return false;
	if(a > b) swap(a , b);
	f[b] = a;
	child[a] += child[b];
	return true;
}
priority_queue<T> pq;
int main(){__IO
	int n , m ;
	long long ans = 0;
	while(cin >> n >> m){
		ans = 0;
		for(int i=0 ; i<=n ; ++i) f[i] = i , child[i] = 1;
		rep(0 , m , i){
			int a , b , w;
			cin >> a >> b >> w;
			pq.push({a , b , w});
		}

		while(pq.size()){
			int a = pq.top().a , b = pq.top().b , w = pq.top().w;
			pq.pop();
			if(U(a , b)) ans += w;
		}
		if(child[0] == n) cout << ans << '\n';
		else cout << -1 << '\n';
	}
}