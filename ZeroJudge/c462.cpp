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
using namespace std;
const int maxn = 500001;
int k;
string str;
bitset<maxn> b , st;
signed main(){
	ios::sync_with_stdio(false),cin.tie(0);
	cin >> k >> str;
	const int n = sz(str);
	for(int i=0 ; i<(int)str.size() ; ++i){
		if(str[i]>='a' && str[i]<='z') b[i] = 0;
		else b[i] = 1;
	}
	bool now;
	int ans=0;
	for(int x=0 ; x<n ; ++x){
		int cnt = 0;
		if(st[x]) continue;
		for(int i=x ; i<n ;){
			bool ok = 1;
			if(cnt == 0){
				st[i]=1;
				now=b[i];
				for(int j=i ; j<i+k ; ++j){
					if(b[j] != now) ok = 0;
				}
				if(ok) cnt++ , now=1-now , i+=k;
				else ++i;
			}
			else{
				for(int j=i ; j<i+k ; ++j){
					if(b[j] != now) ok = 0;
				}
				if(ok) cnt++ , now=1-now , i+=k;
				else ++i , ans = max(ans , cnt) , cnt = 0;
			}
		}
		ans = max(ans , cnt);
	}
	cout << ans*k << '\n';
}