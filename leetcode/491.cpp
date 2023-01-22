class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& a) {
        const int n = a.size();
        vector<vector<int>> ans;
        for (int i = 0; i < (1<<n); i++) {
            if (__builtin_popcount(i)<=1) continue;
            bool ok = true;
            vector<int> tmp;

            for (int j = 0; j < n; ++j) {
                if (i>>j&1) {
                    if (tmp.empty() or tmp.back() <= a[j])
                    tmp.push_back(a[j]);
                    else ok = false;
                }
            }
            if (ok) {
                ans.push_back(tmp);
            }
        }
        sort(begin(ans), end(ans));
        ans.resize(unique(begin(ans), end(ans)) - ans.begin());
        return ans;
    }
};