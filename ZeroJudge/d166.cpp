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
#define loli ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
vector<int> a , ans;
inline void latina(){
	int x;
	string str;
	while(getline(cin , str)){
		if(str == "-1") exit(0);
		a.clear() , ans.clear();
		stringstream ss;
		ss << str;
		while(ss >> x) a.pb(x);
		for(int now = 1 ; now <= sz(a) ; ++now){
			for(int i=0 ; i<sz(a) ; ++i){
				if(a[i] == 0){
					ans.pb(i+1);
					for(int j=i ; j>=0 ; --j) a[j]--;
					break;
				}
			}
		}
		for(auto &c : ans) cout << c << ' ';
			endl
	}
}
signed main(){latina();}