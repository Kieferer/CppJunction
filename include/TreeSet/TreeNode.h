#include <algorithm>

class TreeNode {
private:
    int key;
    int height;
    TreeNode* left;
    TreeNode* right;

public:
    TreeNode(int key) {
        this->key = key;
        height = 1;
        left = nullptr;
        right = nullptr;
    }

    int getKey() const { return key; };
    int getHeight() const { return height; };
    TreeNode* getLeft() const { return left; };
    TreeNode* getRight() const { return right; };

    void setHeight(int height) { this->height = height; }
    void setLeft(TreeNode* left) { this->left = left; }
    void setRight(TreeNode* right) { this->right = right; }

    void recalculateHeight() {
        int leftHeight = (left) ? left->getHeight() : 0;
        int rightHeight = (right) ? right->getHeight() : 0;
        height = std::max(leftHeight, rightHeight) + 1;
    }

    int getBalance() {
        int leftHeight = (left) ? left->getHeight() : 0;
        int rightHeight = (right) ? right->getHeight() : 0;
        return leftHeight - rightHeight;
    }
};