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

int LCS(string x,string y,int n,int m)
{
    if(n == 0 || m==0)
    return 0;

    if(x[n-1] == y[m-1])
        return 1 + LCS(x,y,n-1,m-1);
    
    else 
        return max(LCS(x,y,n-1,m),LCS(x,y,n,m-1)); //Max of Choice
}
void solve ()
{
   string x,y;
   cin>>x;
   cin>>y;
   int n = x.length();
   int m = y.length();
   cout<<LCS(x,y,n,m)<<endl;
   
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
        solve();
    
    return 0;
}