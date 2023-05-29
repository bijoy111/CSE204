#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;// n is number of plants and k is number of friends
    cin>>n>>k;
    int *a=new int[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    long long int ans=0;
    int cycle=0;
    int f=0;
    for(int j=n-1; j>=0; j--)
    {
        ans+=(cycle+1)*a[j];
        f++;
        if(f==k)
        {
            f=0;
            cycle++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
