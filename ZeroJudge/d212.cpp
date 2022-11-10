#include<bits/stdc++.h>
#define test_
#define PB push_back
#define S second
#define F first
#define all(x) (x).begin(),(x).end()
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define pii pair<int,int>
#define endl cout<<'\n';
const long long llMAX=2e18+20020522;
const unsigned long long ullMAX=1e19+20020522;
const int imax = 2e9+20020522;
using namespace std;
unsigned long long  p[101];
inline void solve(){
	p[1] = 1 , p[2] = 2;
	for(int i=3 ; i<=100 ; ++i){
		p[i] = p[i-1]+p[i-2];
	}
}
int main(){
__IO
	int n ;
	solve();
	while(cin >> n) cout << p[n] <<'\n';
}