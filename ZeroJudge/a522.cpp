#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define PB push_back
#define MP make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair<int,int>
#define all(X) (X).begin(),(X).end()
#define F first
#define S second
#define endl cout<<'\n';
#define __IO ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
int need , n;
bool ok;
vector<int> v;
bool cmp(int a,int b){return a<b;}
void dfs(int now , int tot){
	if(tot == need) return ok = true , void();
	for(int i=now+1 ; i<n ; ++i){
		if(tot + v[i] <= need) dfs(i , tot+v[i]);
		else break;
	}
}
int main(){__IO
	int t;
	cin >> t;
	while(t--){
		v.clear() , ok =false;
		cin >> need >> n;
		for(int i=0 ; i<n ; ++i){
			int x; cin >> x , v.push_back(x);
		}
		sort(all(v),cmp);
		for(int i=0 ; i<n&&(!ok) ; ++i) dfs(i , v[i]);
		puts(need==0?"YES":(ok?"YES":"NO"));
	}
}