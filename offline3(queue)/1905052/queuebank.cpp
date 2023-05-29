#include<iostream>
#include "queueadt.h"
#include "queuearr.h"
#include "queueLL.h"
using namespace std;
int main()
{
    arrayList <int> ob1;//Booth 1
    arrayList <int> ob2;//Booth 2
    //linkList <int> ob1;//Booth 1
    //linkList <int> ob2;//Booth 2
    //cout<<"HI 1"<<endl;
    int n;//number of customers
    cin>>n;
    int a[n+1],b[n+1];//a take the entering time and b take the service time
    int service_time[100001];//key of this array is the entering time and value is the service time
    for(int i=0; i<n; i++)
    {
        int x,y;//x is entering time and y is the service time
        cin>>x>>y;
        a[i]=x;
        b[i]=y;
        service_time[x]=y;
    }
    int i=0;//i is used for the traverse of customers
    int t1=0,t2=0;//t1 take the time of booth 1 and t2 take the time for booth 2
    for(int j=0; ; j++) //j is the time that never wait for anyone
    {
        if(i==n&&ob1.length()==0&&ob2.length()==0)
        {
            break;
        }
        if(ob2.length()>0)
        {
            int r=ob2.frontvalue();
            if(r>t2)
                t2=r;
            if(t2+service_time[r]==j)
            {
                ob2.dequeue();
                t2=j;
                //cout<<"ob2"<<" "<<t2<<endl;
            }
        }
        if(ob1.length()>0)
        {
            int r=ob1.frontvalue();
            if(r>t1)//if the teller is free before the front customer enter the booth
                t1=r;
            if(t1+service_time[r]==j)
            {
                ob1.dequeue();
                t1=j;
                //cout<<"ob1"<<" "<<t1<<endl;
            }
        }
        if(a[i]==j&&i<n)
        {
            if(ob2.length()<=ob1.length())
            {
                ob2.enqueue(j);
            }
            else
            {
                ob1.enqueue(j);
            }
            i++;
        }
        while(ob2.length()>ob1.length())
        {
            int r=ob2.leavequeue();
            ob1.enqueue(r);
        }
        while(ob1.length()>ob2.length())
        {
            int r=ob1.leavequeue();
            ob2.enqueue(r);
        }
    }
    cout<<"Booth 1 finishes service at t="<<t1<<endl;
    cout<<"Booth 2 finishes service at t="<<t2<<endl;
    return 0;
}
