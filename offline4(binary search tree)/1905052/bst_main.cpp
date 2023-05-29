#include<iostream>
#include<fstream>
#include<string>
#include "bst_bstadt.h"
#include "bst_binnode.h"
#include "bst_bstnode.h"
#include "bst_bstimplement.h"
using namespace std;
int main()
{
    fstream MyReadFile("input.txt");
    string x;
    string y;
    int i=0;
    BST<int> ob;
    while(MyReadFile>>x)
    {
        i++;
        if(i%2==1)
        {
            y=x;
        }
        if(i%2==0)
        {
            if(y=="F")
            {
                int num=stoi(x);
                if(ob.find(num)==NULL)
                {
                    cout<<"False"<<endl;
                }
                else
                {
                    cout<<"True"<<endl;
                }
            }
            else if(y=="I")
            {
                int num=stoi(x);
                ob.insert(num);
                ob.print();
                cout<<endl;
            }
            else if(y=="D")
            {
                int num=stoi(x);
                if(ob.remove(num)==NULL)
                {
                    cout<<"Invalid Operation"<<endl;
                }
                else
                {
                    ob.print();
                    cout<<endl;
                }
            }
            else if(y=="T")
            {
                if(x=="Pre")
                {
                    preorder(ob.getroot());
                    cout<<endl;
                }
                else if(x=="Post")
                {
                    postorder(ob.getroot());
                    cout<<endl;
                }
                else if(x=="In")
                {
                    inorder(ob.getroot());
                    cout<<endl;
                }
            }
        }
    }
    return 0;
}
