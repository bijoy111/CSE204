#include<iostream>
#include "queueadt.h"
#include "queuearr.h"
#include "queueLL.h"
using namespace std;
void print(arrayList<int> & ob)
{
    int l=ob.length();
    if(l==0)
    {
        cout<<"<"<<">"<<endl;
    }
    else
    {
    cout<<"< ";
    int *lists=new int[l];
    for(int i=0;i<l;i++)
    {
        lists[i]=ob.dequeue();
        cout<<lists[i]<<" ";
    }
    cout<<">";
    cout<<endl;
    for(int i=0;i<l;i++)
    {
        ob.enqueue(lists[i]);
    }
    }
}
void print(linkList<int> & ob)
{
    int l=ob.length();
    if(l==0)
    {
        cout<<"<"<<">"<<endl;
    }
    else
    {
    cout<<"< ";
    int *lists=new int[l];
    for(int i=0;i<l;i++)
    {
        lists[i]=ob.dequeue();
        cout<<lists[i]<<" ";
    }
    cout<<">";
    cout<<endl;
    for(int i=0;i<l;i++)
    {
        ob.enqueue(lists[i]);
    }
    }
}
void print(arrayList<char> & ob)
{
    int l=ob.length();
    if(l==0)
    {
        cout<<"<"<<">"<<endl;
    }
    else
    {
    cout<<"< ";
    char *lists=new char[l];
    for(int i=0;i<l;i++)
    {
        lists[i]=ob.dequeue();
        cout<<lists[i]<<" ";
    }
    cout<<">";
    cout<<endl;
    for(int i=0;i<l;i++)
    {
        ob.enqueue(lists[i]);
    }
    }
}
void print(linkList<char> & ob)
{
    int l=ob.length();
    if(l==0)
    {
        cout<<"<"<<">"<<endl;
    }
    else
    {
    cout<<"< ";
    char *lists=new char[l];
    for(int i=0;i<l;i++)
    {
        lists[i]=ob.dequeue();
        cout<<lists[i]<<" ";
    }
    cout<<">";
    cout<<endl;
    for(int i=0;i<l;i++)
    {
        ob.enqueue(lists[i]);
    }
    }
}
int main()
{
    /*int q;
    //int p;
    char p;
    cin>>q>>p;
    //arrayList <int> ob(10);
    arrayList <char> ob(10);
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
            ob.enqueue(p);
            print(ob);
            cout<<-1<<endl;
        }
        else if(q==3)
        {
            //int r=ob.dequeue();
            char r=ob.dequeue();
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
            //int r=ob.frontvalue();
            char r=ob.frontvalue();
            print(ob);
            cout<<r<<endl;
        }
        else if(q==6)
        {
            //int r=ob.rearvalue();
            char r=ob.rearvalue();
            print(ob);
            cout<<r<<endl;
        }
        else if(q==7)
        {
            //int r=ob.leavequeue();
            char r=ob.leavequeue();
            print(ob);
            cout<<r<<endl;
        }
        cin>>q>>p;
    }*/
    int q;
    int p;
    //char p;
    cin>>q>>p;
    linkList <int> ob;
    //linkList<char>ob;
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
            ob.enqueue(p);
            print(ob);
            cout<<-1<<endl;
        }
        else if(q==3)
        {
            int r=ob.dequeue();
            //char r=ob.dequeue();
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
            int r=ob.frontvalue();
            //char r=ob.frontvalue();
            print(ob);
            cout<<r<<endl;
        }
        else if(q==6)
        {
            int r=ob.rearvalue();
            //char r=ob.rearvalue();
            print(ob);
            cout<<r<<endl;
        }
        else if(q==7)
        {
            int r=ob.leavequeue();
            //char r=ob.leavequeue();
            print(ob);
            cout<<r<<endl;
        }
        cin>>q>>p;
    }
    return 0;
}
