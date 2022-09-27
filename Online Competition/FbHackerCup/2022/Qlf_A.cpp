#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#define pii pair<int,int>
#define ft first
#define sd second
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = "  << x << '\n';
using namespace std;
int main(){
	IOS;
	freopen("second_hands_input.txt","r",stdin);
	freopen("second_hands_output.txt","w",stdout);
	int t;
	cin >> t;
	for(int Case=1 ; Case<=t ; ++Case){
		function<string()> solve = [](){	
			int n,k;
			string ans = "YES";
			cin >> n >> k;
			array<int,101> cnt{};
			for(int i=0 ; i<n ; ++i){
				int s; cin >> s;
				if(++cnt[s] >= 3){
					ans = "NO";
				}
			}
			if(k*2 < n) ans = "NO";
			return ans;
		};
		cout << "Case #" << Case << ": " << solve() << '\n';
	}
}