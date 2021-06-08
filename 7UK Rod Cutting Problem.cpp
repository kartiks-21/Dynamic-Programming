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

//Unbounded Knapsack
int rodcutting(int a[],int n)
{
    int dp[n+1][n+1];
    int len[n+1];

    for(int i=0;i<=n;i++)
        len[i] = i+1;

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(len[i-1]>j)
                dp[i][j] = dp[i-1][j];
            else if(len[i-1]<=j)
                dp[i][j] = max(a[i-1] + dp[i][j - len[i-1]],dp[i-1][j]);
        }
    }

    return dp[n][n];
}

void solve ()
{
   int n;
   cin>>n;

   int a[n];
   for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<rodcutting(a,n)<<endl;
    
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}