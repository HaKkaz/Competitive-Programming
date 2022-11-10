#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define endl cout<<'\n';
#define __IO ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
int a , b ,n , ans = 0;
vector<int> v;
bool cmp(const int &x , const int &y){return x > y;}
void dfs(int idx){
	if(idx == n){
		int sum = a * b;
		ans = max(ans , sum);
		return ;
	}
	a = a*10 + v[idx];
	dfs(idx+1);
	a /= 10;

	b = b*10 + v[idx];
	dfs(idx+1);
	b /= 10;
}
int main(){
//__IO
	cin >> n;
	for(int i=0 ; i<n ; ++i){
		int x; cin >> x;
		v.pb(x);
	}
	sort(all(v) , cmp);
	a = v[0];
	dfs(1);
	a = 0 , b = v[0];
	dfs(1);
	cout << ans << '\n';
}