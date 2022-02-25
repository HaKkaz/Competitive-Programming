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

const ll INF = 0xffffffff;

int fpow(int a,  int p){
    int ret=1;
    for( ; p ; p >>= 1 , a = a * a)
        if(p & 1) ret = ret * a;
    return ret;
}

signed main(){
    fast;
    string s;
    while(getline(cin , s)){
        s+='z';
        const int len = s.size();
        string now="";
        for(int i=0 ; i<len ; ++i){

            auto hex = [&](string str){
                ll ret = 0 ;
                if(str.size() > 10 || str.size() <= 2) return (ll)1e18;
                for(int i=0,j=str.size()-1 ; i<str.size() ; ++i,--j){
                    int r=0;
                    if(str[i] >= '0' && str[i] <= '9')
                        r = str[i] - 48;
                    else if(str[i] >= 'a' && str[i] <= 'f')
                        r = str[i] - 87;
                    else if(str[i] >= 'A' && str[i] <= 'F')
                        r = str[i] - 55;
                    ret += r * fpow(16,j);
                }
                return ret;
            };


            if(now.empty()){
                if(s[i] == '0') now+=s[i];
            }
            else if(now.size() == 1){
                if(s[i] == 'x' || s[i] == 'X'){
                    now += s[i];
                }
            }
            else if(isdigit(s[i]) || ('a'<=s[i] && s[i]<='f') || ('A'<=s[i]&&s[i]<='F')){
                now+=s[i];
            }
            else{
                cout << now << ' ' << hex(now) << '\n';
                now = "";
            }
        }
    }
}