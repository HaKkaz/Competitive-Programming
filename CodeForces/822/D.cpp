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
const int MAXN = 2e5+50;;
int a[MAXN];


signed main(){
	fast;
	int t=1;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k ;
		for(int i=1 ; i<=n ; ++i) cin >> a[i];

		vector<int> v1,v2;
		int nice=-1;
		for(int i=k+1 ; i<=n ; ++i){
			if(nice == -1 || ((a[i] >= 0) ^ nice)){
				v2.push_back(a[i]);
				nice = a[i]>=0;
			}
			else{
				v2.back() += a[i];
			}
		}
		nice=-1;
		for(int i=k-1 ; i>=1 ; --i){
			if(nice == -1 || ((a[i] >= 0) ^ nice)){
				v2.push_back(a[i]);
				nice = a[i]>=0;
			}
			else{
				v2.back() += a[i];
			}
		}
		reverse(ALL(v1));
		reverse(ALL(v2));



		int cur = a[k];
		while(v1.size() or v2.size()){
			if(!v1.empty() && v1.back() >= 0) cur += v1.back();
			if(!v2.empty() && v2.back() >= 0) cur += v2.back();

			auto Merge = [&](vector<int> tmp){
				if(tmp.empty()) return;
				if(cur >= tmp.back()){
					if(tmp.size()>1) tmp[tmp.size()-2] += tmp.back() , tmp.pop_back();
					else tmp.pop_back();
				}
			}

			Merge(v1);
			Merge(v2);
		}

		// for(auto &x : v1) cout << x << ' ' ;
		// cout << '\n';
		// for(auto &x : v2) cout << x << ' ' ;
		// cout << '\n';

	}
}