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
inline void solve(){
	string str;
	while(cin >> str && str != "0"){
		int ans = 0 ,tag = 1;
		for(int i=0 ; tag && i<sz(str) ; ++i){
			if(str[i] >= 'a' and str[i] <= 'z') ans += 1+(str[i]-'a');
			else if(str[i] >= 'A' and str[i] <= 'Z') ans += 1+(str[i]-'A');
			else tag = 0;
		}
		cout << (tag?to_string(ans):"Fail")+'\n' ;
	}
}
signed main(){IOS;solve();}