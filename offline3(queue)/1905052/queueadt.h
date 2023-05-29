template<typename E> class list
{
    private:
    void operator = (const list&){}
    list(const list&){}
public:
    list(){}
    virtual ~list(){}
    virtual void clear()=0;
    virtual void enqueue(E it)=0;
    virtual E dequeue()=0;
    virtual int length()=0;
    virtual E frontvalue()=0;
    virtual E rearvalue()=0;
    virtual E leavequeue()=0;
};
