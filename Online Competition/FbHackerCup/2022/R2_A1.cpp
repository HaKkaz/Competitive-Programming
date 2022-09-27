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

signed main(){
	fast;
	freopen("perfectly_balanced_chapter_1_input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	int t=1;
	cin >> t;
	for(int Case = 1 ; Case <= t ; ++Case){
		string s; cin >> s;
		const int n = (int)s.size();
		vector<vector<int>> cnt(26 , vector<int>(n+1 , 0));
		int ans=0;

		for(int i=1 ; i<=n ; ++i){
			for(int j=0 ; j<26 ; ++j){
				cnt[j][i] = cnt[j][i-1];
				if(s[i-1] == (j + 'a')){
					++cnt[j][i];
				}
			}
		}

		int q; cin >> q;
		while(q--){
			int l,r; cin >> l >> r;
			if((r-l+1) % 2 == 0) continue;

			int m1 = (l+r-1)/2;
			int not_same1=0;
			for(int j=0 ; j<26 ; ++j){
				if(cnt[j][m1] - cnt[j][l-1] != cnt[j][r] - cnt[j][m1])
					not_same1++;
			}

			int m2 = (l+r-1)/2+1;
			int not_same2=0;
			for(int j=0 ; j<26 ; ++j){
				if(cnt[j][m2] - cnt[j][l-1] != cnt[j][r] - cnt[j][m2])
					not_same2++;
			}

			ans += (not_same1 == 1 || not_same2 == 1);
		}
		cout << "Case #" << Case <<": "<< ans << '\n';
	}
	return 0;
}