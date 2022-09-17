#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
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

signed main(){
	fast;
	int F,N; cin >> F >> N;
	vector<int> y(N);
	vector<int> win = {2,-1,5,-1,-1,0};
	//win[0] = 2
	//win[2] = 5
	//win[5] = 0
	for(int i=0 ; i<N ; ++i){
		cin >> y[i];
		if(i > 1 && y[i-1] == y[i-2]) F = win[win[y[i-1]]];
		cout << F << ' ' ;
		if(win[F] == y[i]){
			cout << ": Won at round " << i+1 << '\n';
			return 0;
		}
		if(win[y[i]] == F){
			cout << ": Lost at round " << i+1 << '\n';
			return 0;
		}
	}
	cout << ": Drew at round " << N << '\n';
}