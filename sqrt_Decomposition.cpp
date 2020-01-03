#include <bits/stdc++.h>

using namespace std;

int block,arr[100005],b[10004];

void makeBlock(int n){
	memset(b,0,sizeof(b));

	block = ceil(sqrt(n));

	for(int i=0; i<n; i++){
		b[i/block] += arr[i]; 
	}
}

int query(int l, int r, int n){
	int bl = l/block;
	int br = r/block;
	int sum = 0;

	if(bl==br){
		for(int i=l; i<=r; i++){
			sum+=arr[i];
		}
	}
	else{
		for(int i=l, e=((bl+1)*block)-1; i<=e; i++){
			sum+=arr[i];
		}

		for(int i=bl+1; i<=br-1; i++){
			sum+=b[i];
		}

		for(int i=br*block; i<=r; i++){
			sum+=arr[i];
		}
	}

	return sum;
}

int main()
{
	int n,q,l,r;
	while(cin>>n>>q){
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		makeBlock(n);
		while(q--){
			cin>>l>>r;
			int ans = query(l-1,r-1,n);
			cout<<ans<<endl;
		}
	}
	return 0;
}
