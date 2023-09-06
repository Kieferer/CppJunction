class TreeSet {
public:
    TreeSet();
    ~TreeSet();

    void insert(int value);
    void remove(int value);
    bool contains(int value);

private:
    struct TreeNode {
        int data;
        TreeNode *left;
        TreeNode *right;
        int height;
    };
    TreeNode *root;
};