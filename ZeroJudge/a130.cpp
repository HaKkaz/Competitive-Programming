#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t; cin >> t; for(int Case = 1 ; Case <= t ; ++Case){
        int a[10];
        string s[10];
        int mx=0;
        for(int i=0 ; i<10 ; ++i){
            cin >> s[i] >> a[i];
            mx = max(mx , a[i]);
        }

        cout << "Case #" << Case << ":\n";
        for(int i=0 ; i<10 ; ++i) if(a[i] == mx) cout << s[i] << '\n';
    }   
}