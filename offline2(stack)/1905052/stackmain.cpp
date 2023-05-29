#include<iostream>
#include "stackAdt.h"
#include "stackArr.h"
#include "stackLL.h"
using namespace std;
void print(alist<int> &ob)
{
    int len=ob.length();
    if(len==0)
    {
        cout<<"< >"<<endl;
        return;
    }
    int* l=new int[len];
    for(int i=0; i<len; i++)
    {
        l[i]=ob.pop();
    }
    int* tmp=new int[len];
    for(int i=len-1,j=0; i>=0; i--,j++)
    {
        tmp[j]=l[i];
    }
    cout<<"<"<<" ";
    for(int i=0; i<len; i++)
    {
        ob.push(tmp[i]);
        cout<<tmp[i]<<" ";
    }
    cout<<">";
    cout<<endl;
}
void print(llist<int> &ob)
{
    int len=ob.length();
    if(len==0)
    {
        cout<<"< >"<<endl;
        return;
    }
    int* l=new int[len];
    for(int i=0; i<len; i++)
    {
        l[i]=ob.pop();
    }
    int* tmp=new int[len];
    for(int i=len-1,j=0; i>=0; i--,j++)
    {
        tmp[j]=l[i];
    }
    cout<<"<"<<" ";
    for(int i=0; i<len; i++)
    {
        ob.push(tmp[i]);
        cout<<tmp[i]<<" ";
    }
    cout<<">";
    cout<<endl;
}
int main()
{
    int k;
    cin>>k;
    int *l=new int[k+1];
    for(int i=0;i<k;i++)
    {
        cin>>l[i];
    }
    int pi=1;
    alist <int> ob(l,pi,k);
    print(ob);
    int q,p;
    cin>>q>>p;
    while(q!=0)
    {
        if(q==1)
        {
            ob.clear();
            print(ob);
            cout<<-1<<endl;
        }
        else if(q==2)
        {
            ob.push(p);
            print(ob);
            cout<<-1<<endl;
        }
        else if(q==3)
        {
            int r=ob.pop();
            print(ob);
            cout<<r<<endl;
        }
        else if(q==4)
        {
            int r=ob.length();
            print(ob);
            cout<<r<<endl;
        }
        else if(q==5)
        {
            int r=ob.topValue();
            print(ob);
            cout<<r<<endl;
        }
        else if(q==6)
        {
            ob.setDirection(p);
            print(ob);
            cout<<-1<<endl;
        }
        cin>>q>>p;
    }
    /*int k;
    cin>>k;
    int *l=new int[k+1];
    for(int i=0; i<k; i++)
    {
        cin>>l[i];
    }
    //llist <int> ob;
    llist<int>ob(l,k);
    print(ob);
    int q,p;
    cin>>q>>p;
    while(q!=0)
    {
        if(q==1)
        {
            ob.clear();
            print(ob);
            cout<<-1<<endl;
        }
        else if(q==2)
        {
            ob.push(p);
            print(ob);
            cout<<-1<<endl;
        }
        else if(q==3)
        {
            int r=ob.pop();
            print(ob);
            cout<<r<<endl;
        }
        else if(q==4)
        {
            int r=ob.length();
            print(ob);
            cout<<r<<endl;
        }
        else if(q==5)
        {
            int r=ob.topValue();
            print(ob);
            cout<<r<<endl;
        }
        else if(q==6)
        {
            ob.setDirection(p);
            print(ob);
            cout<<-1<<endl;
        }
        cin>>q>>p;
    }*/
    return 0;
}
