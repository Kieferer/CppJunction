#include "Collection.h"
#include "TreeNode.h"

class TreeSet : public Collection {
public:
    ~TreeSet();

    void add(int value) override;
    void remove(int value) override;
    bool contains(int value) override;
    int size() override;

private:
    TreeNode* root;

    TreeNode* addRecursive(TreeNode* node, int value);
    TreeNode* removeRecursive(TreeNode* node, int value);
    TreeNode* containsRecursive(TreeNode* node, int value);
    int sizeRecursive(TreeNode* node);

    TreeNode* rightRotate(TreeNode* y);
    TreeNode* leftRotate(TreeNode* x);

    void destroyTree(TreeNode* node);
};