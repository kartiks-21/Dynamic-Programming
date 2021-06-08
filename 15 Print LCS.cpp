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
    vector<char> a;
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
                //a.push_back(x[i-1]);
            }

            else
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    int idx = dp[n][m];
    char lcsp[idx+1];
    lcsp[idx] = '\0';

    int i = m,j = n;
    while(i>0 && j>0)
    {
        if(x[i-1] == y[j-1])
        {
            lcsp[idx-1] = x[i-1];
            i--;
            j--;
            idx--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            i--;
            else
            j--;
        }
    }

    for(int i=0;i<dp[n][m];i++)
        cout<<lcsp[i]<<" ";

    return dp[n][m];
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