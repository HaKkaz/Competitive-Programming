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

int dis[26][26];
int dx[]={0 , 1,1,0,-1,-1};
int dy[]={-1,-1,0,1,1,0};
const int INF = 1e12;

void build(){
	string key[3] = {
		"QWERTYUIOP",
		"ASDFGHJKL",
		"ZXCVBNM"
	};
	for(int i=0 ; i<26 ; ++i){
		for(int j=0 ; j<26 ; ++j){
			dis[i][j] = (i!=j)*INF;
		}
	}
	for(int i=0 ; i<3 ; ++i){
		for(int j=0 ; j<(int)key[i].size() ; ++j){
			for(int k=0 ; k<6 ; ++k){
				int new_i = i + dx[k];
				int new_j = j + dy[k];
				if(new_i >= 0 && new_i < 3 && new_j >= 0 && new_j < (int)key[new_i].size()){
					int chA = key[i][j] - 'A';
					int chB = key[new_i][new_j] - 'A';
					dis[chA][chB] = dis[chB][chA] = 1;
				}
			}
		}
	}
	for(int k=0 ; k<26 ; ++k){
		for(int i=0 ; i<26 ; ++i){
			for(int j=0 ; j<26 ; ++j){
				dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
			}
		}
	}
}
vector< vector< vector<int> > > dp(2 , vector< vector<int> >(26 , vector<int>(26 , INF)));
signed main(){
	fast;
	int n ;
	string s;
	cin >> n >> s;
	build();
	dp[0]['F'-'A']['J'-'A'] = 0;
	for(int i=0 ; i<n ; ++i){
		for(int l=0 ; l<26 ; ++l)
			for(int r=0 ; r<26 ; ++r)
				dp[1][l][r] = INF;
		int to = s[i]-'A';
		for(int l=0 ; l<26 ; ++l){
			for(int r=0 ; r<26 ; ++r){
				dp[1][l][to] = min(dp[1][l][to],dp[0][l][r] + dis[r][to]);
				dp[1][to][r] = min(dp[1][to][r],dp[0][l][r] + dis[l][to]);
			}
		}
		swap(dp[0] , dp[1]);
	}
	int ans = INF;
	for(int i=0 ; i<26 ; ++i){
		for(int j=0 ; j<26 ; ++j){
			ans = min(ans , dp[0][i][j]);
		}
	}
	cout << ans << '\n';
}
