class TreeSet {
public:
    TreeSet();
    ~TreeSet();

    void insert(int value);
    void remove(int value);
    bool contains(int value);

private:
    struct TreeNode {
        int key;
        int height;
        TreeNode *left;
        TreeNode *right;
    };
    TreeNode *root;
};