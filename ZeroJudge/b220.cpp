#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#define int long long
#define pb push_back
#define MP make_pair
#define pii pair<int,int>
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = "  << x << '\n';
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
int x[1005],y[1005];
signed main(){
	IOS;
	string str;
	getline(cin , str);
	int top=0 , n = 0;
	while(top < sz(str)){
		char c = str[top++];
		int res = 0 ;
		while(top < sz(str) && (c >= '0' && c <= '9')) res = (res*10) + (c-'0') , c = str[top++];
		n = max(n , res);
	}
	// debug(n);
	for(int i=1 ; i<=n ; ++i){
		int id; cin >> id;
		cin >> x[id] >> y[id];
	}
	// const int N = sz(str);
	top = 0;
	vector< vector<pii>  > stk;
	while(top < sz(str)){
		char c = str[top++];
		while(top<sz(str) && (c < '0' || c > '9') && c != 'H' && c != 'V') c = str[top++];
		if(c>='0' && c<='9'){
			int id = 0 ;
			while(top<sz(str) && c >= '0' && c <= '9') id = id*10 + (c-'0') , c = str[top++];
			vector<pii> tmp;
			tmp.push_back({x[id] , y[id]});
			tmp.push_back({y[id] , x[id]});
			stk.push_back(tmp);
			// debug(id);
			// debug(mn);
			// debug(mx);
			// LINE
		}
		//solve
		else if(c == 'H' || c == 'V'){
			vector<pii> A=stk.back();
			stk.pop_back();
			vector<pii> B=stk.back();
			stk.pop_back();
			vector<pii> tmpA,tmpB;
			for(int i=0 ; i<sz(A) ; ++i){
				for(int j=0 ; j<sz(B) ; ++j){
					int xx , yy;
					if(c == 'H'){
						xx = A[i].F + B[j].F , yy = max(A[i].S , B[j].S);
					}
					if(c == 'V'){
						xx = max(A[i].F , B[j].F) , yy = A[i].S + B[j].S;
					}
					while(tmpA.size() && tmpA.back().F>xx) tmpA.pop_back();
					// while(tmpB.size() && tmpB.back().S>yy) tmpB.pop_back();
					tmpA.push_back({xx,yy});
					tmpB.push_back({xx,yy});
				}
			}
			for(pii &c : tmpB) tmpA.push_back(c);
			sort(all(tmpA)) , tmpA.resize(unique(all(tmpA))-tmpA.begin());
			stk.push_back(tmpA);
		}
	}
	int ans = 4e18;
	// debug(stk.size());
	for(pii &c : stk[0]){
		ans = min(ans , c.F * c.S)	;
	}
	cout << ans << '\n';
}