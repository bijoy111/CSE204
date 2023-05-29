#include<iostream>
#include "ADT.h"
#include "LL.h"
#include "Arr.h"
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
    if(k==0)
    {
        std::cout<<"<>"<<std::endl;
    }
    else
    {
        cout<<"<"<<" ";
        for(int i=0; i<k; i++)
        {
            if(i==len)
            {
                cout<<"|"<<" ";
            }
            cout<<l[i]<<" ";
        }
        cout<<">"<<std::endl;
        ob.moveToPos(len);
    }
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
    if(k==0)
    {
        std::cout<<"<>"<<std::endl;
    }
    else
    {
        cout<<"<"<<" ";
        for(int i=0; i<k; i++)
        {
            if(i==len)
            {
                cout<<"|"<<" ";
            }
            cout<<l[i]<<" ";
        }
        cout<<">"<<std::endl;
        ob.moveToPos(len);
    }
}
int main()
{
    //there is implementation for both array based and link list based. i have to uncomment the corresponding section which i want to use
    //main function for array based implementation
    /*int k,x;
    cin>>k>>x;
    int *l=new int[k+1];
    for(int i=0; i<k; i++)
        cin>>l[i];
    AList<int> ob(k, x, l);
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
            ob.insert(p);
            print(ob);
            cout<<-1<<endl;
        }
        else if(q==3)
        {
            ob.append(p);
            print(ob);
            cout<<-1<<endl;
        }
        else if(q==4)
        {
            int r=ob.remove();
            print(ob);
            cout<<r<<endl;
        }
        else if(q==5)
        {
            ob.moveToStart();
            print(ob);
            cout<<-1<<endl;
        }
        else if(q==6)
        {
            ob.moveToEnd();
            print(ob);
            cout<<-1<<endl;
        }
        else if(q==7)
        {
            ob.prev();
            print(ob);
            cout<<-1<<endl;
        }
        else if(q==8)
        {
            ob.next();
            print(ob);
            cout<<-1<<endl;
        }
        else if(q==9)
        {
            int r=ob.length();
            print(ob);
            cout<<r<<endl;
        }
        else if(q==10)
        {
            int r=ob.currPos();
            print(ob);
            cout<<r<<endl;
        }
        else if(q==11)
        {
            ob.moveToPos(p);
            print(ob);
            cout<<-1<<endl;
        }
        else if(q==12)
        {
            int r=ob.getValue();
            print(ob);
            cout<<r<<endl;
        }
        else if(q==13)
        {
            int r=ob.searchItem(p);
            print(ob);
            cout<<r<<endl;
        }
        cin>>q>>p;
    }*/

    //main function for link list based implementation
    int k;
    cin>>k;
    int *l=new int[k+1];
    for(int i=0; i<k; i++)
        cin>>l[i];
    LList<int> ob(k,l);
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
            ob.insert(p);
            print(ob);
            cout<<-1<<endl;
        }
        else if(q==3)
        {
            ob.append(p);
            print(ob);
            cout<<-1<<endl;
        }
        else if(q==4)
        {
            int r=ob.remove();
            print(ob);
            cout<<r<<endl;
        }
        else if(q==5)
        {
            ob.moveToStart();
            print(ob);
            cout<<-1<<endl;
        }
        else if(q==6)
        {
            ob.moveToEnd();
            print(ob);
            cout<<-1<<endl;
        }
        else if(q==7)
        {
            ob.prev();
            print(ob);
            cout<<-1<<endl;
        }
        else if(q==8)
        {
            ob.next();
            print(ob);
            cout<<-1<<endl;
        }
        else if(q==9)
        {
            int r=ob.length();
            print(ob);
            cout<<r<<endl;
        }
        else if(q==10)
        {
            int r=ob.currPos();
            print(ob);
            cout<<r<<endl;
        }
        else if(q==11)
        {
            ob.moveToPos(p);
            print(ob);
            cout<<-1<<endl;
        }
        else if(q==12)
        {
            int r=ob.getValue();
            print(ob);
            cout<<r<<endl;
        }
        else if(q==13)
        {
            int r=ob.searchItem(p);
            print(ob);
            cout<<r<<endl;
        }
        cin>>q>>p;
    }
    return 0;
}

