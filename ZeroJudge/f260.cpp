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
int ans , fa[100000];
int Find(int x){
	if(x == fa[x]) return x;
	return fa[x] = Find(fa[x]);
}
void Union(int a , int b){
	a = Find(a) , b = Find(b);
	if(a == b) return;
	--ans;
	fa[b] = a;
}
signed main(){
	IOS;
	int n,k;
	while(cin >> n >> k ){
		ans = n;
		for(int i=0 ; i<=n ; ++i)fa[i]=i;
		while(k--){
			int a,b; cin >> a >> b;
			Union(a,b);
		}
		cout<<ans<<'\n';
	}
}