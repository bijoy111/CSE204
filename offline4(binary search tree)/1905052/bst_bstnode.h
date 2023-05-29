//binary search tree node implementation
template <typename E>
class BSTNode : public BinNode<E>
{
private:
    E value; // The node’s value
    BSTNode* leftchild; // Pointer to left child
    BSTNode* rightchild; // Pointer to right child
public:
    BSTNode()
    {
        leftchild = rightchild = NULL;
    }
    BSTNode(E e, BSTNode* left =NULL, BSTNode* right =NULL)
    {
        value = e;
        leftchild = left;
        rightchild = right;
    }
    ~BSTNode() {} // Destructor
    E& element()
    {
        return value;
    }
    void setElement(const E& e)
    {
        value = e;
    }
    inline BSTNode* left() const
    {
        return leftchild;
    }
    void setLeft(BinNode<E>* left)
    {
        leftchild = (BSTNode*)left;
    }
    inline BSTNode* right() const
    {
        return rightchild;
    }
    void setRight(BinNode<E>* right)
    {
        rightchild = (BSTNode*)right;
    }
};

