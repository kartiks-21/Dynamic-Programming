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

int countofsubset(int n,int a[],int s)
{
    int dp[n+1][s+1];

    for(int i=0;i<=s;i++)
    {
        dp[0][i] = 0;
    }
     for(int i=0;i<=n;i++)
    {
        dp[i][0] = 1;
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
        {

            if(a[i-1]>j && i!=0 && j!=0)
            {
                dp[i][j] = dp[i-1][j];
            }
            else if(a[i-1]<=j && i!=0 && j!=0)
            {
                dp[i][j] = dp[i-1][j-a[i-1]]+dp[i-1][j];
            }
            
        }
        
    }



    return dp[n][s];
}

void solve ()
{
   int n;
   cin>>n;

   int a[n];

   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   }

   int s;
   cin>>s;

   cout<<countofsubset(n,a,s);
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
        solve();
    
    return 0;
}