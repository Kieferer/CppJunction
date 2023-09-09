#include "Collection.h"

class TreeSet : public Collection {
public:
    TreeSet();
    ~TreeSet();

    void add(int value) override;
    void remove(int value) override;
    bool contains(int value) override;
    int size() override;

private:
    struct TreeNode {
        int key;
        int height;
        TreeNode *left;
        TreeNode *right;
    };
    TreeNode *root;
};