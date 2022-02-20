#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast" , "unroll-loops" , "fast-math")
using namespace std;
const int MAXN = 2e5+50;
struct suffix_array {
    int box[MAXN], tp[MAXN], m;
    bool not_equ(int a, int b, int k, int n) {
        return ra[a] != ra[b] || a + k >= n ||
            b + k >= n || ra[a + k] != ra[b + k];
    }
    void radix(int *key, int *it, int *ot, int n) {
        fill_n(box, m, 0);
        for (int i = 0; i < n; ++i) ++box[key[i]];
        partial_sum(box, box + m, box);
        for (int i = n - 1; i >= 0; --i)
        ot[--box[key[it[i]]]] = it[i];
    }
    void make_sa(string s, int n) {
        int k = 1;
        for (int i = 0; i < n; ++i) ra[i] = s[i];
        do {
            iota(tp, tp + k, n - k), iota(sa + k, sa + n, 0);
            radix(ra + k, sa + k, tp + k, n - k);
            radix(ra, tp, sa, n);
            tp[sa[0]] = 0, m = 1;
            for (int i = 1; i < n; ++i) {
                m += not_equ(sa[i], sa[i - 1], k, n);
                tp[sa[i]] = m - 1;
            }
            copy_n(tp, n, ra);
            k *= 2;
        } while (k < n && m != n);
    }
    void make_he(string s, int n) {
        for (int j = 0, k = 0; j < n; ++j) {
            if (ra[j])
                for (; s[j + k] == s[sa[ra[j] - 1] + k]; ++k)
                  ;
            he[ra[j]] = k, k = max(0, k - 1);
        }
    }
    int sa[MAXN], ra[MAXN], he[MAXN];
    void build(string s , const int n) {
        fill(sa , sa + n , 0), fill(ra , ra+n , 0), fill(he , he+n , 0);
        fill(box , box + n , 0), fill(tp , tp+n , 0), m = 256;
        make_sa(s, n);
        make_he(s, n);
    }
}SA;

int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    string s;
    while(cin >> s){
        const int n = (int)s.size();
        SA.build(s,n);
        long long ret = 1LL * n * (n+1) /2 + 1;
        for(int i=1 ; i<n ; ++i){
            ret -= SA.he[i];
        }
        cout << ret << '\n';
    }
}

