#include <iostream>
#include <cstdio>
using namespace std;

#define LL long long
#define mod 100005

LL power_fun(LL n, LL pow){
    if(pow==0) return 1;
    if(pow%2==0){
        LL x=power_fun(n,pow/2);
        return ((x%mod)*(x%mod))%mod;
    }
    else{
        LL x=power_fun(n,pow-1);
        return ((n%mod)*(x%mod))%mod;
    }
}

int main()
{
    int n,pow;
    while(cin >> n >> pow){
        cout<< power_fun(n,pow) << endl;
    }
    return 0;
}
