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

bool cmp(vector<int> a , vector<int> b){
    if(a.size() != b.size()) return a.size() < b.size();
    else return a < b;
}

signed main(){
	fast;
    int t; cin >> t;while(t--){
        int n; cin >> n;
        vector< vector<int> > ans;
        for(int i=0 ; i< (1<<n) ; ++i){
            vector<int> v;
            for(int j=0 ; j<n ; ++j){
                if(i >> j & 1){
                    v.push_back(j+1);
                }
            }
            ans.push_back(v);
        }
        
        sort(ALL(ans) , cmp);

        for(auto &vv : ans) {
            if(vv.size() == 0){
                cout << "{0}\n";
            }
            else{
                cout << '{';
                for(auto &x : vv){
                    cout << x ;
                    if(x != vv.back()) cout << ',';
                }
                cout << '}';
                cout << endl;
            }
        }
        cout << endl;
    }

    ;
}




for(int i=0 ; i<(1<<n) ; ++i){
    for(int j=0 ; j<n ; ++j){//枚舉現在這個狀態的落腳點
        if(i >> j & 1){
            for(int k=0 ; k<n ; ++k){//枚舉上一個狀態的落腳點
                if((i - (1 << j)) >> k & 1){
                   dp[j][i] = min(dp[j][i] , dp[k][i - (1<<j)] + dis[k][j]);
                }
            }
        }
    }
}
int MN = INF;
//100 -> 11
for(int i=0 ; i<n ; ++i){
    for(int j=0 ; j<i ; ++j){
        MN = min(MN , dp[i][(1 << n ) - 1] +  dis[i][j]);
    }
}

int MX = .. , MN = ..;
int gcd = __gcd(MX,MN);
cout << (MX/g) << '/' << (MN/g) << '\n';

//1101 <- 1001 , 1100 , 0101 





























