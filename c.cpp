#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#define PI                   acos(-1)
#define inf                  1e9   // this is double value
#define ms(a,b)              memset(a,b,sizeof a)
#define CLR(a)               memset(a,0,sizeof a)
#define input_file           freopen("in.txt","r",stdin)
#define output_file          freopen("out.txt","w",stdout)
#define N                    100000008
#define LL                   long long
#define nl                   printf("\n")
#define spc                  printf(" ")
#define isValid(x,y,dx,dy)   ((0<=dx&&dx<x) && (0<=dy&&dy<y)) 
#define Abs(a,b)             a>b ? a-b : b-a // if a>b is true return a-b eles b-a
#define pb                   push_back
#define sq(n)                (n*n)   
#define si(x)                scanf("%d",&x)
#define sii(x,y)             scanf("%d%d",&x,&y)
#define siii(x,y,z)          scanf("%d%d%d",&x,&y,&z)
#define sl(x)                scanf("%lld",&x)
#define sll(x,y)             scanf("%lld%lld",&x,&y)
#define slll(x,y,z)          scanf("%lld%lld%lld",&x,&y,&z)
#define ss(ch)               scanf("%s",ch)
#define pi(x)                printf("%d",x)
#define pii(x,y)             printf("%d %d",x,y)
#define pl(x)                printf("%lld",x)
#define pll(x,y)             printf("%lld %lld",x,y)
#define ps(ch)               printf("%s",ch)

int n;
stack<int> st;

void subset(int x){
	if(x==n){
		int i,sz;
		if(st.size()==0) return;
		vector<int> vec;
		while(st.size()){
			vec.pb(st.top());
			st.pop();
		}
		sz=vec.size();
		for(i=sz-1; i>=0; i--){
			pi(vec[i]);
			st.push(vec[i]);
		}
		nl;
		vec.clear();
		return;
	}
	st.push(0);
	subset(x+1);
	st.pop();
	st.push(1);
	subset(x+1);
	st.pop();
	
}

int main()
{
	while(si(n)==1){
		subset(0);
	}
	return 0;
}


