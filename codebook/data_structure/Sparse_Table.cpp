//a is 0-base
//query is 1-base
struct Sparse_Table
{
    vector< vector<int> > ST;
    void build(vector<int> a){
        int lg = __lg(a.size()+1);
        int sz = a.size();
        ST = vector< vector<int> > (lg , vector<int>(sz+1));
        for(int i=0 ; i<sz ; ++i) ST[0][i+1] = a[i];
        for(int i=1 ; i<lg ; ++i){
            for(int j=1 ; j+(1<<(i-1))<=sz ; ++j){
                ST[i][j] = max(ST[i-1][j],ST[i-1][j+(1<<(i-1))]);
            }
        }
    }

    int query(int l , int r){
        int k = 31-__builtin_clz(r-l+1);
        return max(ST[k][l] , ST[k][r-(1<<k)+1]);
    }    
};