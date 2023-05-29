template <typename E>class Link
{
public:
    E val;
    Link *next;
    Link(E v,Link *n)
    {
        val=v;
        next=n;
    }
    Link(Link *n)
    {
        next=n;
    }
};
template<typename E> class linkList:public list<E>
{
private:
    Link<E> *front;
    Link<E> *rear;
    int listSize;
public:
    linkList()
    {
        listSize=0;
        front=new Link<E>(NULL,NULL);
        rear=new Link<E>(NULL,NULL);
    }
    linkList(int k,E *lists)
    {
        listSize=k;
        front=new Link<E>(NULL,NULL);
        rear=new Link<E>(NULL,NULL);
        for(int i=0; i<k; i++)
        {
            if(front->next==NULL)
            {
                front->next=new Link<E>(lists[i],front->next);
                rear=front->next;
            }
            else
            {
                rear->next=new Link<E>(lists[i],rear->next);
                rear=rear->next;
            }
        }
    }
    ~linkList()
    {
        removeAll();
    }
    void removeAll()
    {
        while(front->next!=NULL)
        {
            Link<E>* tmp=front;
            front=front->next;
            delete tmp;
        }
    }
    void clear()
    {
        removeAll();
        front=new Link<E>(NULL,NULL);
        rear=new Link<E>(NULL,NULL);
        listSize=0;
    }
    void enqueue(E it)
    {
        if(front->next==NULL)
        {
            front->next=new Link<E>(it,front->next);
            rear=front->next;
        }
        else
        {
            rear->next=new Link<E>(it,rear->next);
            rear=rear->next;
        }
        listSize++;
    }
    E dequeue()
    {
        if(listSize==0)
        {
            std::cout<<"Queue is empty"<<std::endl;
            return -1;
        }
        E it=front->next->val;
        front->next=front->next->next;
        listSize--;
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
        return front->next->val;
    }
    E rearvalue()
    {
        if(listSize==0)
        {
            std::cout<<"Queue is empty"<<std::endl;
            return -1;
        }
        return rear->val;
    }
    E leavequeue()
    {
        if(listSize==0)
        {
            std::cout<<"Queue is empty"<<std::endl;
            return -1;
        }
        E leaveval;
        leaveval=rear->val;
         if(listSize==1)
        {
            clear();
            return leaveval;
        }
        Link <E> *tmp=front;
        while(tmp->next!=rear)
        {
            tmp=tmp->next;
        }
        rear=tmp;
        tmp=tmp->next;
        delete tmp;
        rear->next=new Link<E>(NULL,NULL);
        listSize--;
        return leaveval;
    }
};

