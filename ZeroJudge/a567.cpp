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
    int n; 
    while(cin >> n){
        int ans = 0L;
        priority_queue<int> pq;
        vector<pii> p(n);
        for(pii &pp : p) cin >> pp.F >> pp.S;
        sort(all(p));
        for(int day=10000 ; day>=1 ; --day){
            while(p.size() && p.back().F == day) pq.push(p.back().S) , p.pop_back();
            if(pq.size())ans += pq.top() , pq.pop();
        }
        cout << ans << '\n';
    }
}