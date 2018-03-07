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
#define SZ(a)                a.size()
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

bool visit[100005];
int visit_time[100005],low_time[100005],parent[100005],t=0;
vector<int> vec[100005],bridge;
vector<Pr> ans;


void func(int node){
    visit_time[node]=low_time[node]=t++;
    visit[node]=true;
    int sz=vec[node].size();
    for(int k=0; k<sz; k++){
        int x=vec[node][k];
        if(parent[node]==x) continue;
        if(!visit[x]){
            parent[x]=node;
            func(x);
            if(visit_time[node]<low_time[x]){
                bridge.pb(min(node,x));
                bridge.pb(max(node,x));
            }
            else{
                low_time[node]=min(low_time[node],low_time[x]);
            }
        }
        else{ /// backedge
            low_time[node]=min(low_time[node],visit_time[x]);
        }
    }
}


int main()
{
    //input_file;
    //output_file;
    int node,a,b,e,line=0;
    while(sf("%d",&node)==1){
        // if(line) cout<<endl;
        // line=1;
        for(int i=0; i<node; i++){
            sf("%d (%d)",&a,&e);
            for(int j=0; j<e; j++){
                sf("%d",&b);
                vec[a].pb(b);
                vec[b].pb(a);
            }
        }
        ms(visit, false);
        for(int i=0; i<node; i++){
            parent[i]=-1;
        }
        bridge.clear();
        for(int i=0; i<node; i++){
            if(!visit[i]){
                t=0;
                func(i);
            }
        }
        int sz=bridge.size();
        cout<<sz/2<<" critical links"<<endl;
        for(int i=0; i<sz; i+=2){
            //cout<<bridge[i]<<" - "<<bridge[i+1]<<endl;
            ans.pb(Pr(bridge[i],bridge[i+1]));
        }
        sort(ans.begin(), ans.end());
        for(int i=0; i<sz/2; i++){
            a=ans[i].first;
            b=ans[i].second;
            cout<<a<<" - "<<b<<endl;
        }
        for(int i=0; i<node+5; i++){
            vec[i].clear();
        }
        ans.clear();
        cout<<endl;
    }
	return 0;
}

