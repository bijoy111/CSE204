#include<bits/stdc++.h>
using namespace std;
int n;//number of city
long long a[11][11];//for taking the input cost
long long dp[11][1<<10];//for memorization
long long funtion(int i,int x)//recursive function
{
    int t=(1<<(i-1));
    if((x^t) == 0)//checking base case
    {
        long long tmp1=0;
        for(int j=1; j<=n; j++)
        {
            tmp1+=a[i][j];
        }
        if(dp[i][x]>tmp1)
        {
            dp[i][x]=tmp1;
        }
        return tmp1;
    }
    long long tmp=0;
    for(int j=1; j<=n; j++)
    {
        t=(1<<(j-1));
        if((x&t)==0 || (i==j))//calculate the cost to visit the i city
        {
            tmp+=a[i][j];
        }
    }
    long long ans1 = LLONG_MAX;
    for (int j = 1; j <= n; j++)
    {
        int t = (1 << (j - 1));
        if ((x & t) && (i != j))//visited the non-visited city
        {
            int ti = (1 << (i - 1));
            int tii = x ^ ti;
            long long ans2;
            if(dp[j][tii]!=LLONG_MAX)
            {
                //cout<<"i"<<" "<<j<<" "<<"x"<<" "<<tii<<endl;
                ans2=dp[j][tii];
            }
            else
            {
                ans2 = funtion(j, tii);
                if (dp[i][x] > ans2)
                {
                    dp[i][x] = ans2;
                }
            }
            if (ans1 > tmp + ans2)
            {
                ans1 = tmp + ans2;
            }
        }
    }
    return ans1;
}
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>a[i][j];
        }
    }
    if(n==1)
    {
        cout<<a[n][n]<<endl;
        return 0;
    }
    long long ans=LLONG_MAX;
    int x=(1<<n)-1;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=x; j++)
        {
            dp[i][j]=LLONG_MAX;
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int t=1<<(j-1);
            if((x&t) && (i!=j))
            {
                long long ans2;
                int tii=x^(1<<(i-1));
                if(dp[j][tii] != LLONG_MAX)
                {
                    //cout<<"i"<<" "<<j<<" "<<"x"<<" "<<tii<<endl;
                    ans2=dp[j][tii];
                }
                else
                {
                    ans2 = funtion(j,tii);
                    if (dp[i][x] > ans2)
                    {
                        dp[i][x] = ans2;
                    }
                }
                if(ans>a[i][i]+ans2)
                {
                    ans=a[i][i]+ans2;
                }
            }
        }
    }
    cout<<ans<<endl;
    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=x;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return 0;
}


