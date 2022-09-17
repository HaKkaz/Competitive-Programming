#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define cerr if(0);else cerr
#define _ << ' ' << 
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
using ll = long long ;
using ld = long double ;
using pii = pair<int,int> ;
#define vi vector<int>

vi tmp;
vector< vi > ans;
void dfs(int a , const int &n){
    if(a == n+1){
        ans.emplace_back(tmp);
        return;
    }
    tmp.emplace_back(a);
    dfs(a+1 , n);
    tmp.pop_back();
    dfs(a+1 , n);
}

signed main(){
	fast;
    int t; cin >> t;while(t--){
        ans.clear(); tmp.clear();
        int n; cin >> n;
        dfs(1,n);
        sort(ALL(ans) , [](const vi &a ,const vi &b){
                if(a.size() != b.size()) return (int)a.size() < (int)b.size();
                return a < b;
        });
        for(auto &v : ans){
            cout << '{';
            if(v.empty()) cout << 0 ;
            for(auto &x : v){
                cout << x;
                if(x != v.back()) cout << ',';
            }
            cout << "}\n";
        }
        cout << endl;
    }

    ;
}

