#include<bits/stdc++.h>
//#define test_
#define MP make_pair
#define pb push_back
#define S second
#define F first
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define pii pair<int,int>
#define et cout<<'\n';
#define rep(i , n) for(int mm=i ; mm<n ; ++mm)
using namespace std;
struct node
{
	node *l , *r;
	int key , pri , ls , rs , sz;
	bool rev;
	node(const int &x);
	inline void push_up(){
		sz = l->sz + r->sz + 1;
	}
	inline void push_rev();
}*nil = new node(0) , *root;
node::node(const int &x){
	key = x , pri = rand() , sz = 1 , l = r = nil , rev = false;
}
inline void node::push_rev(){
	if(!rev) return;
	l->rev ^= 1 , r->rev ^= 1;
	rev = 0;
	swap(l , r);
}
void split(node *o , node *&a , node *&b , int k){
	if(o == nil) return a=b=nil , void();
	if(o->rev) o->push_rev();
	if(o->l->sz < k){
		a = o;
		split(o->r , a->r , b , k-(o->l->sz)-1);
	}
	else{
		b = o;
		split(o->l , a , b->l , k);
	}
	o->push_up();
}
node *merge(node *a , node *b){
	if(a==nil or b==nil) return a==nil?b:a;
	if(a->pri < b->pri){
		if(a->rev) a->push_rev();
		a->r = merge(a->r , b);
		a->push_up();
		return a;
	}
	else{
		if(b->rev) b->push_rev();
		b->l = merge(a , b->l);
		b->push_up();
		return b;
	}
}
void dfs(node *now){
	if(now == nil) return;
	if(now->rev) now->push_rev();
	dfs(now->l);
	cout << now->key << ' ';
	dfs(now->r);
}
signed main(){
	nil->sz = 0 , root = nil;
	srand(time(0));
	int n , q;
	cin >> n >> q;
	for(int i=1 ; i<=n ; ++i) root = merge(root , new node(i));
	while(q--){
		int L , R;
		cin >> L >> R;
		node *a , * b , *c , *d;
		split(root , a , b , L-1);
		split(b , c , d , R - L + 1);
		c->rev ^= 1;
		root = merge(a , merge(c , d));
	}
	dfs(root) , et;
}