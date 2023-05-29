template <typename E>class list
{
private:
    void operator = (const list&){}
    list(const list&){}
public:
    list(){}
    virtual ~list(){}
    virtual void clear()=0;
    virtual void push(const E& it)=0;
    virtual E pop()=0;
    virtual E length()=0;
    virtual const E& topValue()=0;
    virtual void setDirection(int var)=0;
};
