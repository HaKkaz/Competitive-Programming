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
	int n , m;
	cin >> n >> m ;
	string str;
	cin >> str;
	sort(all(str));
	for(int i=0 ; i<m ; ++i){
		int x; cin >> x;
		cout << str[x-1] ;
	}
}
signed main(){latina();}