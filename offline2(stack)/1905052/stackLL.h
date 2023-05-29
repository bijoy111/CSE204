template <typename E> class Link
{
public:
    E element; // Value for this node
    Link *next; // Pointer to next node in list

    Link(const E& elemval, Link* nextval)
    {
        element = elemval;
        next = nextval;
    }
    Link(Link* nextval)
    {
        next = nextval;
    }
};
template <typename E> class llist:public list<E>
{
private:
    Link<E> *top;
    int size;
public:

    llist()
    {
        size=0;
        top=new Link<E>(NULL,NULL);
    }
    llist(E* lists,E k)
    {
        top=new Link<E>(NULL,NULL);
        for(int i=0; i<k; i++)
        {
            top=new Link<E>(lists[i],top);
            size++;
        }
    }
    ~llist()
    {
        clear();
    }
    void clear()
    {
        while (top != NULL)   // Delete link nodes
        {
            Link<E>* temp = top;
            top = top->next;
            delete temp;
        }
        size = 0;
        top=new Link<E>(NULL,NULL);
    }
    void push(const E&it)
    {
        top=new Link<E>(it,top);
        size++;
    }
    E pop()
    {
        if(size>0)
        {
        E it = top->element;
        Link<E>* tmp = top->next;
        delete top;
        top = tmp;
        size--;
        return it;
        }
        else
        {
            std::cout<<"The stack is empty"<<std::endl;
            return -1;
        }
    }
    E length()
    {
        return size;
    }
    const E& topValue()
    {
        if(size>0)
        return top->element;
        else
        {
            std::cout<<"The stack is empty"<<std::endl;
            return -1;
        }
    }
    void setDirection(int var)
    {
        std::cout<<"You can not set direction for link list based implementation"<<std::endl;
        return;
    }
};
