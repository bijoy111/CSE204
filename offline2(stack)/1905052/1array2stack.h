template <typename E> class oneArrtwostack:public list<E>
{
private:
    int maxSize=1000;
    int top1;
    int top2;
    int sd;
    E*listArray=new E[maxSize];
public:
    oneArrtwostack(int val)
    {
        sd=val;
        if(sd==1)
            top1=0;
        else if(sd==-1)
            top2=maxSize;
    }
    ~oneArrtwostack()
    {
        delete [] listArray;
    }
    void clear()
    {
        delete [] listArray;
        top1=0;
        top2=maxSize;
        listArray=new E[maxSize];
    }
    void push(const E&it)
    {
        if(top2-top1==1)
        {
            std::cout<<"Stack is full"<<std::endl;
            return;
        }
        if(sd==1)
        {
            listArray[top1] = it;
            top1++;
        }
        else if(sd==-1)
        {
            listArray[top2]=it;
            top2--;
        }
    }
    E pop()
    {
        if(sd==1)
        {
            return listArray[--top1];
        }
        else if(sd==-1)
        {
            return listArray[++top2];
        }
    }
    E length()
    {
        if(sd==1)
        {
            return top1;
        }
        else if(sd==-1)
        {
            return maxSize-top2;
        }
    }
    const E& topValue()
    {
        if(sd==1)
        {
            return listArray[top1-1];
        }
        else if(sd==-1)
        {
            return listArray[top2+1];
        }
    }
    void setDirection(int var)
    {
        return;
    }
};
