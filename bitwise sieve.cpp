#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
int primes[MAX/32+1];
vector<int>v;
bool cheak(int n,int pos)
{
    return (bool)(n&(1<<pos));
}
int mark(int n,int pos)
{
    return n|=(1<<pos);
}
int main()
{
  for(int i=3;i<=sqrt(MAX);i++)
  {
if(!cheak(primes[i/32],i%32))
      {
        for(int j=i*i;j<=MAX;j+=(i*2))
        {
            primes[j/32]=mark(primes[j/32],j%32);
        }
      }
  }
  v.push_back(2);
  for(int k=3;k<=MAX;k+=2)
  {
      if(!cheak(primes[k/32],k%32))
      {
        v.push_back(k);
      }
  }
  for(int i:v)
  {
      cout<<i<<" ";
  }



 return 0;
}
