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

const int maxn = 5e5+50;
vector<int> a(maxn);
vector<int> b(maxn);
int n,k;

ll Mod[] = {1076767633LL,999991231LL,999888733LL,1000000000039LL,556679LL};
ll Pow[] = {3,13331,14341,75577,123457};

void Hash(vector<int> &v , int P , int mod){
	v[0] = b[0];
	for(int i=1, p=P ; i<n ; ++i, p=p*P%mod){
		v[i] = (v[i-1] + b[i] * p % mod) % mod;
	}
}

bool check(int i , int k){

}

bool solve(){
	cin >> n >> k ;
	for(int i=0 ; i<n ; ++i) cin >> a[i];
	for(int i=0 ; i<n ; ++i) cin >> b[i];

	if(k == 0 || k == 1) return (k == 1)^(a == b);
	if(n == 2) return (k & 1)^(a == b);

	vector< vector<int> > hash_(5,vector<int>(n+1,0));
	for(int t=0 ; t<5 ; ++t){
		Hash(hash_[t] , Pow[t] , Mod[t]);
	}

	bool nice = false;

	for(int i=0 ; i<n-1 ; ++i){
		bool ok = true;
		for(int k=0 ; k<5 ; ++k){
			check(i,k);
		}
		nice |= ok;
	}

	return nice;
}

signed main(){
	fast;
	int t=1;
	cin >> t;
	for(int kase=1 ; kase<=t ; ++kase){
		// solve();
		cout << "Case #" << kase << ": " << (solve() ? "YES" : "NO") << '\n';
	}
}