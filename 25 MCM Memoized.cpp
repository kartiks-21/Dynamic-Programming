/* Author Kartik Shukla */
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
typedef long long int ll;
#define mod 998244353
#define MOD 1000000007
#define PI 3.14159265358
#define inf 1e9
#define INF 1e18

int dp[1005][1005];

int mcm(int a[],int i,int j)
{
    if(i>=j)
    return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];

    int mm = INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int cost = mcm(a,i,k) + mcm(a,k+1,j) + a[i-1]*a[k]*a[j];
        mm = min(cost,mm);
    }

    return mm;
}
 
void solve ()
{
   memset(dp,-1,sizeof(dp));
   int n;
   cin>>n;

   int a[n];
   for(int i=0;i<n;i++)
   cin>>a[i];
   cout<<mcm(a,1,n-1);
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
  
        solve();
    
    return 0;
}