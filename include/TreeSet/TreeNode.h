class TreeNode {
private:
    int key;
    int height;
    TreeNode *left;
    TreeNode *right;

public:
    int getKey();
    int getHeight();
    TreeNode getLeft();
    TreeNode getRight();
};