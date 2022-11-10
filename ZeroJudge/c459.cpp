#include<bits/stdc++.h>
//#include<cstdio>
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
/*
inline int read(){
	int res=0; char ch=getchar_unlocked();
	while(ch<'0'||ch>'9') ch=getchar_unlocked();
	while(ch>='0'&&ch<='9') res=(res<<3)+(res<<1)+(ch^48),ch=getchar_unlocked();
	return res;
}
*/
#define int long long
#define mp make_pair
#define pb push_back
#define S second
#define F first
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define IOS ios::sync_with_stdio(false),cin.tie(0);
#define pii pair<int,int>
#define endl cout<<'\n';
#define LINE cout << "-----------------------\n";
using namespace std;
const int maxn = 1e6+5;

signed main(){
	IOS;
	int b ; 
	string n;
	cin >> b >> n ;
	reverse(all(n));
	int res=0 , res2=0;
	for(int i=0,k=1 ; i<n.size() ; ++i,k*=b){
		res += k*(n[i]-'0');

	}
	string tmp = to_string(res);
	for(int i=0 ; i<n.size() ; ++i){
		int now = 1;
		for(int j=1 ; j<=n.size() ; ++j){
			now *= n[i]-'0';
		}
		res2 += now;
	}
	if(res2 == res) cout << "YES\n";
	else cout << "NO\n";
}