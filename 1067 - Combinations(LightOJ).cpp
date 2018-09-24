#include <iostream>
#include <cstdio>

#define mod 1000003

using namespace std;


long long factorial[1000007];

void fact(){
    long long i,sum;
    factorial[0]=1;
    for(i=sum=1; i<=1000006; i++){
        sum=(sum*(i%mod))%mod;
        factorial[i]=sum;
    }
}

long long Big_MOD(long base, long power){
    if(power==0) return 1;
    if(power%2==0){
        long long x=Big_MOD(base,power/2);
        return ((x%mod)*(x%mod))%mod;
    }
    else {
        long long x=Big_MOD(base,power-1);
        return ((base%mod)*(x%mod))%mod;
    }
}

int main()
{
    fact();
    long long T,t,n,r,ans,ncr;
    while(scanf("%lld",&T)==1){
        t=1;
        while(T--){
            scanf("%lld %lld",&n,&r);
            ans=((factorial[r])*(factorial[n-r]))%mod;
            ncr=(factorial[n]*(Big_MOD(ans,mod-2)))%mod;
            printf("Case %lld: %lld\n",t++,ncr);
        }
    }
    return 0;
}
