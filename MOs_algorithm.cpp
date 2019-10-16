/// problem link: https://www.spoj.com/problems/DQUERY/

#include <bits/stdc++.h>

using namespace std;

struct Query{
	int left,right,ans,index;
};

Query Q[200005];
int arr[30004],freq[1000006];
int block;

bool comp(Query x, Query y){
	if(x.left!=y.left) return x.left<y.left;
	return x.right<y.right;
}

bool c(Query x, Query y){
	return x.index<y.index;
}

void MOs_algorithm(int q,int n){
	block = (int)sqrt(n);
	sort(Q,Q+q,comp);
	memset(freq,0,sizeof(freq));
	int currL=1, currR=1;
	int count=0;
	for(int i=0; i<q; i++){
		int left = Q[i].left;
		int right = Q[i].right;
		while(currL<left){
			freq[arr[currL]]--;
			if(freq[arr[currL]]==0) count--;
			currL++;
		}
		while(currL>left){
			freq[arr[currL-1]]++;
			if(freq[arr[currL-1]]==1) count++;
			currL--;
		}
		while(currR<=right){
			freq[arr[currR]]++;
			if(freq[arr[currR]]==1) count++;
			currR++;
		}
		while(currR>right+1){
			freq[arr[currR-1]]--;
			if(freq[arr[currR-1]]==0) count--;
			currR--;
		}
		Q[i].ans=count;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	int n,q,l,r;
	while(scanf("%d",&n)==1){
		for(int i=1; i<=n; i++){
			scanf("%d",&arr[i]);
		}
		scanf("%d",&q);
		for(int i=0; i<q; i++){
			scanf("%d %d",&l,&r);
			Q[i]={l,r};
			Q[i].index=i;
		}
		MOs_algorithm(q,n);
		sort(Q,Q+q,c);
		for(int i=0; i<q; i++){
			printf("%d\n",Q[i].ans);
		}
	}
	return 0;
}
