#include<iostream>
#include<vector>
#include <algorithm>
#pragma GCC optimize("Ofast")
#define int long long
#define double long double
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
const double eps = 1e-7;
int n,m,top,dwn;
bool check(double mid , vector<pii> &v){
	top = 0 , dwn = 0;
	vector<pair<double,pii> > tmp(n);
	for(int i=0 ; i<n ; ++i){
		tmp[i] = {v[i].F-v[i].F*mid-v[i].S*mid , v[i]};
	}
	sort(all(tmp)) , reverse(all(tmp));
	double sum = 0 ;
	for(int i=0 ; i<m ; ++i){
		sum += tmp[i].F;
		top += tmp[i].S.F;
		dwn += tmp[i].S.F+tmp[i].S.S;
	}
	return sum >= 0.0;
}
double l , r;
signed main(){
	IOS;
	while(cin >> n >> m){
		vector<pii> v(n);
		for(pii &x : v) cin >> x.F >> x.S;
		l=0 , r = 1;
		while(r-l>eps){
			double mid = (l+r)/2.0;
			if( check(mid , v) ) l = mid;
			else r = mid;
		}
		if(top == dwn) cout << 1 << '\n';
		else if(top == 0) cout << 0 << '\n';
		else cout << top/__gcd(top,dwn) << '/' << dwn/__gcd(top,dwn) << '\n';
		//
		for(int i=0 ; i<n ; ++i) swap(v[i].F , v[i].S);
		l=0 , r = 1;
		while(r-l>eps){
			double mid = (l+r)/2.0;
			if( check(mid , v) ) l = mid;
			else r = mid;
		}
		if(top == dwn) cout << 1 << '\n';
		else if(top == 0) cout << 0 << '\n';
		else cout << top/__gcd(top,dwn) << '/' << dwn/__gcd(top,dwn) << '\n';
	}
}

/*
3 1
0 1
5 5
2 6

3 2
0 1
5 5
2 6

4 2
1 5
2 6
7 7
9 9

2 1
0 1
1 0
*/