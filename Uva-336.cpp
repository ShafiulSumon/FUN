#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long node,edge,t=1,i,j,a,b,start,ttl,s,x,y,sz;
    while(scanf("%lld",&edge)==1){
        if(edge==0) break;
        map<long long,int> mp;
        vector<int> vec[40];
        int cnt=0;
        for(i=0; i<edge; i++){
            scanf("%lld %lld",&a,&b);
            if(mp[a]==0) mp[a]=++cnt;
            if(mp[b]==0) mp[b]=++cnt;
            vec[mp[a]].push_back(mp[b]);
            vec[mp[b]].push_back(mp[a]);
        }
        node=cnt;
        //cout<<"Node: "<<node<<endl;
        while(1){
            scanf("%lld %lld",&start,&ttl);
            if(start==0 and ttl==0) break;
            s=mp[start];

            bool visit[40];
            memset(visit,false,sizeof visit);
            visit[s]=true;

            int dis[40];
            memset(dis,-1,sizeof dis);
            dis[s]=0;

            queue<int> q;
            q.push(s);
            while(!q.empty()){
                x=q.front();
                q.pop();
                sz=vec[x].size();
                for(i=0; i<sz; i++){
                    y=vec[x][i];
                    if(!visit[y]){
                        visit[y]=true;
                        dis[y]=dis[x]+1;
                        q.push(y);
                    }
                }
            }
            int c=0;
            for(j=1; j<=cnt; j++) if(dis[j]<=ttl and dis[j]!=-1) c++;
            printf("Case %lld: %lld nodes not reachable from node %lld with TTL = %lld.\n",t++,node-c,start,ttl);
            while(!q.empty()) q.pop();
            memset(dis,-1,sizeof dis);
            memset(visit,false,sizeof visit);
        }
        for(i=0; i<40; i++) vec[i].clear();
        mp.clear();
    }
    return 0;
}
