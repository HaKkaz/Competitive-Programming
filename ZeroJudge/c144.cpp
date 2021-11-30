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
vector<string> Num[3];
void dfs(string s , int pos , int id){
	if(pos == s.size()){
		Num[id].push_back(s);
		return;
	}
	if(s[pos] != '?') dfs(s,pos+1,id);
	else{
		for(char c = '0' ; c <= '9' ; ++c){
			s[pos] = c;
			dfs(s , pos+1 , id);
		}
	}
}
signed main(){
	IOS;
	string a,b,c;
	dfs(a,0,0);
	dfs(b,0,0);
	dfs(c,0,0);
	string ans[3];
	for(int i=0 ; i<Num[0].size() ; ++i){
		for(int j=0 ; j<Num[1].size() ; ++j){
			for(int k=0 ; k<Num[2].size() ; ++k){
				int A=Num[0][i],B=Num[1][j],C=Num[2][k];
				if(A+B == C && ){
					
				}
			}
		}
	}
}