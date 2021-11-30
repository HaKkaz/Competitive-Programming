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
const int mod = 1e9+7;
int main(){
	freopen("weak_typing_chapter_2_input.txt","r",stdin);
	freopen("weak_typing_chapter_2_output.txt","w",stdout);
	fast;
	int T; cin >> T;
	for(int kase=1 ; kase<=T ; ++kase){
		ll n , ans=0;
		string s; 
		cin >> n >> s;
		int who = -1;
		ll pos = -1;
		for(int i=0 ; i<n ; ++i){
			if(s[i]=='O'){
				if(who == 1){//add ans
					ans = (ans + (pos+1)*(n-i)%mod)%mod;
				}
				who=0 , pos = i;
			}
			if(s[i]=='X'){
				if(who == 0){//add ans
					ans = (ans + (pos+1)*(n-i)%mod)%mod;
				}
				who=1 , pos = i;
			}
		}
		cout << "Case #" << kase << ": " << ans << '\n';
	}
}

