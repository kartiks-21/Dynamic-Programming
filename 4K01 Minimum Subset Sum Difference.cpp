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


//O(s*n)
int minimum_subset_sum_difference(int a[],int n,int s)
{
    bool dp[n+1][s+1];

    for(int i=0;i<=s;i++)
    dp[0][i] = false;

    for(int i=0;i<=n;i++)
    dp[i][0] = true;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=s;j++)
        {
            if(a[i-1]>j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else if(a[i-1]<=j)
            {
                dp[i][j] = dp[i-1][j] || dp[i-1][j - a[i-1]];
            }
        }
    }

    int ans = inf;

    for(int i=0;i<=s;i++)
    {
        if(dp[n][i])
        {
            ans = min(ans,abs(s-2*i));
        }
    }

    return ans;
}
void solve ()
{
   int n;
   cin>>n;
   int a[n];
   int s = 0;
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
       s+=a[i];
   }
   
   cout<<minimum_subset_sum_difference(a,n,s)<<endl;


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