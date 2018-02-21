#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>

using namespace std;

#define PI                   acos(-1)
#define inf                  1e9
#define ms(a,b)              memset(a,b,sizeof a)
#define CLR(a)               memset(a,0,sizeof a)
#define input_file           freopen("in.txt","r",stdin)
#define output_file          freopen("out.txt","w",stdout)
#define fast                 ios_base::sync_with_stdio(0); cin.tie(0)
#define N                    100000008
#define LL                   long long
#define nl                   printf("\n")
#define spc                  printf(" ")
#define isValid(a,b,A,B)      ((0<=a&&a<A) && (0<=b&&b<B))
#define Abs(a,b)             a>b ? a-b : b-a // if a>b is true return a-b eles b-a
#define pb                   push_back
#define mp                   make_pair
#define sq(n)                (n*n)
#define sf                   scanf
#define pf                   printf

/* "Life is amazing, Enjoy it"........................*/

int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};

int n,e,t=0;
int visit_time[100005],low_time[100005];
int parent[100005];
bool visit[100005];
vector<int> articulation_point,vec[100005];


void tarjans_algo(int node){
    visit_time[node]=low_time[node]=t++;
    bool ap=false;
    int child=0;
    int sz=vec[node].size();
    for(int k=0; k<sz; k++){
        int adj_node=vec[node][k];
        if(parent[node]==adj_node) continue;
        if(!visit[adj_node]){
            visit[adj_node]=true;
            child++;
            parent[adj_node]=node;
            tarjans_algo(adj_node);
            if(visit_time[node]<=low_time[adj_node]) ap=true;
            else low_time[node]=min(low_time[node],low_time[adj_node]);
        }
        else{ /// backedge found
            low_time[node]=min(low_time[node],visit_time[adj_node]);
        }
    }
    if(parent[node]!=-1 and ap) articulation_point.pb(node);
    else if(parent[node]==-1 and child>1) articulation_point.pb(node);
}



int main()
{
    int a,b,root;
    while(cin>>n>>e){
        for(int i=0; i<e; i++){
            cin>>a>>b;
            vec[a].pb(b);
            vec[b].pb(a);
        }
        cin>>root;
        for(int i=0; i<100005; i++){
            parent[i]=-1;
            visit[i]=false;
        }
        tarjans_algo(root);
        int sz=articulation_point.size();
        sort(articulation_point.begin(), articulation_point.end());
        for(int i=0; i<sz; i++){
            cout<<articulation_point[i];spc;
        }
        nl;
    }
  return 0;
}
