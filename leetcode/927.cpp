class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        const int n = arr.size();
        int cnt = accumulate(begin(arr), end(arr), 0);
        if (cnt % 3) return vector<int>{-1,-1};
        if (cnt == 0) return vector<int>{0,2};

        int c1 = 0, c2 = 0, back_zero = 0;
        bool stop = false;

        for (int i = n-1 ; i >= 0; --i) {
            if (arr[i]) stop = true;
            if (!stop) ++back_zero;
        }

        auto get_cut = [&](int st){
            int dd = -1, cc = 0;
            for (int i = st; i < n; ++i) {
                cc += arr[i];
                if (cc == cnt/3) {
                    dd = i + back_zero;
                    break;
                }
            }
            return dd;
        };

        int d1 = get_cut(0);
        int d2 = get_cut(d1+1) + 1;

        if (d1 < 0 || d1 >= n || d2 < 0 || d2 >= n)
            return vector<int>{-1,-1};
        
        vector<int> v1,v2,v3;
        auto getbit = [&](vector<int> &v, int l, int r) {
            for (int i = l; i <= r; ++i) {
                if (v.size() || arr[i]) {
                    v.push_back(arr[i]);
                }
            }
        };

        getbit(v1, 0, d1);
        getbit(v2, d1+1, d2-1);
        getbit(v3, d2, n-1);

        if (v1 == v2 && v2 == v3) 
            return vector<int>{d1,d2};
        else 
            return vector<int>{-1,-1};
    }
};