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
#define loop(var,s,f,i)      for(var=s; var<=f; var+=i)

int arr[]={1,3,8};
int len_arr=3;
stack<int> stk;

void sub_gen(int i){
	int x,y;
	vector<int> patil;
	if(len_arr==i){
		if(!stk.size()) return; 
		while(stk.size()){
			patil.pb(stk.top());
			stk.pop();
		}
		x=patil.size();
		for(y=x-1; y>=0; y--){
			printf("%d ",patil[y]);
			stk.push(patil[y]);
		}
		nl;
		patil.clear();
		return;
	}
	sub_gen(i+1);
	stk.push(arr[i]);
	sub_gen(i+1);
	stk.pop();
}


int main()
{
	sub_gen(0);
	return 0;
}
