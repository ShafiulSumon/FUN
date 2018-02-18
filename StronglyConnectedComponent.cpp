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
#include <utility>

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
#define isValid(a,b,A,B)   	 ((0<=a&&a<A) && (0<=b&&b<B))
#define Abs(a,b)             a>b ? a-b : b-a // if a>b is true return a-b eles b-a
#define pb                   push_back
#define mp                   make_pair
#define sq(n)                (n*n)
#define sf                   scanf
#define pf                   printf

int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};

typedef pair<int,int> Pr;


/* "Finish the race, even you become last"........................*/


bool visit[30];
stack<int> st,ans;
vector<int> vec[30],rev[30];

void make_fine(int node){
    visit[node]=true;
    int sz=vec[node].size();
    for(int i=0; i<sz; i++){
        int x=vec[node][i];
        if(!visit[x]){
            make_fine(x);
        }
    }
    //cout<<"node: "<<node<<endl;
    st.push(node);
}

void DFS(int node){
    ans.push(node);
    visit[node]=true;
    int sz=rev[node].size();
    for(int k=0; k<sz; k++){
        int x=rev[node][k];
        if(!visit[x]){
            DFS(x);
        }
    }
}

int main()
{
    input_file;
    int node,edge,a,b;
    while(sf("%d %d",&node,&edge)==2){
        for(int i=0; i<edge; i++){
            sf("%d %d",&a,&b);
            vec[a].pb(b);
            rev[b].pb(a);
        }
        ms(visit, false);
        for(int i=0; i<node; i++){
            if(!visit[i]){
                make_fine(i+1);
            }
        }
        ms(visit, false);
        while(!st.empty()){
            int x=st.top();
            st.pop();
            if(!visit[x]){
                DFS(x);
                while(!ans.empty()){
                    cout<<ans.top();spc;
                    ans.pop();
                }
                nl;
            }
        }
    }
	return 0;
}
