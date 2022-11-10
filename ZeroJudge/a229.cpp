#include <iostream>
#include <cstring>
using namespace std;
 
int N;
string s;
//int total;
 
void solve(int now, int nL, int nR) {
    if (now == 2 * N) {
        //total++;
        cout << s << "\n";
        return;
    }
    if (nL < N) {
        s[now] = '(';
        solve(now+1, nL+1, nR);
    }
    if (nR < nL) {
        s[now] = ')';
        solve(now+1, nL, nR+1);
    }
}
 
int main() {
    bool first = true;
     
    while (cin >> N) {
        s = "";
        for (int i = 0; i < 2*N; i++){
            s += " "; //placeholder
        }
         
        if (first) first = false;
        else cout << "\n"; // a blank line between test cases
        //total = 0;
        solve(0, 0, 0);
        //cout << N << " : " << total << "\n";
    }
    return 0;
}