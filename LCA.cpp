#include <bits/stdc++.h>

#define ll                 long long
#define sf                 scanf
#define pf                 printf
#define nl                 printf("\n")
#define endl               '\n'
#define pb                 push_back
#define rep(i,a,b)         for(int i=a; i<b; i++)
#define repr(i,a,b)        for(int i=a; i>=b; i--)
#define TEST               int Test;cin>>Test;for(int _t=1;_t<=Test;_t++)
#define isValid(a,b,A,B)   (0<=a&&a<A) and (0<=b&&b<B)

using namespace std;

template <typename... T> void read(T &... args){ ((cin >> args), ...); }

typedef pair<int,int> Pr;

void yes(){ pf("Yes\n"); }
void no() { pf("No\n"); }

vector<int> vec[1003];
bool vis[1003];
int level[1003],parent[1003],SPT[1003][10];

void BFS(){
    memset(vis,false,sizeof(vis));
    memset(level,0,sizeof(level));
    memset(parent,-1,sizeof(parent));

    vis[1] = true;
    level[1] = 0;
    queue<int> Q;

    Q.push(1);

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
}

void sparse_table(int node){
    for(int i=1; i<=node; i++){
        SPT[i][0] = parent[i]; // 0-th parent of i-th node
    }
    for(int j=1; (1<<j)<=node; j++){
        for(int i = 1; i<=node; i++){
            if(SPT[i][j-1]!=-1)
                SPT[i][j] = SPT[SPT[i][j-1]][j-1];
        }        
    }
}


void Precal(int node){
    BFS();
    sparse_table(node);
}


int find_LCA(int x, int y, int node){
    if(level[x]<level[y]) swap(x,y); // now level of x is bigger or equal
    for(int i = log2(node); i>=0; i--){
        if(level[x]-(1<<i) >= level[y]){
            x = SPT[x][i];
        }
    }
    // now x and y are in same level

    if(x==y) return x;

    for(int i = log2(node); i>=0; i--){
        if(parent[x]!=-1 and SPT[x][i]!=SPT[y][i]){
            x = SPT[x][i], y = SPT[y][i];
        }
    }
    return parent[x];
}

int main()
{	
    int cas = 1;
    int node,m,v,x,y,query;
    TEST{
        read(node);
        rep(i,1,node+1){
            read(m);
            rep(j,0,m){
                read(v);
                vec[i].pb(v);
                vec[v].pb(i);
            }
        }

        Precal(node);

        pf("Case %d:\n",cas++);
        read(query);
        while(query--){
            read(x,y);
            int ans = find_LCA(x,y,node);
            if(ans==-1) ans = 1;
            pf("%d\n",ans);
        }
        rep(i,1,node+1) vec[i].clear();
    }	
	return 0;
}
