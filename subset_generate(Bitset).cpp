#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int arr[100];

void fun(int n){
    int x=0;
    while(n){
        if(n&1) printf("%d ",arr[x]);
        n=n>>1;
        x++;
    }
    printf("\n");
    return;
}

int main()
{
    int n,i,l;
    while(scanf("%d",&n)==1){
        for(i=0; i<n; i++)scanf("%d",&arr[i]);
        l=pow(2,n);/// l<=100000008; so, n<=25
        for(i=1; i<l; i++) fun(i);
    }
    return 0;
}
