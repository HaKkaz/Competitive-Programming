#include<bits/stdc++.h>
#define int long long
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
using namespace std;
const int inf = numeric_limits<int>::max();
const int maxn = 1e6+500;
map<char , int> mm;
inline void solve(){
	for(int i=0 ; i<26 ; ++i){
		mm['a'+i] = i+1;
		mm['A'+i] = i+27;
	}
	string str;
	while(cin >> str){
		int tot = 0;
		for(int i=0 ; i<sz(str) ; ++i){
			tot += mm[str[i]];
		}
		bool tag = 1;
		for(int i=2 ; i<tot ; ++i) if(tot % i == 0) tag = 0;
		if(tag) cout << "It is a prime word.\n";
		else cout << "It is not a prime word.\n";
	}
}
signed main(){IOS;solve();}