/* Author Kartik Shukla */
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
typedef long long int ll;
#define mod 998244353
#define MOD 1000000007
#define PI 3.14159265358
vector<int> a[200005];
vector<bool> vis(200005, 0);
vector<int> dis(200005, 0);

bool dpsum(vector<int> a)
{
    int n = a.size();

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    if (sum % 2)
        return false;
    else
        sum /= 2;

    bool dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < a[i - 1])
                dp[i][j] = dp[i - 1][j];
            if (j >= a[i - 1])
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
        }
    }

    return dp[n][sum];
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);

    int s = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    s /= 2;

    cout << dpsum(a) << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}