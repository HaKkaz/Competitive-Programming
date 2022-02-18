//tree is Tree
//node is 1-base
#define vi vector<int>
struct LCA
{
    vector< vi > tree;
    vector< vi > ac;
    vector< int > in , out , deep;
    int now_time;
    int n , lg;

    LCA(int _n):n(_n) , lg(__lg(_n)+1){
        tree = vector< vi >(n+1);
        ac = vector< vi >(lg , vi(n+1));
        in = out = deep = vi(n+1);
        now_time=0;
    }

    inline void add_edge(const int &a , const int &b){
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    void DFS(int now , int fa){
        deep[now] = deep[fa] + 1;
        ac[0][now] = fa;
        in[now] = ++now_time;
        for(const int &nxt : tree[now]){
            if(nxt != fa){
                DFS(nxt , now);
            }
        }
        out[now] = ++now_time;
    }


    void build(){
        DFS(1,1);
        for(int i=1 ; i<lg ; ++i){
            for(int j=1 ; j<=n ; ++j){
               ac[i][j] = ac[i-1][ac[i-1][j]];     
            }
        }
    }

    int query(int a , int b){
        auto is_ancestor = [&](const int &a , const int &b){
            return (in[a] <= in[b] && out[a] >= out[b]);
        };
        if(is_ancestor(a,b)) return a;
        if(is_ancestor(b,a)) return b;
        for(int i=lg-1 ; i>=0 ; --i){
            if(!is_ancestor(ac[i][a],b))
                a = ac[i][a];
        }
        return ac[0][a];
    }

    inline int distance(const int &a , const int &b){
        int lca = query(a,b);
        return deep[a] + deep[b] - deep[lca]*2 ;
    }
};
//NOTICE YOUR BASE