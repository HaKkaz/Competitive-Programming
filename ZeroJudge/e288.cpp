#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
map<long long,int> mp;
string s;
int main(){
    fast;
    int m , n , ans=0;
    cin >> m >> n ;
    for(int i=0 ; i<n ; ++i){
        cin >> s;
        long long t = 0;
        for(const char &c : s){
            if(isupper(c)) t |= (1ll<<(c-'A'));
            else t |= (1ll<<(c-'a'+26));
        }
        long long k = ((1ll<<m)-1)^t;
        if(mp.count(k)) ans += mp[k];
        mp[t]++;
    }
    cout << ans << '\n';
}