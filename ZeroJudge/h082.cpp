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
int A[100000] , B[100000];
signed main(){
	IOS;
	int n, m ; cin >> n >> m;
	for(int i=1 ; i<=n ; ++i) cin >> A[i];
	for(int i=1 ; i<=n ; ++i) cin >> B[i];
	deque<int> p(n) , cnt(n+1 , 0);
	for(int i=0 ; i<n ; ++i) cin >> p[i];

	while(p.size() > 1){
		vector<int> win , lose;
		while(p.size() > 1){
			int x = p.front(); p.pop_front();
			int y = p.front(); p.pop_front();
			int a = A[x] , b = B[x] , c = A[y] , d = B[y];
			if(a*b >= c*d){
				A[x] = a + c*d / (2*b) , B[x] = b + c*d/(2*a);
				A[y] = c + c/2 , B[y] = d + d/2;
				cnt[y]++;
				win.push_back(x) , lose.push_back(y);
			}
			else{
				A[y] = c + a*b / (2*d) , B[y] = d + a*b/(2*c);
				A[x] = a + a/2 , B[x] = b + b/2;
				cnt[x]++;
				win.push_back(y) , lose.push_back(x);
			} 
		}
		assert(p.size()<=1);
		if(p.size()) win.push_back(p.front()) , p.pop_front();
		assert(p.size()==0);
		for(auto &x : win) p.push_back(x);
		for(auto &x : lose) if(cnt[x] < m) p.push_back(x);
	}
	cout << p[0] << '\n';
}