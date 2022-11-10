#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define S second
#define F first
#define sz(x) (int)(x).size()
#define rz(n) resize(n)
#define all(x) (x).begin(),(x).end()
#define IOS ios::sync_with_stdio(false),cin.tie(0);
#define pii pair<int,int>
#define endl cout<<'\n';
#define LINE cout << "-----------------------\n";
using namespace std;
const int inf = numeric_limits<int>::max();
const int maxn = 1e6+500;
char ch[260];
inline void solve(){
	IOS;
	int n , m;
	string str,a,b;
	cin >> n >> m >> str >> a >> b;
	for(int i=int('a') ; i<=int('z') ; ++i) ch[i]=char(i);
	for(int i=int('A') ; i<=int('Z') ; ++i) ch[i]=char(i);
	for(int i=int('0') ; i<=int('9') ; ++i) ch[i]=char(i);
	for(int i=0 ; i<m ; ++i){
		for(int j=int('a') ; j<=int('z') ; ++j)
			if(ch[j]==a[i]) ch[j]=b[i];
		for(int j=int('0') ; j<=int('9') ; ++j)
			if(ch[j]==a[i]) ch[j]=b[i];
		for(int j=int('A') ; j<=int('Z') ; ++j)
			if(ch[j]==a[i]) ch[j]=b[i];
	}
	for(int i=0 ; i<n ; ++i){
		cout << char(ch[int(str[i])]);
	}
}
signed main(){solve();}
/*
4 3
abcd
abd
bca
5 3
aA0aA
aA9
9aA
*/