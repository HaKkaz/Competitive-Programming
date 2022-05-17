#include<bits/stdc++.h>
using namespace std;
int main(){
    int t ; cin >> t;
    for(int i=0 ; i<t ; ++i){
        cout << "Case #" << i+1 << ":\n";
        int n , m;  cin >> n >> m ;
        int N = (n-1)*2 + 3;
        int M = (m-1)*2 + 3;
        vector< vector<char> > ans(N , vector<char>(M));
        for(int i=0 ; i<N ; i++){
            for(int j=0 ; j<M ; ++j){
                if(i & 1){
                    if(j & 1) ans[i][j] = '.';
                    else ans[i][j] = '|';
                }
                else{
                    if(j & 1) ans[i][j] = '-';
                    else ans[i][j] = '+';
                }
            }
        }
        ans[0][0] = ans[0][1] = ans[1][0] = '.';
        for(auto &c : ans){
            for(auto &cc : c){
                cout << cc;
            }
            cout << '\n';
        }
    }
}