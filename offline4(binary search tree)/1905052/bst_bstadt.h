// BstAdt abstract class.
template <typename E> class BstAdt
{
private:
    void operator =(const BstAdt&) {}//overload assignment operator
    BstAdt(const BstAdt&) {}//copy constructor
public:
    BstAdt() {}
    virtual ~BstAdt() {}
    virtual void clear() = 0;
    virtual void insert(const E& e) = 0;
    virtual E remove(const E& e) = 0;
    virtual E find(const E& e) const = 0;
};

