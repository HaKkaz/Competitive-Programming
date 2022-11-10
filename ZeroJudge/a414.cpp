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
inline void latina(){
	loli;
	int x; 
	while(cin >> x and x){
		int res = 0;
		for(int i=0 ; i<33 ; ++i){
			if(x&(1<<i)) ++res;
			else break;
		}
		cout << res << '\n'; 
	}
}
signed main(){latina();}