class Solution {
public:
    int longestValidParentheses(string s) {
        const int n = s.size();
        vector<int> stk;
        int out=0;
        int ans=0;
        for(int i=0 ; i<n ; ++i){
            const char ch = s[i];
            if(ch == '(') stk.push_back(0);
            else if(stk.size()){
                int count = stk.back() + 2;
                stk.pop_back();
                if(stk.size()) stk.back() += count , ans = max(ans , stk.back());
                else out += count;
                ans = max(ans , out);
            }
            else{
                out = 0;
            }
        }
        return ans;
    }
};