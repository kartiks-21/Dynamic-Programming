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

int lcs(string x,string y,int n,int m)
{
    int dp[n+1][m+1];
    int res = -1;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            dp[i][j] = 0;

            else if( x[i-1] == y[j-1])
            {
            dp[i][j] = 1 + dp[i-1][j-1];
            res = max(res,dp[i][j]);
            }
            else
            dp[i][j] = 0;
        }
    }


    return res;
}
void solve ()
{
    string x,y;
    cin>>x;
    cin>>y;

    int n = x.length();
    int m = y.length();

    cout<<lcs(x,y,n,m)<<endl;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
        solve();
    
    return 0;
}