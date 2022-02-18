struct DSU
{
    vector<int> fa;
    vector<int> rk;
    DSU(int _n){
        fa.resize(_n+1);
        iota(ALL(fa),0);
        fill(ALL(rk),1);
    }
    int Find(int x){
        if(x == fa[x]) return x;
        return fa[x] = Find(fa[x]);
    }
    void Union(int a , int b){
        a = Find(a) , b = Find(b);
        if(a == b) return;
        if(rk[a] < rk[b]) swap(a,b);
        fa[b] = a;
        rk[a] += rk[b];
    }
    bool same(int a , int b){
        return Find(a) == Find(b);
    }

};