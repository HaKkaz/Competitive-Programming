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
using ll = long long;
using ld = long double;
using pii = pair<int,int>;

vector<ll> A,B;

void dfs(vector<int> &v , vector<ll> &con , int i , ll sum ,const int &n){
    if(i == n){
        con.emplace_back(sum);
        return;
    }
    dfs(v , con , i + 1 , sum + v[i] , n);
    dfs(v , con , i + 1 , sum , n);
}

signed main(){
    fast;
    int n;
    ll x;
    cin >> n >> x;

    int m = n/2;
    n = n - m;
    vector<int> a(n);
    vector<int> b(m);

    for(int &i : a) cin >> i;
    for(int &i : b) cin >> i;
    
    dfs(a,A,0,0,n);
    dfs(b,B,0,0,m);

    sort(ALL(A));
    sort(ALL(B));

    ll ans = 0 ;
    for(ll &val : A){
        if(val > x) break;
        auto LB = lower_bound(ALL(B) , x - val);
        if(LB != B.end()){
            ans += upper_bound(ALL(B) , x - val) - LB;
        }
    }
    cout << ans << '\n';
}

