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
vector<int> v;
int i(char x){return x-'0';}
inline void solve(){
	string s; cin >> s;
	string t;
	for(int i=0 ; i<sz(s) ; ++i) if(s[i] != '-') t+=s[i];
	int tot = 0;
	for(int i=0 ; i<9 ; ++i){
		tot += (t[i]-'0')*(i+1);
	}
	tot %= 11;
	if(tot == 10){
		if(t.back() == 'X') cout << "Right\n";
		else s.pop_back() , cout << s << 'X' << '\n';
	}
	else{
		if(t.back()-'0' == tot) cout << "Right\n";
		else s.pop_back() , cout << s << tot << '\n';
	}
}
signed main(){IOS;solve();}