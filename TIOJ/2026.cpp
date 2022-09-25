#include"bits/stdc++.h"
using namespace std;
priority_queue<int> A;
priority_queue<int , vector<int> , greater<int>> B;
int main(){
    ios::sync_with_stdio(false), cin.tie(0),cout.tie(0);
    int q;
    cin >> q;
    while(q--){
        int opt; cin >> opt;
        if(opt == 1){
            int k; cin >> k ;
            if(B.empty()) B.push(k);
            else if(k >= B.top()) B.push(k);
            else A.push(k);
            // 詢問有保證數字總數量為奇數，所以維護B.size()=A.size()+1即可
            if(B.size() - A.size() > 1) A.push(B.top()) , B.pop(); 
            if(A.size() >= B.size()) B.push(A.top()) , A.pop();
        }
        if(opt == 2) cout << B.top() << '\n';
    }
}