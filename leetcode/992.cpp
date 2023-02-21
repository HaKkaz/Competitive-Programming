class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        array<int,20005> cnt{}, pos{};
        multiset<int> left;
        deque<int> dq;
        int diff = 0, ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            //push
            dq.push_back(nums[i]);
            cnt[nums[i]]++;
            if (cnt[nums[i]] == 1) ++diff;
            else left.erase(pos[nums[i]]);
            pos[nums[i]] = i;
            left.insert(i);

            //pop
            while(diff > k) {
                int pop = dq.front();
                dq.pop_front();
                cnt[pop]--;
                if (cnt[pop] == 0) {
                    --diff;
                    left.erase(pos[pop]);
                }
            }

            if (diff == k){
                int l = i - dq.size() + 1;
                int r = *left.begin();
                ans += (r-l+1);
                // cout << l << ' ' << r << '\n';
            }
        }
        return ans;
    }
};