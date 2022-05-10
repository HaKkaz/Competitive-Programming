class Solution {
public:
    string longestPalindrome(string s) {
        const int n = (int)s.size();
        int ans = 0 , pos = 0;
        for(int i=0 ; i<n ; ++i){
            for(int l = i , r = i ; l >= 0 and r < n ; --l , ++r){
                if(s[l] != s[r]) break;
                if(r - l + 1 > ans){
                    pos = l;
                    ans = r-l+1;
                }
            }
            for(int l = i , r = i+1 ; l>=0 and r < n ; --l , ++r){
                if(s[l] != s[r]) break;
                if(r - l + 1 > ans){
                    pos = l;
                    ans = r-l+1;
                }
            }
        }
        return s.substr(pos , ans);
    }
};