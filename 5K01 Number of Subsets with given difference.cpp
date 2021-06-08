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
vector<int> a[200005];
vector<bool> vis(200005,0);
vector<int> dis(200005,0);
vector<int> in(200005,0);
vector<int> low(200005,0);
int timer = 1;

int number_of_subsets_with_given_difference(int a[],int n,int s)
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
                dp[i][j] = dp[i-1][j];

            else if(a[i-1]<=j)
                dp[i][j] = dp[i-1][j] + dp[i-1][j-a[i-1]];
        }
    }

    return dp[n][s];
}

void solve ()
{
   int n;
   cin>>n;

   int a[n];
   int sum = 0;

   for(int i=0;i<n;i++)
   {
       cin>>a[i];
       sum+=a[i];
   }

   int s;
   cin>>s;

   s = (sum + s)/2;

   cout<<number_of_subsets_with_given_difference(a,n,s)<<endl;

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