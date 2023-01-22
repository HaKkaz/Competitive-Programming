class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        const int n = words.size();
        unordered_set<string> table;
        for(auto &str : words) table.emplace(str);
        
        vector< string > ans;
        for(int i=0 ; i<n ; ++i){
            auto &word = words[i];
            const int len = word.size();
            if(len == 0) continue;
            vector< int > ok(len , 0);
            for(int l=0 ; l<len ; ++l){
                string sub="";
                for(int r=l ; r<len ; ++r){
                    sub += word[r];
                    if(table.find(sub) != table.end()){
                        if(l == 0 || ok[l-1]){
                            ok[r] = (l == 0 ? 1 : ok[l-1] + 1);
                        }
                    }
                }
            }
            if(ok.back() > 1) ans.emplace_back(word);
        }
        return ans;
    }
};