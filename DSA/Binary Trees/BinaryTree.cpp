#include <iostream>

class BinaryNode
{
public:
    BinaryNode *left = nullptr;
    BinaryNode *right = nullptr;
    int value;

    BinaryNode(int value) : value(value) {}
    BinaryNode(int value, BinaryNode *left, BinaryNode *right) : value(value), left(left), right(right) {}
};

class BinaryTree
{
public:
    BinaryNode *root = nullptr;

    BinaryTree(BinaryNode *root) : root(root) {}

    /**
     * Reverse the Binary Tree using the Depth-First Approach
     * 
     * @param node: Root of the tree
     */
    void reverse_DF(BinaryNode *node)
    {
        BinaryNode *prevLeft = node->left;
        node->left = node->right;
        node->right = prevLeft;

        if (node->left != nullptr)
        {
            reverse_DF(node->left);
        }
        if (node->right != nullptr)
        {
            reverse_DF(node->right);
        }
    }

    /**
     * Merge another Binary Tree with current tree
     * 
     * @param tree: Tree to be merged
     * @param newRootValue: Value of the new root
     * @param atRight: If true, root of tree to be merged will aquire right position in the new root else left
     */
    void merge(BinaryTree *tree, int newRootValue, bool atRight)
    {
        BinaryNode *newRoot = atRight ? new BinaryNode(newRootValue, root, tree->root) : new BinaryNode(newRootValue, tree->root, root);
        this->root = newRoot;
    }
};

int main()
{
    BinaryNode *r2c1l = new BinaryNode(4);
    BinaryNode *r2c1r = new BinaryNode(5);
    BinaryNode *r1l = new BinaryNode(2, r2c1l, r2c1r);
    BinaryNode *r2c2l = new BinaryNode(6);
    BinaryNode *r1r = new BinaryNode(3, r2c2l, nullptr);
    BinaryNode *root = new BinaryNode(1, r1l, r1r);

    BinaryTree *tree1 = new BinaryTree(root);
    BinaryTree *tree2 = new BinaryTree(root);

    tree1->reverse_DF(tree1->root);
    tree1->merge(tree2, 10, true);

    return 0;
}

/*
      1                1
    /   \            /   \
   2     3          3     2
  / \    |         / \   / \
 4   5   6        7   6 5   4
*/