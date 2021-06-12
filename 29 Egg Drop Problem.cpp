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

int eggdrop(int n,int k)
{
    if(k == 0 || k == 1)
        return k;
    if(n == 1)
        return k;

    int res = INT_MAX,mm;

    for(int f=1;f<=k;f++)
    {
        mm = 1 + max(eggdrop(n-1,f-1),eggdrop(n,k-f));
        res = min(res,mm); 
    }

    return res;
}
void solve ()
{
   int n,k;
   cin>>n>>k;

   cout<<eggdrop(2,10);
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
   
        solve();
    
    return 0;
}