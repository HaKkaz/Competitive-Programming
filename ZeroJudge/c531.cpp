#include"bits/stdc++.h"
#define pb push_back
#define mp make_pair
#define int long long
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define rz(x) resize(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define endl cout<<'\n';
#define LINE cout<<"--------------------------\n";
#define loli ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
const int maxn = 500001;
vector<int> v , id , num;
int ans[25];
inline void latina(){
	loli;
	string str;
	while(cin >> str){
		v.clear(),id.clear(),num.clear();
		int now = 0;
		for(int i=0 ; i<str.size() ; ++i){
			if(str[i]==',') v.push_back(now),now=0;
			else now=now*10+(str[i]-'0');
		}
		v.push_back(now);
		for(int i=0 ; i<v.size() ; ++i){
			ans[i] = v[i];
			if(v[i]%2 == 0)
				num.push_back(v[i]) , id.push_back(i);
		}
		sort(all(num));
		for(int i=0 ; i<id.size() ; ++i){
			ans[id[i]]=num[i];
		}
		for(int i=0 ;i<v.size() ; ++i) cout << ans[i] << ",\n"[i==v.size()-1];
	}
}
signed main(){latina();}