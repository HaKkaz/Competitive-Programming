class Solution {
public:
    int findJudge(int n, vector<vector<int>>& t) {
        array<int, 1001> in{},ot{};
        for (auto &tt : t) {
            ot[tt[0]]++;
            in[tt[1]]++;
        }

        for (int i = 1; i <= n; i++){
            if (in[i] == n-1 && ot[i] == 0)
            return i;
        }
        return -1;
    }
};