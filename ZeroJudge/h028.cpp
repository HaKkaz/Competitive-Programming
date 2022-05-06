#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ft first
#define sd second
using ll = long long;
using ld = long double;

const int MAXN = 1e5+50;
const int INF = 1e9+50000;

//linked list
struct node{
	int p , h;
	bool vis;
	node *next , *prev;
	node(){}
	node(int _p , int _h):p(_p) , h(_h) , vis(false){
		next = prev = nullptr;
	}
	bool check(){
		bool ok = false;
		ok |= prev!=nullptr && p-h >= prev->p;
		ok |= next!=nullptr && p+h <= next->p;
		return ok & !vis;
	}
	void remove(){
		if(prev) prev->next = next ? next : nullptr;
		if(next) next->prev = prev ? prev : nullptr;
	}
}*tree[MAXN];

signed main(){
	fast;
	int n , L; cin >> n >> L;
	vector<int> p(n);
	vector<int> h(n);
	for(int &x : p) cin >> x;
	for(int &x : h) cin >> x;

	tree[0] = new node(0 , INF);
	tree[n+1] = new node(L , INF);
	for(int i=1 ; i<=n ; ++i){
		tree[i] = new node(p[i-1] , h[i-1]);
	}
	for(int i=0 ; i<=n+1 ; ++i){
		if(i-1 >=   0) tree[i]->prev = tree[i-1];
		if(i+1 <= n+1) tree[i]->next = tree[i+1];
	}

	queue<node*> q;
	for(int i=1 ; i<=n ; ++i){
		if(tree[i]->check()){
			q.emplace(tree[i]);
			tree[i]->vis = true;
		}
	}


	int mxh = 0 , cnt = 0;
	while(q.size()){
		node *cur = q.front();
		q.pop();
		//update answer
		mxh = max(mxh , cur->h);
		++cnt;
		cur->remove();

		//BFS
		if(cur->prev && cur->prev->check()){
			q.emplace(cur->prev);
			cur->prev->vis = true;

		}
		if(cur->next && cur->next->check()){
			q.emplace(cur->next);
			cur->next->vis = true;
		}
	}

	cout << cnt << '\n';
	cout << mxh << '\n';
}