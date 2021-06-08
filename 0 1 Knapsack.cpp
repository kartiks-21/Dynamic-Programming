/* Author Kartik Shukla */
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
typedef long long int ll;
#define mod 998244353
#define MOD 1000000007
#define PI 3.14159265358
vector<int> a[200005];
vector<bool> vis(200005,0);
vector<int> dis(200005,0);

int knapsack(int wt[],int val[],int w,int n)
{
    if(w == 0 || n == 0)
    return 0;

    if(wt[n-1]>w)
    {
        return knapsack(wt,val,w,n-1);    
    }
    else 
    {
        return max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
    }
}
 
void solve ()
{
   int n,w;
   cin>>n>>w;

   int wt[n],val[n];
   for(int i=0;i<n;i++)
   cin>>wt[i];
   for(int i=0;i<n;i++)
   cin>>val[i];

   cout<<knapsack(wt,val,w,n)<<endl;


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