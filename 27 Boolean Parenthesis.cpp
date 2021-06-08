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

int dp[101][101][2];

int parenthesization(string s,int i,int j,int istrue)
{
    if(i>j)
    return 0;

    if(i == j)
    {
        if(istrue == 1)
        return s[i] == 'T';
        else
        return s[i] == 'F';
    }

    if(dp[i][j][istrue]!=-1)
    return dp[i][j][istrue];

    int ans = 0;

    for(int k = i+1;k<=j-1;k+=2)
    {
        int leftt,rightt,leftf,rightf;

        if(dp[i][k-1][1] == -1)
        {
            leftt = parenthesization(s,i,k-1,1);
        }
        else
        {
            leftt = dp[i][k-1][1];
        }

        if(dp[k+1][j][1] == -1)
        {
            rightt = parenthesization(s,k+1,j,1);
        }
        else
        {
            rightt = dp[k+1][j][1];
        }

        if (dp[i][k - 1][0] == -1)
        {
            
            leftf = parenthesization(s, i, k - 1, 0);
        }
        else
        {
            leftf = dp[i][k - 1][0];
        }
 
        if (dp[k + 1][j][0] == -1)
        {
            
            rightf = parenthesization(s, k + 1, j, 0);
        }
        else
        {
            rightf = dp[k + 1][j][0];
        }

        if (s[k] == '&')
        {
            if (istrue == 1)
                ans += leftt * rightt;
            else
                ans += leftf * rightf + leftt * rightf
                       + leftf * rightt;
        }
        else if (s[k] == '|')
        {
            if (istrue == 1)
                ans += leftt * rightt + leftt * rightf
                       + leftf * rightt;
            else
                ans = ans + leftf * rightf;
        }
        else if (s[k] == '^')
        {
            if (istrue == 1)
                ans = ans + leftf * rightt + leftt * rightf;
            else
                ans = ans + leftt * rightt + leftf * rightf;
        }
        dp[i][j][istrue] = ans;
    }


    return ans;

}
 
void solve ()
{
    string s;
    cin>>s;
   cout<<parenthesization(s,0,s.length()-1,1);
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
        solve();
    
    return 0;
}