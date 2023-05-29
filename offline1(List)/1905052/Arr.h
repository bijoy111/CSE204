template <typename E> class AList : public List<E>
{
private:
    int maxSize; // Maximum size of list
    int listSize; // Number of list items now
    int curr; // Position of current element
    E* listArray; // Array holding list elements
    E* helpingArray; //it will help in dynamic memory allocations
    int chunk; //take the value of x
public:
    AList()   // Constructor
    {
        maxSize = 10; //default size
        listSize = curr = 0;
        listArray = new E[maxSize];
        helpingArray = new E[maxSize];
    }
    AList(int k,int x,E* lists)   // Constructor
    {
        curr = 0;
        chunk=x;
        maxSize=x;
        listSize=k;
        listArray = new E[maxSize];
        helpingArray = new E[maxSize];
        listArray=lists;
        helpingArray=lists;
    }
    ~AList() // Destructor
    {
        delete [] listArray;
        delete [] helpingArray;
    }
    void clear()   // Reinitialize the list
    {
        delete [] listArray; // Remove the array
        delete [] helpingArray;
        listSize = curr = 0; // Reset the size
        listArray = new E[maxSize]; // Recreate array
        helpingArray=new E[maxSize];
    }
// Insert "it" at current position
    void insert(const E& it)
    {
        if(listSize+1==maxSize)
        {
            maxSize+=chunk;//increase the size by x as it will take x+1th element
            delete [] listArray;//remove the old array
            listArray=new E[maxSize];//reinitialize the the array
            listArray=helpingArray;//take the old value
            delete [] helpingArray;
            helpingArray=new E[maxSize];
            helpingArray=listArray;//now both listArray and helping array can hold another x elements
        }
        //Assert(listSize < maxSize, "List capacity exceeded");
        for(int i=listSize; i>curr; i--) // Shift elements up
            listArray[i] = listArray[i-1]; // to make room
        listArray[curr] = it;
        listSize++; // Increment list size
    }
    void append(const E& it)   // Append "it"
    {
        if(listSize+1==maxSize)
        {
            maxSize+=chunk;
            delete [] listArray;
            listArray=new E[maxSize];
            listArray=helpingArray;
            delete [] helpingArray;
            helpingArray=new E[maxSize];
            helpingArray=listArray;
        }
        //Assert(listSize < maxSize, "List capacity exceeded");
        listArray[listSize++] = it;
    }
// Remove and return the current element.
    E remove()
    {
        //Assert((curr>=0) && (curr < listSize), "No element");
        if(listSize==0)
        {
            return -1;
        }
        E it = listArray[curr]; // Copy the element
        for(int i=curr; i<listSize-1; i++) // Shift them down
            listArray[i] = listArray[i+1];
        listSize--; // Decrement size
        if(curr==listSize)
            curr--;
        return it;
    }
    void moveToStart()
    {
        curr = 0;    // Reset position
    }
    void moveToEnd()
    {
        curr = listSize-1;    // Set at end
    }
    void prev()
    {
        if (curr > 0) curr--;    // Back up
    }
    void next()
    {
        if (curr < listSize-1) curr++;    // Next
    }
// Return list size
    int length()
    {
        return listSize;
    }
// Return current position
    int currPos()
    {
        return curr;
    }
// Set current list position to "pos"
    void moveToPos(int pos)
    {
        //Assert ((pos>=0)&&(pos<=listSize), "Pos out of range");
        if(pos<0||pos>=listSize) return;
        curr = pos;
    }
    const E& getValue()    // Return current element
    {
        //Assert((curr>=0)&&(curr<listSize),"No current element");
        return listArray[curr];
    }
    int searchItem(const E& it)
    {
        for(int i=0; i<listSize; i++)
        {
            if(listArray[i]==it)
            {
                return 1;
            }
        }
        return -1;
    }
};


