/* Author Kartik Shukla */
#include<stdio.h>
#include<math.h>


int len(char a[])
{
    int l = 0;

    for(int i=0;a[i];i++)
    l++;

    return l;
}

int largest(int x,int y,int z)
{
    if(x>y && x>z)
    return x;
    if(y>x && y>z)
    return y;
    return z;
}

int max(int x,int y)
{
    if(x>y)
    return x;
    else
    return y;
}
void solve ()
{
   char a[450],b[450],c[450];
        scanf("%s%s%s",a,b,c);
    int l = len(a);

    int dp[l+1][l+1][l+1];

    for(int i=0;i<=l;i++)
    {
        for(int j=0;j<=l;j++)
        {
            for(int k=0;k<=l;k++)
            {
                if(i == 0 || j == 0 || k == 0)
                dp[i][j][k] = 0;

                else if(a[i-1] == b [j-1] && a[i-1] == c[k-1])
                dp[i][j][k] = dp[i-1][j-1][k-1] + 1;

                else
                dp[i][j][k] = max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);

                //printf("%d ",dp[i][j][k]);
            }
            //printf("\n");

        }
    }

    printf("%d\n",3*(l-dp[l][l][l]));
}
 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        solve();
    }
    return 0;
}