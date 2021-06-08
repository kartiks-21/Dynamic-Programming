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

void number_of_insertions_or_deletions(string x,string y,int n,int m)
{
    int dp[n+1][m+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            dp[i][j]=0;

            else if(x[i-1] == y[j-1])
            dp[i][j] = 1 + dp[i-1][j-1];

            else
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    cout<<"Number of deletions "<<max(n,m)-dp[n][m]<<'\n'<<"Number of insertions "<<min(n,m)-dp[n][m]<<endl;
}

void solve ()
{
    string x,y;
    cin>>x;
    cin>>y;

    int n = x.length();
    int m = y.length();

    number_of_insertions_or_deletions(x,y,n,m);
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
        solve();
    
    return 0;
}