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
int arr[200050];
signed main(){
    fast;
    int n , x;
    cin >> n >> x;
    for(int i=0 ; i<n ; ++i) cin >> arr[i];
    sort(arr , arr+n);

    int ans = 0 ;
    for(int i=0,j=n-1 ; i<n ; ++i){
        while(j>i and arr[j] > x-arr[i]) --j;
        if(arr[i] != -1) ++ans;
        if(j>i and arr[j] <= x-arr[i]) arr[j--] = -1;
    }

    cout << ans << '\n';
}

