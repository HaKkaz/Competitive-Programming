#include<bits/stdc++.h>
using namespace std;
int ans[105][105] , n , m;
bool check(int x , int y){
    bool ok = 1;
    for(int i=0 ; i<n*n ; ++i){
        if(i != y && ans[x][i] == ans[x][y]) ok = 0;//橫的
        if(i != x && ans[i][y] == ans[x][y]) ok = 0;//值得
    }

    for(int i=x/n*n ; i<x/n*n+n ; ++i){//小九宮格
        for(int j=y/n*n ; j<y/n*n+n ; ++j){
            if(i == x && j == y) continue;
            if(ans[i][j] == ans[x][y]) ok = 0;
        }
    }        
    return ok;
}
bool hav_ans = 0;
void solve(int x , int y){
    if(hav_ans) return;//已經有答案了 直接return

    //代表已經把所有格子填滿了
    if(x == n*n && y == 0){
        for(int i=0 ; i<n*n ; ++i){
            for(int j=0 ; j<n*n ; ++j){
                cout << ans[i][j] ;
                if(j != n*n-1) cout << ' ';
            }
            cout << '\n';
        }
        hav_ans = 1;
        return;
    }

    //下一格遞迴的位置
    int nxt_x = x , nxt_y = y+1;
    if(nxt_y == n*n) nxt_x++ , nxt_y = 0;

    //看現在這格(x,y)有沒有被填過數字
    if(ans[x][y] != 0) solve(nxt_x , nxt_y);//有
    else{
        for(int num=1 ; num<=n*n ; ++num){
            ans[x][y] = num;
            if(check(x,y)){//剪枝
                solve(nxt_x , nxt_y);
            }
            ans[x][y] = 0;
        }
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    while(cin >> n){
        hav_ans = 0;
        for(int i=0 ; i<n*n ; ++i){
            for(int j=0 ; j<n*n ; ++j){
                cin >> ans[i][j];
            }
        }
        solve(0,0);
        if(!hav_ans) cout << "NO SOLUTION\n";
    }
}