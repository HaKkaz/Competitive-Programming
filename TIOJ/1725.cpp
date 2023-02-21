#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define _ <<' '<<
#define ALL(v) v.begin(),v.end();

const int MAXN = 3e6+50;
array<int,MAXN> z1, z2;
void make_z(const string &s, array<int,MAXN> &z) {
  int l = 0, r = 0;
  for (int i = 1, sz = s.size(); i < sz; i++) {
    z[i] = max(0, min(r - i + 1, z[i - l]));
    while (i + z[i] < sz and s[i + z[i]] == s[z[i]])
         z[i]++;
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
}


signed main(){
	fast;
	int n; cin >> n;
	string a, b;
	cin >> a >> b;
	make_z(b + '/' + a + a, z1);
	reverse(begin(a), end(a));
	reverse(begin(b), end(b));
	make_z(b + '/' + a + a, z2);
	
	bool first = true;
	for (int i = n + 1, j = 2*n+1; i <= n*2; ++i, --j) {
		if (z1[i] + z2[j] == n - 1) {
			if (first) cout << "TAK\n", first = false;
			cout << i-n-1 << ' ';
		}
	}
	if (first) {
		cout << "NIE\n";
	}
}