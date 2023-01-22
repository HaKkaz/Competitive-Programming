class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        vector<int> Lmx(n);
        vector<int> Rmx(n);
        for(int i=0  ,mx=0 ; i< n ; ++i) Lmx[i] = mx , mx = max(height[i] , mx);
        for(int i=n-1,mx=0 ; i>=0 ; --i) Rmx[i] = mx , mx = max(height[i] , mx);
        int ans = 0 ;
        for(int i=1 ; i<n-1 ; ++i){
            ans += max(0 , min(Lmx[i] , Rmx[i]) - height[i]);
        }
        return ans;
    }
};