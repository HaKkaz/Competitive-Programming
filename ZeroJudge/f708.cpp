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
signed main(){
    IOS;
    int m,n; cin >> m >> n;
    int sum0=0,sum1=0;
    for(int i=0,x ; i<m ; ++i) cin >> x , sum0 += x;
    for(int i=0,x ; i<n ; ++i) cin >> x , sum1 += x;
    if(m > n && sum0 > sum1) cout << "Yes\n";
    else cout << "No\n";
}