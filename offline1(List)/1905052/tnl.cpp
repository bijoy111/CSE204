#include<iostream>
#include "ADT.h"
#include "Arr.h"
#include "LL.h"
using namespace std;
void print( LList<int> &ob) // Print list contents
{
    int len=ob.currPos();
    ob.moveToStart();
    int k;
    k=ob.length();
    int *l=new int[k+1];
    for(int i=0; i<k; i++)
    {
        l[i]=ob.getValue();
        ob.next();
    }
    for(int i=0,j=0; j<k; i++)
    {
        if(l[j]==i)
        {
            cout<<l[j];
            if(j<k-1)
                cout<<",";
            j++;
        }
        else
        {
            cout<<",";
        }
    }
    cout<<endl;
}
void print( AList<int> &ob) // Print list contents
{
   int len=ob.currPos();
    ob.moveToStart();
    int k;
    k=ob.length();
    int *l=new int[k+1];
    for(int i=0; i<k; i++)
    {
        l[i]=ob.getValue();
        ob.next();
    }
    for(int i=0,j=0; j<k; i++)
    {
        if(l[j]==i)
        {
            cout<<l[j];
            if(j<k-1)
                cout<<",";
            j++;
        }
        else
        {
            cout<<",";
        }
    }
    cout<<endl;
}
int main()
{
    int k;
    cin>>k;
    int *l=new int[k+1];
    for(int i=0; i<k; i++)
        l[i]=i;
    AList<int>rs(k,100,l);
    //LList<int>rs(k,l);
    int L;
    cin>>L;
    int *m=new int[L+1];
    for(int i=0; i<L; i++)
        cin>>m[i];
    AList <int> bs(L,100,m);
    //LList <int> bs(L,m);
    int M;
    cin>>M;
    int *n=new int[M+1];
    for(int i=0; i<M; i++)
        cin>>n[i];
    AList <int> ts(M,100,n);
    //LList <int> ts(M,n);
    int T;
    cin>>T;
    if(T==1)
    {
        print(rs);
        print(bs);
        print(ts);
    }
    return 0;
}

