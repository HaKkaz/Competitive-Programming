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
const int mod = 1e7+9;
const int maxn = 1e7+500;
const int p = 1e9+7;
map<string,bool> has;
signed main(){
	IOS;
	string str;
	while(cin >> str){
		cout << has[str] << '\n';
		has[str] = 1;
	}
}