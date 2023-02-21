#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define _ <<' '<<
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
#define tiii tuple<int,int,int>
using ll = long long;
using ld = long double;
using pii = pair<int,int>;

const int MAXN=1e6+60;
vector<int> prime(MAXN,1);

vector<int> fac[MAXN];
void seive(){
	for(int i=2 ; i<MAXN ; ++i){
		for(int j=i*i ; j<MAXN ; j+=i){
			fac[i].push_back(j);
		}
	}
}

signed main(){
	fast;
	int t=1;
	cin >> t;
	seive();
	while(t--){
		int n; cin >> n ;
		string T; cin >> T;
		int ans=0;

		vector<int> vis(n+1,0);
		for(int i=1 ; i<=n ; ++i)
		{
			if(T[i-1] == '0'){
				for(int k=i ; k<=n ; k=k+i){
					if(T[k-1] == '1') break;
					else if(!vis[k]){
						ans += i;
						// cout << k << " use " << i << '\n';
						vis[k] = i;
					}
				}
			}
		}
		cout << ans << '\n';
	}
}