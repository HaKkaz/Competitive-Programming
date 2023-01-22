class Solution {
public:
    bool check(string &s) {
        return stoi(s) <= 255 && (s[0] != '0' || (s.size() == 1));
    }

    vector<string> restoreIpAddresses(string s) {
        const int n = s.size();
        if (n > 12) return vector<string>();

        vector<string> ans;

        for (int i = 1; i <= 3; ++i) {
            for(int j = 1; j <= 3; ++j) {
                for (int k=1; k <= 3; ++k) {
                    if (i + j + k + 1 > n) break;
                    if (n - i - j - k > 3) continue;

                    string A = "", B = "", C = "", D = "";
                    for(int z = 0; z < i; ++z) A += s[z];
                    for(int z = i; z < i + j; ++z) B += s[z];
                    for(int z = i + j; z < i + j + k; ++z) C += s[z];
                    for(int z = i + j + k; z < n; ++z) D += s[z];
                    
                    if(check(A) && check(B) && check(C) && check(D)){
                        ans.push_back(A+"."+B+"."+C+"."+D);
                    }
                }
            }
        }
        return ans;
    }
};