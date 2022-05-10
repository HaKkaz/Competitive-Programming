class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector< vector<int> > ans;
        for(int i=0 ; i<(1<<9) ; ++i){
            int count = 0;
            int sum = 0 ;
            vector<int> tmp;
            for(int j=0 ; j<9 ; ++j){
                if(i >> j & 1){
                    count++;
                    sum += j + 1;
                    tmp.push_back(j+1);
                }
            }
            if(sum == n && count==k){
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};