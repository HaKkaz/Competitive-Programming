#include<bits/stdc++.h>
#include <string>
#include <cctype>
#include <algorithm>
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
map<char , int > dic;
struct T
{
	int cnt;
	char c;
	bool operator<(const T &x)const{
		if(cnt != x.cnt) return cnt > x.cnt;
		return c < x.c;
	}
};
vector<T> v;
inline void solve(){
	int t; cin >> t;
	string str;
	getline(cin , str);
	while(t--){
		dic=map<char,int>() , v=vector<T>();
		string str;
		getline(cin , str);
		for(auto &c : str){
			if(c >= 'A' and c <= 'Z') c += 32;
			if(c >= 'a' and c <= 'z') dic[c]++;
		}
		for(auto &c : dic) v.pb({c.S , c.F});// , cout << c.S << ' ' << c.F << '\n'; 
		sort(all(v));
		int b = -1;
		for(auto &c : v){
			if(b == -1) cout << c.c , b = c.cnt;
			else if(c.cnt == b) cout << c.c;
			else break;
		}
		endl
	}
}
signed main(){IOS;solve();}