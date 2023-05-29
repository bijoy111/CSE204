// Binary tree node abstract class
template <typename E> class BinNode
{
public:
    virtual ~BinNode() {} // Base destructor
    virtual E& element() = 0;// Return the node’s value
    virtual void setElement(const E&) = 0;// Set the node’s value
    virtual BinNode* left() const = 0;// Return the node’s left child
    virtual void setLeft(BinNode*) = 0;// Set the node’s left child
    virtual BinNode* right() const = 0;// Return the node’s right child
    virtual void setRight(BinNode*) = 0;// Set the node’s right child
};
