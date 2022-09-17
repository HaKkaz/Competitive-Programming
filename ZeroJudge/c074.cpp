#include<bits/stdc++.h>
using namespace std;
int n , a[20];
vector< vector<int> > vs;
vector<int> v;

void dfs(int x , int cnt){
    if(cnt > 6) return;
    if(cnt == 6){
        vs.push_back(v);
        return;
    }
    dfs(x + 1 , cnt);
    v.push_back(a[x]);
    dfs(x + 1, cnt + 1);
    v.pop_back();
}

int main(){
    while(cin >> n , n){
        for(int i=0 ; i<n ; ++i) cin >> a[i];
        for(int i=0 ; i<n ; ++i){
        }
    }
}
