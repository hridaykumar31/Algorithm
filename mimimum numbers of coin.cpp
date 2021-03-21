#include<bits/stdc++.h>
#define MAX 10000000
using namespace std;
int dp[100][10000];
int min_num_coins(int size,int coins[],int w)
{
    for(int i=0;i<=5;i++)
    {
      dp[i][0]=0;
    }
    for(int i=1;i<=w;i++)
    {
        dp[0][i]=MAX;
    }
    for(int i=1;i<=5;i++)
    {
        for(int j=0;j<=w;j++)
        {
           if(coins[i-1]>j)
           {
             dp[i][j]=dp[i-1][j];
           }
           else
           {
               dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
           }
        }
    }

    return dp[size][w];
}
int main()
{
  int coins[5]={2,5,8,9,10};
  int res=min_num_coins(5,coins,205);
 cout<<"Minimum numbers of coin use :"<<res<<endl;
 vector<int>v;
 map<int,int>mp;
 int i=5,j=205;
  while(j!=0)
  {
    if(dp[i][j]!=dp[i-1][j])
    {
        v.push_back(coins[i-1]);
        j=j-coins[i-1];
    }
    else
    {
     i--;
    }
  }
  for(int i:v)
  {
    mp[i]++;
  }
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  for(int i=0;i<v.size();i++)
  {
      cout<<"coins use "<<v[i]<<" tk "<<mp[v[i]]<<" times"<<endl;
  }


 return 0;
}
