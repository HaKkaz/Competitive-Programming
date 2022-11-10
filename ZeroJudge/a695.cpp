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
const int maxn = 1e5;
vector<int> prime;
bool ok[maxn];
void sieve(){
	for(int i=2 ; i<maxn ; ++i){
		for(int j=i*i ; j<maxn ; j+=i){
			ok[j]=1;
		}
	}
	for(int i=2 ; i<=maxn ; ++i){
		if(!ok[i]) prime.pb(i);
	}
}
inline void latina(){
	loli;
	sieve();
	int n ; cin >> n ;
	for(auto &c : prime) if(n%c==0) cout << n/c << '\n',exit(0);
}
signed main(){latina();}