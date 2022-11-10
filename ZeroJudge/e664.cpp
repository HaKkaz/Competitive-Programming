#include"bits/stdc++.h"
#define pb push_back
#define mp make_pair
#define int long long
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define rz(x) resize(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define endl cout<<'\n';
#define LINE cout<<"--------------------------\n";
#define loli ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
const int maxn = 500001;
vector<int> v;
inline void latina(){
	loli;
	bool tag = 1;
	string str;
	getline(cin , str);
	stringstream ss;
	int x;
	ss << str;
	while(ss >> x) v.pb(x);
	const int n = v.size();
	for(int i=1 ; i<n-1 ; ++i){
		if(v[i] > v[i-1] and v[i]>v[i+1]){
			cout << i+1 << ' ' << v[i] << '\n',tag=0;
		}
		else if(v[i] == v[i+1] and v[i] > v[i-1]){
			int j = i+1;
			while(v[j] == v[i]) ++j;
			if(j < n and v[i] > v[j])cout << i+1 << ' ' << j << ' ' << v[i] << '\n',tag=0;
		}
	}
	if(tag) cout << "0 0\n";
}
signed main(){latina();}