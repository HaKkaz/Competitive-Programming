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

signed main(){
    fast;
    string s; cin >> s;
    array<int,26> cnt;
    cnt.fill(0);
    for(auto &ch : s) cnt[ch-'A']++;

    if(s.size() % 2 == 0){
        for(int i=0 ; i<26 ; ++i) if(cnt[i] & 1) return puts("NO SOLUTION"),0;    
        for(int i=0 ; i<26 ; ++i)
            for(int j=0 ; j<cnt[i]/2 ; ++j) cout << char(i+'A');
        
        for(int i=25 ; i>=0 ; --i)
            for(int j=0 ; j<cnt[i]/2 ; ++j) cout << char(i+'A');
    }
    else{
        int odd = 0 ;
        for(int i=0 ; i<26 ; ++i) if(cnt[i] & 1) ++odd;
        if(odd > 1) return puts("NO SOLUTION"),0;    
        for(int i=0 ; i<26 ; ++i)
            for(int j=0 ; j<cnt[i]/2 ; ++j) cout << char(i+'A');

        for(int i=0 ; i<26 ; ++i)
            if(cnt[i] & 1) cout << char(i + 'A');

        for(int i=25 ; i>=0 ; --i)
            for(int j=0 ; j<cnt[i]/2 ; ++j) cout << char(i+'A');

        


    }
}

