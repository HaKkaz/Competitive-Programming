#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define int long long
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
const int MAXN = 2e6+500;
struct
{
	pii p[MAXN];
	int sz=0;
	void push(pii x){
		p[sz++] = x;
		std::push_heap(p , p+sz);
	}
	void pop(){
		std::pop_heap(p , p+sz);
		--sz;
	}
	pii top(){return p[0];}
}a,b;
bitset<MAXN> vis;
signed main(){
	IOS;
	int opt , id=1;
	a.sz=b.sz=0;
	while(cin >> opt){
		if(opt == 1){
			++id;
			int n; cin >> n ;
			a.push({n , id});
			b.push({-n , id});
		}
		if(opt == 2){
			while(a.sz && vis[a.top().S]) a.pop();
			cout << a.top().F << '\n';
			vis[a.top().S] = 1;
		}
		if(opt == 3){
			while(b.sz && vis[b.top().S]) b.pop();
			cout << -b.top().F << '\n';
			vis[b.top().S] = 1;
		}
	}
}