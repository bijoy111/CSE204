template<typename E> class arrayList:public list<E>
{
private:
    int maxSize;
    int listSize; // Number of list items now
    E *listArray;
    E *helpingArray;
public:
    arrayList(int s=0)
    {
        if(s==0)
            maxSize=10;
        else
        maxSize=s;
        listArray=new E[maxSize];
        helpingArray=new E[maxSize];
        listSize=0;
    }
    arrayList(E* lists)
    {
        listArray=lists;
        helpingArray=lists;
        listSize=0;
        maxSize=10;
    }
    arrayList(int k,int m,E* lists)
    {
        listSize=k;
        maxSize=m;
        listArray=lists;
        helpingArray=lists;
    }
    ~arrayList()
    {
        delete [] listArray; // Remove the array
        delete [] helpingArray;
    }
    void clear()
    {
        delete [] listArray; // Remove the array
        delete [] helpingArray;
        listSize =0; // Reset the size
        listArray = new E[maxSize]; // Recreate array
        helpingArray=new E[maxSize];
    }
    void enqueue(E it)
    {
        if(listSize+1>=maxSize)
        {
            maxSize+=maxSize;
            delete [] listArray;
            listArray=new E[maxSize];
            listArray=helpingArray;
            delete [] helpingArray;
            helpingArray=new E[maxSize];
            helpingArray=listArray;
        }
        listArray[listSize]=it;
        helpingArray[listSize]=it;
        listSize++;
    }
    E dequeue()
    {
        if(listSize==0)
        {
            std::cout<<"Queue is empty"<<std::endl;
            return -1;
        }
        E it = listArray[0]; // Copy the element
        for(int i=0; i<listSize-1; i++) // Shift them down
            listArray[i] = listArray[i+1];
        listSize--; // Decrement size
        return it;
    }
    int length()
    {
        return listSize;
    }
    E frontvalue()
    {
        if(listSize==0)
        {
            std::cout<<"Queue is empty"<<std::endl;
            return -1;
        }
        return listArray[0];
    }
    E rearvalue()
    {
        if(listSize==0)
        {
            std::cout<<"Queue is empty"<<std::endl;
            return -1;
        }
        return listArray[listSize-1];
    }
    E leavequeue()
    {
         if(listSize==0)
        {
            std::cout<<"Queue is empty"<<std::endl;
            return -1;
        }
        E leaveval;
        leaveval=listArray[listSize-1];
        listSize--;
        return leaveval;
    }
};
