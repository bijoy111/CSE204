#include<bits/stdc++.h>
#include "stackAdt.h"
#include "stackArr.h"
#include "stackLL.h"
#include "1array2stack.h"
using namespace std;
int main()
{
    //array based implementation
    /*int n,x; //n is the number of friends and x is the number of courses in the meal
    cin>>n>>x;
    int *time=new int[x+1];//it will take the time to wash the corresponding dish for a course
    int *eat=new int[n+1];//it will take the information of each invitees to finish the full meal
    int *cmealtime=new int[n+1];
    int *ti=new int[10000+1];//to take the corresponding course on that time
    for(int i=1; i<=n; i++)
    {
        eat[i]=0;
    }
    for(int i=1; i<=x; i++)
    {
        cin>>time[i];
    }
    int k,t,s;
    cin>>k>>t>>s;//here is k is the index of friend,t is the time to keep the dish in dirty stack,s is the index of the course
    llist <int> ob1;//dirty stack
    llist <int> ob2;//clean stack
    int t2=0;//t2 will keep the time of washing
    int j=0;
    while(k!=0)
    {
        while(t>t2&&ob1.length()>0)
        {
            int r=ob1.pop();
            if(r==0)
            {
                t2=time[ti[r]]-1;
                ob2.push(t2);
            }
            else
            {
                int u=time[ti[r]];
                if(r>=t2)
                {
                    if(r==t2)
                        t2=r+u;
                    else
                        t2=r+u-1;
                }
                else
                {
                    t2=t2+u;
                }
                ob2.push(t2);
            }
        }
        ob1.push(t);
        ti[t]=s;
        if(s==x)
        {
            eat[k]=t;//k index invitee finish the full meal
            cmealtime[j]=t;
            j++;
        }
        cin>>k>>t>>s;
    }
    while(ob1.length()>0)
    {
        int r=ob1.pop();
        int u=time[ti[r]];
        if(r>=t2)
        {
            if(r==t2)
                t2=r+u;
            else
                t2=r+u-1;
        }
        else
        {
            t2=t2+u;
        }
        ob2.push(t2);
    }
    cout<<t2<<endl;
    int len1=ob2.length();//how many dish is exist in the clean stack
    int *tmp1=new int[len1];
    for(int i=0; i<len1; i++)
    {
        tmp1[i]=ob2.pop();
    }
    sort(tmp1,tmp1+len1);
    for(int i=0; i<len1; i++)
    {
        if(i!=len1-1)
            cout<<tmp1[i]<<",";
        else
            cout<<tmp1[i];
    }
    cout<<endl;
    int var=0;
    for(int i=1; i<=n; i++)
    {
        if(eat[i]==0)
        {
            cout<<"N"<<endl;
            var=1;
            break;
        }
    }
    if(var==0)
    {
        cout<<"Y"<<endl;
    }
    sort(cmealtime,cmealtime+j);
    int coma=1;
    for(int i=j-1; i>=0; i--)
    {
        for(int m=1; m<=n; m++)
        {
            if(eat[m]!=0&&cmealtime[i]==eat[m])
            {
                if(coma==0)
                {
                    cout<<",";
                }
                cout<<m;
                coma=0;
                break;
            }
        }
    }*/
    //link list based implementation
    /*int n,x; //n is the number of friends and x is the number of courses in the meal
    cin>>n>>x;
    int *time=new int[x+1];//it will take the time to wash the corresponding dish for a course
    int *eat=new int[n+1];//it will take the information of each invitees to finish the full meal
    int *cmealtime=new int[n+1];
    int *ti=new int[10000+1];//to take the corresponding course on that time
    for(int i=1; i<=n; i++)
    {
        eat[i]=0;
    }
    for(int i=1; i<=x; i++)
    {
        cin>>time[i];
    }
    int k,t,s;
    cin>>k>>t>>s;//here is k is the index of friend,t is the time to keep the dish in dirty stack,s is the index of the course
    alist <int> ob1;//dirty stack
    alist <int> ob2;//clean stack
    int t2=0;//t2 will keep the time of washing
    int j=0;
    while(k!=0)
    {
        while(t>t2&&ob1.length()>0)
        {
            int r=ob1.pop();
            if(r==0)
            {
                t2=time[ti[r]]-1;
                ob2.push(t2);
            }
            else
            {
                int u=time[ti[r]];
                if(r>=t2)
                {
                    if(r==t2)
                        t2=r+u;
                    else
                        t2=r+u-1;
                }
                else
                {
                    t2=t2+u;
                }
                ob2.push(t2);
            }
        }
        ob1.push(t);
        ti[t]=s;
        if(s==x)
        {
            eat[k]=t;//k index invitee finish the full meal
            cmealtime[j]=t;
            j++;
        }
        cin>>k>>t>>s;
    }
    while(ob1.length()>0)
    {
        int r=ob1.pop();
        int u=time[ti[r]];
        if(r>=t2)
        {
            if(r==t2)
                t2=r+u;
            else
                t2=r+u-1;
        }
        else
        {
            t2=t2+u;
        }
        ob2.push(t2);
    }
    cout<<t2<<endl;
    int len1=ob2.length();//how many dish is exist in the clean stack
    int *tmp1=new int[len1];
    for(int i=0; i<len1; i++)
    {
        tmp1[i]=ob2.pop();
    }
    sort(tmp1,tmp1+len1);
    for(int i=0; i<len1; i++)
    {
        if(i!=len1-1)
            cout<<tmp1[i]<<",";
        else
            cout<<tmp1[i];
    }
    cout<<endl;
    int var=0;
    for(int i=1; i<=n; i++)
    {
        if(eat[i]==0)
        {
            cout<<"N"<<endl;
            var=1;
            break;
        }
    }
    if(var==0)
    {
        cout<<"Y"<<endl;
    }
    sort(cmealtime,cmealtime+j);
    int coma=1;
    for(int i=j-1; i>=0; i--)
    {
        for(int m=1; m<=n; m++)
        {
            if(eat[m]!=0&&cmealtime[i]==eat[m])
            {
                if(coma==0)
                    cout<<",";
                cout<<m;
                coma=0;
                break;
            }
        }
    }*/
    //1 array 2 stack based implementation
    int n,x; //n is the number of friends and x is the number of courses in the meal
    cin>>n>>x;
    int *time=new int[x+1];//it will take the time to wash the corresponding dish for a course
    int *eat=new int[n+1];//it will take the information of each invitees to finish the full meal
    int *cmealtime=new int[n+1];
    int *ti=new int[1000+1];//to take the corresponding course on that time
    for(int i=1; i<=n; i++)
    {
        eat[i]=0;
    }
    for(int i=1; i<=x; i++)
    {
        cin>>time[i];
    }
    int k,t,s;
    cin>>k>>t>>s;//here is k is the index of friend,t is the time to keep the dish in dirty stack,s is the index of the course
    oneArrtwostack <int> ob1(1);//dirty stack
    oneArrtwostack <int> ob2(-1);//clean stack
    int t2=0;//t2 will keep the time of washing
    int j=0;
    while(k!=0)
    {
        while(t>t2&&ob1.length()>0)
        {
            int r=ob1.pop();
            if(r==0)
            {
                t2=time[ti[r]]-1;
                ob2.push(t2);
            }
            else
            {
                int u=time[ti[r]];
                if(r>=t2)
                {
                    if(r==t2)
                        t2=r+u;
                    else
                        t2=r+u-1;
                }
                else
                {
                    t2=t2+u;
                }
                ob2.push(t2);
            }
        }
        ob1.push(t);
        ti[t]=s;
        if(s==x)
        {
            eat[k]=t;//k index invitee finish the full meal
            cmealtime[j]=t;
            j++;
        }
        cin>>k>>t>>s;
    }
    while(ob1.length()>0)
    {
        int r=ob1.pop();
        int u=time[ti[r]];
        if(r>=t2)
        {
            if(r==t2)
                t2=r+u;
            else
                t2=r+u-1;
        }
        else
        {
            t2=t2+u;
        }
        ob2.push(t2);
    }
    cout<<t2<<endl;
    int len1=ob2.length();//how many dish is exist in the clean stack
    int *tmp1=new int[len1];
    for(int i=0; i<len1; i++)
    {
        tmp1[i]=ob2.pop();
    }
    sort(tmp1,tmp1+len1);
    for(int i=0; i<len1; i++)
    {
        if(i!=len1-1)
            cout<<tmp1[i]<<",";
        else
            cout<<tmp1[i];
    }
    cout<<endl;
    int var=0;
    for(int i=1; i<=n; i++)
    {
        if(eat[i]==0)
        {
            cout<<"N"<<endl;
            var=1;
            break;
        }
    }
    if(var==0)
    {
        cout<<"Y"<<endl;
    }
    sort(cmealtime,cmealtime+j);
    int coma=1;
    for(int i=j-1; i>=0; i--)
    {
        for(int m=1; m<=n; m++)
        {
            if(eat[m]!=0&&cmealtime[i]==eat[m])
            {
                if(coma==0)
                    cout<<",";
                cout<<m;
                coma=0;
                break;
            }
        }
    }
    return 0;
}
