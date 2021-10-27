class LCA{
public: 
    int node,root;

    // make these line global

    // const int N = 1003;

    // vector<int> vec[N];
    // bool vis[N];
    // int level[N], parent[N], SPT[N][(int)log2(N)+1];

    
    LCA(int node, int root){
        this->node = node;
        this->root = root;

        // BFS for leveling the nodes
        memset(vis,false,sizeof(vis));
        memset(level,0,sizeof(level));
        memset(parent,-1,sizeof(parent));

        vis[root] = true;
        level[root] = 0;
        queue<int> Q;

        Q.push(root);

        while(!Q.empty()){
            int u = Q.front();
            Q.pop();
            for(auto v : vec[u]){
                if(!vis[v]){
                    vis[v] = true;
                    level[v] = level[u] + 1;
                    Q.push(v);
                    parent[v] = u;
                }
            }
        }
        // Sparse-table

        // store the parent's of every node 
        // in 2's power
        // SPT[i][j] = x;
        // 'x' is the 2^j -th parent of node 'i'
        for(int i=1; i<=node; i++){
            SPT[i][0] = parent[i]; // 2^0-th parent of i-th node
        }
        for(int j=1; (1<<j)<=node; j++){
            for(int i = 1; i<=node; i++){
                if(SPT[i][j-1]!=-1)
                    SPT[i][j] = SPT[SPT[i][j-1]][j-1];
            }        
        }
    }


    int findLCA(int x, int y){
        if(level[x]<level[y]) swap(x,y); // now level of x is bigger or equal
    
        for(int i = log2(node); i>=0; i--){
            if(level[x]-(1<<i) >= level[y]){
                x = SPT[x][i];
            }
        }
        // now x and y are in same level

        if(x==y) return x; // overlapping node, so that's the LCA

        for(int i = log2(node); i>=0; i--){
            if(SPT[x][i]!=-1 and SPT[x][i]!=SPT[y][i]){
                x = SPT[x][i], y = SPT[y][i];
            }
        }
        return SPT[x][0];
    }
};
