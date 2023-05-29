// Binary Search Tree implementation for the Dictionary ADT
template <typename E>
class BST : public BstAdt<E>
{
private:
    BSTNode<E>* root; // Root of the BST
    int nodecount; // Number of nodes in the BST
    void private_clear(BSTNode<E>*);
    BSTNode<E>* private_insert(BSTNode<E>*,const E&);
    BSTNode<E>* private_remove(BSTNode<E>*, const E&);
    E private_find(BSTNode<E>*, const E&) const;
    BSTNode<E>* deletemin(BSTNode<E>*);
    BSTNode<E>* getmin(BSTNode<E>*);
    BSTNode<E>* deletemax(BSTNode<E>*);
    BSTNode<E>* getmax(BSTNode<E>*);
    void private_print(BSTNode<E>*) const;

public:

    BST()
    {
        root = NULL;    // Constructor
        nodecount = 0;
    }
    ~BST()
    {
        private_clear(root);    // Destructor
    }
    BSTNode<E>* getroot()
    {
        return root;
    }
    void clear() // Reinitialize tree
    {
        private_clear(root);
        root = NULL;
        nodecount = 0;
    }
// Insert a record into the tree.
// e is the record to insert.
    void insert(const E& e)
    {
        root = private_insert(root,e);
        nodecount++;
    }
// Remove a record from the tree.
    E remove(const E& e)
    {
        E var = private_find(root, e); // First find it
        if (var != NULL)
        {
            root = private_remove(root, e);
            nodecount--;
        }
        return var;
    }
    E find(const E& e) const
    {
        return private_find(root, e);
    }
    void print() const   // Print the contents of the BST
    {
        if (root == NULL)
        {
            std::cout << "The BST is empty.\n";
        }
        else
        {
            private_print(root);
        }
    }
};



template <typename E>
E BST<E>::private_find(BSTNode<E>* root, const E& e) const
{
    if (root == NULL)
    {
        return NULL; // Empty tree
    }
    if (e < root->element())
    {
        return private_find(root->left(), e); // Check left
    }
    else if(e > root->element())
    {
        return private_find(root->right(), e); // Check right
    }
    else
    {
        return root->element(); // Found it
    }
}


template <typename E>
BSTNode<E>* BST<E>::private_insert(BSTNode<E>* root, const E& e)
{
    if (root == NULL) // Empty tree: create node
    {
        return new BSTNode<E>(e, NULL, NULL);
    }
    else if (e < root->element())
    {
        root->setLeft(private_insert(root->left(),e));
    }
    else
    {
        root->setRight(private_insert(root->right(),e));
    }
    return root; // Return tree with node inserted
}


template <typename E>
BSTNode<E>* BST<E>::
deletemin(BSTNode<E>* rt)
{
    if (rt->left() == NULL) // Found min
    {
        return rt->right();
    }
    else   // Continue left
    {
        rt->setLeft(deletemin(rt->left()));
        return rt;
    }
}
template <typename E>
BSTNode<E>* BST<E>::
deletemax(BSTNode<E>* rt)
{
    if (rt->right() == NULL) // Found min
    {
        return rt->left();
    }
    else   // Continue left
    {
        rt->setRight(deletemax(rt->right()));
        return rt;
    }
}

template <typename E>
BSTNode<E>* BST<E>::
getmin(BSTNode<E>* rt)
{
    if (rt->left() == NULL)
    {
        return rt;
    }
    else
    {
        return getmin(rt->left());
    }
}
template <typename E>
BSTNode<E>* BST<E>::
getmax(BSTNode<E>* rt)
{
    if (rt->right() == NULL)
    {
        return rt;
    }
    else
    {
        return getmax(rt->right());
    }
}

// Remove a node with value e
template <typename E>
BSTNode<E>* BST<E>::
private_remove(BSTNode<E>* rt, const E& e)
{
    if (rt == NULL)
    {
        return NULL;
    }
    else if (e < rt->element())
    {
        rt->setLeft(private_remove(rt->left(), e));
    }
    else if(e > rt->element())
    {
        rt->setRight(private_remove(rt->right(), e));
    }
    else   // Found: remove it
    {
        BSTNode<E>* temp = rt;
        if (rt->left() == NULL)   // Only a right child
        {
            rt = rt->right(); // so point to right
            delete temp;
        }
        else if (rt->right() == NULL)   // Only a left child
        {
            rt = rt->left(); // so point to left
            delete temp;
        }
        else   // Both children are non-empty
        {
            BSTNode<E>* temp = getmax(rt->left());
            rt->setElement(temp->element());
            rt->setLeft(deletemax(rt->left()));
            delete temp;
        }
    }
    return rt;
}


template <typename E>
void BST<E>::
private_clear(BSTNode<E>* root)
{
    if (root == NULL)
    {
        return;
    }
    private_clear(root->left());
    private_clear(root->right());
    delete root;
}


template <typename E>
void BST<E>::
private_print(BSTNode<E>* root) const
{
    std::cout<<root->element();
    if(root->left() || root->right())
    {
        std::cout<<"(";
        if(root->left()!=NULL)
        {
            private_print(root->left()); // Do left subtree
        }
        std::cout<<")";
        std::cout<<"(";
        if(root->right()!=NULL)
        {
            private_print(root->right()); // Do right subtree
        }
        std::cout<<")";
    }
    else
    {
        return;
    }
}


//preorder traversal
template <typename E>
void preorder(BinNode<E>* root)
{
    if (root == NULL) return;
    // Perform desired action
    std::cout<<root->element()<<" ";
    preorder(root->left());
    preorder(root->right());
}
//postorder traversal
template <typename E>
void postorder(BinNode<E>* root)
{
    if (root == NULL) return;
    postorder(root->left());
    postorder(root->right());
    // Perform desired action
    std::cout<<root->element()<<" ";
}
//inorder traversal
template <typename E>
void inorder(BinNode<E>* root)
{
    if (root == NULL) return; // Empty subtree, do nothing
    inorder(root->left());
    // Perform desired action
    std::cout<<root->element()<<" ";
    inorder(root->right());
}

