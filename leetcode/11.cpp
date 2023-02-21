class Solution {
public:
    int maxArea(vector<int>& height) {
        const int n = height.size();
        vector< pair<int,int> > hh(n);
        for (int i = 0; i < n; ++i) {
            hh[i].first = height[i];
            hh[i].second = i;
        }

        sort(begin(hh), end(hh), greater<pair<int,int>>());
        const int inf = 1e9;
        int mn = inf;
        int mx = -inf;
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            auto [h,p] = hh[i];
            ans = max(ans, 1LL * h * (p - mn));
            ans = max(ans, 1LL * h * (mx - p));
            mn = min(mn, p);
            mx = max(mx, p);
        }
        return ans;
    }
};