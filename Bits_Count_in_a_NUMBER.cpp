// counting bits in a number

//Let's N = 10 and it's binary representation is 1010.

//So if we want to find out how many bits are in number 10, we use log2 function.

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N = 10;
    int numberOfBits = (int) log2(N)+1;
    printf("%d\n",numberOfBits);
    return 0;
}
  
  
