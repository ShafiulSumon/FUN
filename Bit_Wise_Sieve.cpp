#include <bits/stdc++.h>
#define N 100000008

using namespace std;

bool Check(int a, int b){return a&(1<<b);}
int Set(int a, int b){return a|(1<<b);}

int status[N/32];

void bitWiseSieve(){
    status[0]=Set(status[0],0);
    status[0]=Set(status[0],1);
    for(int i=2; i*i<N; i++){
        if(Check(status[i/32],i%32)==0){
            for(int j=i*i; j<N; j+=i){
                status[j/32]=Set(status[j/32],j%32);
                /// 32 is equal to 2^5;
                /// multiplication by 2 means n<<1;
                /// multiplication by 8(2^3) means n<<3;
                /// divided by 8(2^3) means n>>3;
                /// modulus with mod(n%mod) means (n & mod-1);
                ///status[j>>5]=Set(status[j>>5],j&31);
                /// this optimization may save your valuable time :D
            }
        }
    }
}

int main()
{
    bitWiseSieve();
    int n;
    while(cin>>n){
        if(Check(status[n>>5],n&31)==0) cout<<"Prime"<<endl;
        else cout<<"Not Prime"<<endl;
    }
    return 0;
}
