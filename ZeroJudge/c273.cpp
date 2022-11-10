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
int ans[2];
inline void latina(){
	loli;
	string str;
	bool tag=1;
	while(cin >> str){
		tag=0;
		ans[0]=ans[1]=0;
		for(int i=0 ; i<str.size() ; ++i){
			ans[i&1] += str[i]-'0';
		}
		cout << ans[0]-ans[1] << '\n';
	}
	if(tag) cout <<"I finish the homework.\n";
}
signed main(){latina();}