#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define ft first
#define sd second
#define ALL(v) v.begin(),v.end()
#define fast ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define cerr if(0);else cerr
#define _ << ' ' << 

int main(){
	freopen("weak_typing_chapter_1_input.txt","r",stdin);
	freopen("weak_typing_chapter_1_output.txt","w",stdout);
	fast;
	int T ; cin >> T;
	for(int Case = 1 ; Case <= T ; ++Case){
		int n; cin >> n ;
		string s; cin >> s;
		int dp[2][2];
		memset(dp , 0 , sizeof(dp));
		for(int i=0 ; i<(int)s.size() ; ++i){
			if(s[i] == 'F'){
				dp[1][0] = min(dp[0][0] , dp[0][1]+1);
				dp[1][1] = min(dp[0][0]+1 , dp[0][1]);
			}
			else if(s[i] == 'O'){
				dp[1][0] = min(dp[0][0] , dp[0][1]+1);
				dp[1][1] = 1e9;
			}
			else{
				dp[1][0] = 1e9;
				dp[1][1] = min(dp[0][0]+1 , dp[0][1]);
			}
			dp[0][0] = dp[1][0];
			dp[0][1] = dp[1][1];
		}
		cout << "Case #" << Case << ": " << min(dp[0][0] , dp[0][1]) << '\n';
	}
	
}

