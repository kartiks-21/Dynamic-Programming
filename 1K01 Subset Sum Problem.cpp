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

bool subasum(vector<int> a,int sum)
{
    int n = a.size();
    bool suba[n + 1][sum + 1];
 
   
    for (int i = 0; i <= n; i++)
        suba[i][0] = true;
 
    for (int i = 1; i <= sum; i++)
        suba[0][i] = false;
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < a[i - 1])
                suba[i][j] = suba[i - 1][j];
            if (j >= a[i - 1])
                suba[i][j] = suba[i - 1][j]
                               || suba[i - 1][j - a[i - 1]];
        }
    }
 
    return suba[n][sum];
}
 
void solve ()
{
    int n,sum;
    cin>>n>>sum;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<subasum(a,sum)<<endl;

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