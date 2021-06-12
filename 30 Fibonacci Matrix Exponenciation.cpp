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

vector<vector<int>> multiply(vector<vector<int>> &a,vector<vector<int>> &b)
{
    vector<vector<int>> c = {{0,0},{0,0}};

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            ll sum = 0;
            for(int k=0;k<2;k++)
            {
                sum+=(a[i][k]*b[k][j]);
            }

            c[i][j] = sum;
        }
    }

    return c;
}

void power(vector<vector<int>> &f,int n)
{
    if(n == 1)
        return;

    power(f,n/2);
    f = multiply(f,f);

    if(n%2 == 1)
    {
        vector<vector<int>> m = {{1,1},{1,0}};
        f = multiply(f,m);
        return;
    }   

}
 
void solve ()
{
   int n;
   cin>>n;

   vector<vector<int>> f = {{1,1},{1,0}};

   power(f,n-2);
   cout<<f[0][0] + f[0][1]<<endl;


}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
        solve();
    
    return 0;
}