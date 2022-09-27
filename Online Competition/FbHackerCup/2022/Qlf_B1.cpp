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
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
int main(){
	IOS;
	freopen("second_friend_input.txt","r",stdin);
	freopen("second_friend_output.txt","w",stdout);
	int t;
	cin >> t;
	for(int Case=1 ; Case<=t ; ++Case){
		auto solve = [](){
			int n, m; cin >> n >> m ;

			bool have_tree = false;
			for(int i=0 ; i<n ; ++i){
				for(int j=0 ; j<m ; ++j){
					char c; cin >> c;
					have_tree |= (c == '^');
				}
			}

			string ans = ((n < 2 || m < 2)&&have_tree ? "Impossible" : "Possible");
			cout << ans << '\n';
			if(ans[0] == 'P'){
				for(int i=0 ; i<n ; ++i){
					for(int j=0 ; j<m ; ++j){
						cout << (have_tree ? '^' : '.');
					}
					cout << '\n';
				}
			}
		};
		cout << "Case #" << Case << ": ";
		solve();
	}
}