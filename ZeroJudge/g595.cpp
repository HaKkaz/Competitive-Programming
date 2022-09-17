#include<iostream>
int a[100005];
int main(){
    int n; cin >> n;
    a[0] = a[n+1] = 10000000;
    int ans = 0;
    for(int i=1 ; i<=n ; ++i) cin >> a[i];
    for(int i=1 ; i<=n ; ++i) ans += (a[i-1] < a[i+1] ? a[i-1] : a[i+1]);
    cout << ans << '\n';
}
