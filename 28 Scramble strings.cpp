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
vector<int> a[200005];
vector<bool> vis(200005,0);
vector<int> dis(200005,0);
vector<int> in(200005,0);
vector<int> low(200005,0);
int timer = 1;

map<string,bool> mp;

bool scramblestrings(string s1,string s2)
{
    string key = s1+" "+s2;

    if(mp.find(key) != mp.end())
    return mp[key];

    if(s1.length()!=s2.length())
        return mp[key] = false;

    int n = s1.length();

    if(n == 0)
        return mp[key] = true;
    
    if(s1 == s2)
        return mp[key] = true;
    
    string s1_copy = s1;
    string s2_copy = s2;

    sort(s1_copy.begin(),s1_copy.end());
    sort(s2_copy.begin(),s2_copy.end());

    if(s1_copy!=s2_copy)
        return mp[key] = false;

    for(int i=1;i<n;i++)
    {
        if(scramblestrings(s1.substr(0,i),s2.substr(0,i)) && scramblestrings(s1.substr(i,n-i),s2.substr(i,n-i)))
            return true;

        if(scramblestrings(s1.substr(0,i),s2.substr(n-i,i)) && scramblestrings(s1.substr(i,n-i),s2.substr(0,n-i)))
            return true;
    }

    return mp[key] = false;
}
 
void solve ()
{
   string s1,s2;
   cin>>s1;
   cin>>s2;

   cout<<scramblestrings(s1,s2)<<endl;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
  
        solve();
    
    return 0;
}