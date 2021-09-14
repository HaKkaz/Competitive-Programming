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
#define _ << ' ' << 

int main(){
	fast;
    int n; cin >> n ;
    vector<pii> p;
    set<pii> st;
    for(int i=0 ; i<n ; ++i){
        cin >> p[i].ft >> p[i].sd;
        st.insert({p[i].ft , p[i].sd});
    }
    int ans = 0 ;
    for(int i=0 ; i<n ; ++i){
        for(int j=0 ; j<i ; ++j){
            int a = p[i].ft , b = p[i].sd;
            int c = p[j].ft , d = p[j].sd;
            if(st.count({a,d}) > 0 && st.count(c,b) > 0) ++ans;
        }
    }
}
