#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#define int long long
#define pb push_back
#define MP make_pair
#define pii pair<int,int>
#define F first
#define S second
#define SZ(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = "  << x << '\n';
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
int ans[2][200050];
signed main(){
	IOS;
	int n; cin >> n;
	vector<int> l(n) , r(n) , sorted(n);
	for(int i=0 ; i<n ; ++i){
		cin >> l[i] >> r[i];
		sorted[i] = i;
	}

	//照左界排序，左界一樣照右界
	sort(sorted.begin() , sorted.end() , [&](const int &a , const int &b){
		if(l[a] != l[b]) return l[a] < l[b];
		else return r[a] > r[b];
	});
	//找第i個是否包含其他
	int mn = 2e9;
	for(int i=n-1 ; i>=0 ; --i){
		int id = sorted[i];
		if(mn <= r[id]) ans[0][id] = 1;
		else mn = r[id];
	}
	//找第i個是否被包含
	int mx = 0;
	for(int i=0 ; i<n ; ++i){
		int id = sorted[i];
		if(mx >= r[id]) ans[1][id] = 1;
		else mx = r[id];
	}

	for(int i=0 ; i<n ; ++i) cout << ans[0][i] << " \n"[i==n-1];
	for(int i=0 ; i<n ; ++i) cout << ans[1][i] << " \n"[i==n-1];

}