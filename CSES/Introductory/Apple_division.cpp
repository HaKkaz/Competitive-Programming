#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define cerr if(1);else cerr
#define _ <<' '<<
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
#define int long long
using ll = long long;
using ld = long double;
using pii = pair<int,int>;

int ans = 1e18;
int a[1000005] , n;

void dfs(int i , int A , int B){
    if(i == n) {
        ans = min(ans , abs(A-B));
        return;
    }
    dfs(i+1 , A+a[i] , B);
    dfs(i+1 , A , B + a[i]);
}

signed main(){
    fast;
    cin >> n;
    for(int i=0 ; i<n ; ++i) cin >> a[i];

    dfs(0,0,0);

    cout << ans << '\n';
}

