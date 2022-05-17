#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#define int long long
#define pb push_back
#define MP make_pair
#define pii pair<int,int>
#define F first
#define S second
#define SZ(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = "  << x << '\n';
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
signed main(){
	IOS;
	int t ; cin >> t;
	for(int i=0 ; i<t ; ++i){
		cout << "Case #" << i+1 << ": ";
		int a[4][3];
		for(int i=0 ; i<3 ; ++i){
			for(int j=0 ; j<4 ; ++j){
				cin >> a[j][i];
			}
		}
		int tot=0 , MN[4];
		for(int i=0 ; i<4 ; ++i){
			int mn = *min_element(a[i] , a[i]+3);
			tot += mn;
			MN[i] = mn;
		}
		if(tot < 1000000){
			cout << "IMPOSSIBLE";
		}
		else{
			int need = 1000000;
			for(int i=0 ; i<4 ; ++i){
				if(need >= MN[i]) cout << MN[i] << ' ' , need -= MN[i];
				else cout << need << ' ' , need = 0;
			}
		}
		cout << '\n';
	}
}