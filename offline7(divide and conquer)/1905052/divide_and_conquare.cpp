#include<bits/stdc++.h>
#include <chrono>//for calculate time
#include<fstream>//for writing in file
using namespace std;
using namespace std::chrono;

//insertion sort
void insertion_sort(int a[],int n)
{
    for(int i=0; i<n; i++)
    {
        int x=a[i];
        int j=i-1;
        while(j>=0 && a[j]>=x)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
    }
}

//merge sort
void do_merge(int a[],int l,int m,int r)
{
    int len1=m-l+1;
    int len2=r-m;
    int *left=new int[len1+1];
    int *right=new int[len2+1];
    int tmp1=l;
    for(int i=0; i<len1; i++)
    {
        left[i]=a[tmp1++];
    }
    for(int i=0; i<len2; i++)
    {
        right[i]=a[tmp1++];
    }
    int i=0,j=0,tmp2=l;
    while(i<len1&&j<len2)
    {
        if(left[i]<=right[j])
        {
            a[tmp2++]=left[i++];
        }
        else
        {
            a[tmp2++]=right[j++];
        }
    }
    while(i<len1)
    {
        a[tmp2++]=left[i++];
    }
    while(j<len2)
    {
        a[tmp2++]=right[j++];
    }
}
void merge_sort(int a[],int l,int r)
{
    if(l>=r)
    {
        return;
    }
    int mid=(l+r)/2;
    merge_sort(a,l,mid);
    merge_sort(a,mid+1,r);
    do_merge(a,l,mid,r);
}

//quick sort
int do_partition(int a[],int l,int r)
{
    int x=a[r];
    int i=l-1;
    for(int j=l; j<r; j++)
    {
        if(a[j]<=x)
        {
            i=i+1;
            int tmp=a[i];
            a[i]=a[j];
            a[j]=tmp;
        }
    }
    int tmp=a[i+1];
    a[i+1]=a[r];
    a[r]=tmp;
    return i+1;
}
void quick_sort(int a[],int l,int r)
{
    if(l>=r)
    {
        return;
    }
    int m=do_partition(a,l,r);
    quick_sort(a,l,m-1);
    quick_sort(a,m+1,r);
}

//randomized quick sort
int do_partition_random(int a[],int l,int r)
{
    int n=r-l+1;
    n=rand()%n;
    n=n+l;
    int tmp1=a[n];
    a[n]=a[r];
    a[r]=tmp1;
    int x=a[r];
    int i=l-1;
    for(int j=l; j<r; j++)
    {
        if(a[j]<=x)
        {
            i=i+1;
            int tmp=a[i];
            a[i]=a[j];
            a[j]=tmp;
        }
    }
    int tmp=a[i+1];
    a[i+1]=a[r];
    a[r]=tmp;
    return i+1;
}
void randomized_quick_sort(int a[],int l,int r)
{
    if(l>=r)
    {
        return;
    }
    int m=do_partition_random(a,l,r);
    randomized_quick_sort(a,l,m-1);
    randomized_quick_sort(a,m+1,r);
}

//main function
int main()
{
    ofstream file;
    file.open("out.csv");
    file<<","<<"Time required in ms"<<endl;
    file<<"n"<<","<<"Merge Sort"<<","<<"Quicksort"<<","<<"Randomized Quicksort"<<","<<"Insertion Sort"<<","<<"Quicksort with Sorted Input"<<","<<"Randomized Quicksort with Sorted Input"<<","<<"STL sort() function"<<endl;
    int arr[]= {5,10,100,1000,10000,100000};
    for(int i=0; i<=5; i++)
    {
        //t1 for merge sort
        //t2 for quick sort
        //t3 for randomized quick sort
        //t4 for insertion sort
        //t5 for quick sort working on sorting array
        //t6 for randomized quick sort working on sorting array
        //t7 for built in sorting
        double t1=0.0,t2=0.0,t3=0.0,t4=0.0,t5=0.0,t6=0.0,t7=0.0;
        int n=arr[i];
        int *a=new int[n+1];//store the original array
        int *b=new int[n+1];//use as a temporary array for sorting
        for(int t=1; t<=20; t++)
        {
            srand(t);
            for(int i=0; i<n; i++)
            {
                a[i]=rand();
            }

            for(int i=0; i<n; i++)
            {
                b[i]=a[i];
            }
            auto start = high_resolution_clock::now();
            merge_sort(b,0,n-1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            t1+=duration.count();

            for(int i=0; i<n; i++)
            {
                b[i]=a[i];
            }
            start = high_resolution_clock::now();
            quick_sort(b,0,n-1);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            t2+=duration.count();

            for(int i=0; i<n; i++)
            {
                b[i]=a[i];
            }
            start = high_resolution_clock::now();
            randomized_quick_sort(b,0,n-1);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            t3+=duration.count();

            for(int i=0; i<n; i++)
            {
                b[i]=a[i];
            }
            start = high_resolution_clock::now();
            insertion_sort(b,n);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            t4+=duration.count();

            start = high_resolution_clock::now();
            quick_sort(b,0,n-1);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            t5+=duration.count();

            start = high_resolution_clock::now();
            randomized_quick_sort(b,0,n-1);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            t6+=duration.count();

            for(int i=0; i<n; i++)
            {
                b[i]=a[i];
            }
            start = high_resolution_clock::now();
            sort(b,b+n);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            t7+=duration.count();
        }
        //cout<<"n"<<" "<<n<<endl;
        t1=t1/20.0;
        t2=t2/20.0;
        t3=t3/20.0;
        t4=t4/20.0;
        t5=t5/20.0;
        t6=t6/20.0;
        t7=t7/20.0;
        /*cout<<"merge sort"<<" "<<t1/1000.0<<endl;
        cout<<"quick sort"<<" "<<t2/1000.0<<endl;
        cout<<"randomized quick sort"<<" "<<t3/1000.0<<endl;
        cout<<"insertion sort"<<" "<<t4/1000.0<<endl;
        cout<<"sorting array in quick sort"<<" "<<t5/1000.0<<endl;
        cout<<"sorting array in randomized quick sort"<<" "<<t6/1000.0<<endl;
        cout<<"built in sort"<<" "<<t7/1000.0<<endl;*/
        file<<n<<","<<t1/1000.0<<","<<t2/1000.0<<","<<t3/1000.0<<","<<t4/1000.0<<","<<t5/1000.0<<","<<t6/1000.0<<","<<t7/1000.0<<endl;
        delete []a;
        delete []b;
    }
    file.close();
    return 0;
}
