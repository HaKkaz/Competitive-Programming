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
    string str;

    auto have_space = [](string str){
        for(int i=0 ; i<str.size()-1 ; ++i)
            if(str[i] == ' ' and str[i+1] == ' ') return true;
        return false;
    };

    while(getline(cin , str)){
        int ans=0;
        while(have_space(str)){
            ++ans;
            string tmp;
            for(int i=0 ; i<str.size() ; ++i){
                if(str[i] != ' ') tmp += str[i];
                else if(str[i] == ' '){
                    if(i+1 < str.size() and str[i+1] == ' ') ++i , tmp+=' ';
                    else tmp += ' ';
                }
            }
            str = tmp;
        }
        cout << ans << '\n';
    }
}