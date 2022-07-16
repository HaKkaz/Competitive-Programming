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

signed main(){
	fast;
	int n ;cin >> n ;

	map<string , int> score;

	int mx = -1 , idx = -1;

	for(int i=0 ; i<n ; ++i){
		string name;
		int t;
		cin >> name >> t;
		if(score.find(name) == score.end()){
			score[name] = t;
			if(t > mx) mx = t , idx = i + 1;
		}
	}

	cout << idx << '\n';

}