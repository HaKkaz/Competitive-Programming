#include<bits/stdc++.h>
#define pb push_back
#define MP make_pair
#define pii pair<int,int>
#define F first
#define S second
#define SZ(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = "  << x << '\n';
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
const int maxn = 3e6;
struct node
{
	int id,weight,lc,rc;
	node(){id=weight=lc=rc=0;}
};
vector<node> Node;

void get_size(node &cur){
	if(!cur.lc && !cur.rc){
		return;
	}
	get_size(Node[cur.lc]);
	get_size(Node[cur.rc]);
	cur.weight += Node[cur.lc].weight;
	cur.weight += Node[cur.rc].weight;
}

int dfs(int w , node &cur){
	cur.weight += w;
	//is leaf
	if(!cur.lc && !cur.rc){
		return cur.id;
	}
	//not leaf
	if(Node[cur.lc].weight <= Node[cur.rc].weight){
		return dfs(w , Node[cur.lc]);
	}
	else{
		return dfs(w , Node[cur.rc]);
	}
}
vector<int> items;

signed main(){
	IOS;
	int n,m;
	cin >> n >> m ;
	Node.reserve((n<<1|1));
	Node.resize((n<<1|1));
	for(int i=1 ; i<2*n ; ++i) Node[i].id = i;
	for(int i=n ; i<2*n ; ++i) cin >> Node[i].weight;

	items.resize(m);
	for(int &x : items) cin >> x;

	for(int i=0 ; i<n-1 ; ++i){
		int a,b,c; cin >> a >> b >> c;
		Node[a].lc = b;
		Node[a].rc = c;
	}

	get_size(Node[1]);

	for(int i=0 ; i<m ; ++i){
		cout <<  dfs(items[i] , Node[1]) << " \n"[i==m-1];
	}
}