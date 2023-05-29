template<typename E> class alist:public list<E>
{
private:
    int maxSize;
    int top;
    int sd;
    E*listArray;
    E* helpingArray;
public:
    alist()
    {
        maxSize=10;
        top=0;
        sd=1;
        listArray=new E[maxSize];
        helpingArray=new E[maxSize];
    }
    alist(E*lists,E direction,E k)
    {
        sd=direction;
        listArray=new E[maxSize];
        helpingArray=new E[maxSize];
        if(sd==1)
        {
            listArray=lists;
            helpingArray=lists;
            top=k;
        }
        else if(sd==-1)
        {
            top=maxSize;
            for(int i=maxSize,j=0;; i--,j++)
            {
                listArray[i]=lists[j];
                helpingArray[i]=lists[j];
                top--;
            }
        }
    }
    ~alist()
    {
        delete [] listArray;
        delete [] helpingArray;
    }
    void clear()
    {
        delete [] listArray;
        delete [] helpingArray;
        if(sd==1)
        {
            top=0;
        }
        else if(sd==-1)
        {
            top=maxSize;
        }
        listArray=new E[maxSize];
        helpingArray=new E[maxSize];
    }
    void push(const E&it)
    {
        if(sd==1)
        {
            if(top+1>=maxSize)
            {
                maxSize+=maxSize;
                delete [] listArray;
                listArray=new E[maxSize];
                listArray=helpingArray;
                delete [] helpingArray;
                helpingArray=new E[maxSize];
                helpingArray=listArray;
            }
            listArray[top] = it;
            helpingArray[top]=it;
            top++;
        }
        else if(sd==-1)
        {
            listArray[top]=it;
            helpingArray[top]=it;
            top--;
        }
    }
    E pop()
    {
        if(top==0)
        {
            std::cout<<"The stack is empty"<<std::endl;
            return -1;
        }
        else
        {
        if(sd==1)
        {
            return listArray[--top];
        }
        else if(sd==-1)
        {
            return listArray[++top];
        }
        }
    }
    E length()
    {
        if(sd==1)
        {
            return top;
        }
        else if(sd==-1)
        {
            return maxSize-top;
        }
    }
    const E& topValue()
    {
         if(top==0)
        {
            std::cout<<"The stack is empty"<<std::endl;
            return -1;
        }
        else
        {
        if(sd==1)
        {
            return listArray[top-1];
        }
        else if(sd==-1)
        {
            return listArray[top+1];
        }
        }
    }
    void setDirection(int var)
    {
        sd=var;
        if(sd==-1)
        {
            top=maxSize;
        }
        else if(sd==1)
        {
            top=0;
        }
    }
};
