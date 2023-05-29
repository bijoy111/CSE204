#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int l1=s1.length();
    int l2=s2.length();
    char* str1=new char[l1+1];
    char* str2=new char[l2+1];
    for(int i=1; i<=l1; i++)
    {
        str1[i]=s1[i-1];
    }
    for(int i=1; i<=l2; i++)
    {
        str2[i]=s2[i-1];
    }
    int dp[l1+1][l2+1];
    for(int i=0; i<=l1; i++)
    {
        dp[i][0]=0;
    }
    for(int i=0; i<=l2; i++)
    {
        dp[0][i]=0;
    }
    for(int i=1; i<=l1; i++)
    {
        for(int j=1; j<=l2; j++)
        {
            if(str1[i]==str2[j])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[l1][l2]<<endl;
    int l=dp[l1][l2];
    char* ans=new char[l+1];
    int i=l1,j=l2,k=l;
    while(i>0&&j>0&&k>0)
    {
        if(str1[i]==str2[j])
        {
            ans[k]=str1[i];
            i--,j--,k--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    for(int i=1; i<=l; i++)
    {
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}

