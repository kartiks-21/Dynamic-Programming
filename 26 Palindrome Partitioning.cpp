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

bool palindrome(string s,int i,int j)
{
    while(i < j)
    {
      if(s[i] != s[j])
        return false; 
      i++;
      j--;
    }
    return true;

}

int number_of_partitions(string s,int i,int j)
{
    if(i>=j)
    return 0;

    if(palindrome(s,i,j))
    return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];

    int mm = INT_MAX,count;
    for(int k=i;k<=j-1;k++)
    {
        if(palindrome(s,i,k))
        {
        count = number_of_partitions(s,i,k) + number_of_partitions(s,k+1,j) + 1;
        mm = min(count,mm);
        }
    }

    return dp[i][j] = mm;
}
 
void solve ()
{
   memset(dp,-1,sizeof(dp));
   string s;
   cin>>s;

   cout<<number_of_partitions(s,0,s.length()-1)<<endl;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
  
        solve();
    
    return 0;
}