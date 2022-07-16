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

int X[3] , Y[3];

void dfs(int x , int y){

}

signed main(){
	fast;
	cin >> X[0] >> X[1] >> X[2] ;
	cin >> Y[0] >> Y[1] >> Y[2] ;
	vector< vector<int> > okx[3];
	for(int i=1 ; i<=30 ; ++i){
		for(int j=1 ; j<=30 ; ++j){
			for(int k=1 ; k<=30 ; ++k){
				for(int p=0 ; p<3 ; ++p){
					if(i + j + k == X[p]){
						auto tmp = vector<int>{i,j,k};
						okx[p].push_back(tmp);
					}
				}
			}
		}
	}
	int ans = 0 ;
	for(auto vi : okx[0]){
		for(auto vj : okx[1]){
			for(auto vk : okx[2]){
				if(vi[0] + vj[0] + vk[0] == Y[0]
				&& vi[1] + vj[1] + vk[1] == Y[1]
				&& vi[2] + vj[2] + vk[2] == Y[2]){
					++ans;
				}
			}
		}
	}
	cout << ans << '\n';
}