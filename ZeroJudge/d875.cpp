#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define _ <<' '<<
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
#define tiii tuple<int,int,int>
using ll = long long;
using ld = long double;
using pii = pair<int,int>;

signed main(){
    fast;
    int n;
    while(cin >> n){
        vector<int> ans;
        for(int i=sqrt(n)+1 ; i>=1 ; --i){//枚舉一個數字當最高點，通常越大越好，所以從大的開始枚舉
            int d = (1+i)*i/2 + i*(i-1)/2;//d = 1+2+3+...+i+(i-1)+(i-2)+...+1
            if(d <= n){
                int need = n - d;
                vector<int> ans;
                for(int j=1 ; j<=i ; ++j) ans.push_back(j);
                while(need >= i) ans.push_back(i) , need -= i; //如果d不足n ，盡量補 i 進去
                for(int j=i-1 ; j>=1 ; --j){
                    ans.push_back(j);
                    if(need == j) ans.push_back(j);
                }
                
                reverse(ALL(ans));
                for(int &x : ans) cout << x << ' ';
                cout << '\n';
                break;
            }
        }
    }
}