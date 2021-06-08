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



void knapsack(int wt[],int val[],int w,int n)
{
    if(w == 0 || n == 0)
    return ;

    int t[n+1][w+1];

    for(int i=0;i<=n;i++)
    {
        for(int j = 0;j<=w;j++)
        {
            if(i == 0 || j == 0)
            t[i][j] = 0;

            else if(wt[i-1]<=j)
            {
                t[i][j] = max(val[i-1] + t[i-1][j - wt[i-1]],t[i-1][j]);
                //cout<<max(val[i-1] + t[i-1][j - wt[i-1]],t[i-1][j])<<" ";
               
            }
            else
            {
                t[i][j] = t[i-1][j];
                //cout<<t[i-1][j]<<" ";
            }
            
        }
        cout<<endl;
    }

    cout<<t[n][w]<<endl;


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

   knapsack(wt,val,w,n);


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