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

int max_number_of_ways(int a[],int n,int s)
{
    int dp[n+1][s+1];

    for(int i=0;i<=s;i++)
        dp[0][i] = 0;

    for(int i=0;i<=n;i++)
        dp[i][0] = 1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=s;j++)
        {
            if(a[i-1]>j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i][j-a[i-1]] + dp[i-1][j];
            }
        }
    }

    return dp[n][s];
}
void solve ()
{
   int n,s;
   cin>>n>>s;
   int a[n];
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   }
   cout<<max_number_of_ways(a,n,s)<<endl;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
        solve();
    
    return 0;
}