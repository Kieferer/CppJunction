class TreeNode {
private:
    int key;
    int height;
    TreeNode* left;
    TreeNode* right;

public:
    int getKey() const { return key; };
    int getHeight() const {return height; };
    TreeNode getLeft() const { return *left; };
    TreeNode getRight() const { return *right; };

    void setHeight(int height) { this->height = height; }
    void setLeft(TreeNode* left) { this->left = left; }
    void setRight(TreeNode* right) {this->right = right; }
};