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
#define int long long
int a[100050];

signed main(){
	fast;
    int n; cin >> n;
    int sum=0;
    for(int i=1 ; i<=n ; ++i)
        cin >> a[i] , sum += a[i];
    int X ; cin >> X;
    int ans = X/sum*n;
    int SUM = X/sum*sum;
    for(int i=1 ; i<=n ; ++i){
        ++ans;
        SUM += a[i];
        if(SUM > X) break;
    }
    cout << ans << '\n';
}

