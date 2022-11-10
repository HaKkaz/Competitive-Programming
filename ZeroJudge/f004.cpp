#include"bits/stdc++.h"
#define pb push_back
#define int long long
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define LINE cout<<"--------------------------\n";
#define IOS ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
const int maxn = 1e6+50;
int d[]={1000,500,100,50,10,5,1};
signed main(){
	IOS;
	int x;
	while(cin >> x){
		string ans = "";
		cout << x << " = " ;
		for(int i=0 ; i<7 ; ++i) if(x >= d[i]) ans += (to_string(d[i]) + '*' + to_string(x/d[i]) + " + ") , x%=d[i];
		for(int i=0 ; i<ans.size()-2 ; ++i) cout << ans[i];
		cout << '\n';
	}	
}