#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#define int long long
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
bitset<10000005> used;
int q[200005];
signed main(){
	IOS;
	int n , L;
	cin >> n >> L;
	used[0]=used[L]=1;
	for(int i=1 ; i<=n ; ++i){
		int pos , id;
		cin >> pos >> id ;
		q[id] = pos;
	}
	int ans=0;
	for(int i=1 ; i<=n ; ++i){
		int l=-1,r=-1;
		for(int j=q[i] ; j>=0 ; --j){
			if(used[j]) {l=j;break;}
		}
		for(int j=q[i] ; j<=L ; ++j){
			if(used[j]) {r=j;break;}
		}
		used[q[i]]=1;
		ans += (r-l);
	}
	cout << ans << '\n';
}