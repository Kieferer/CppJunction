#include "TreeSet/TreeSet.h"

TreeSet::~TreeSet() {
    destroyTree(root);
}

void TreeSet::add(int value) {

}

void TreeSet::remove(int value) {

}

bool TreeSet::contains(int value) {
    return false;
}

int TreeSet::size() {
    return 0;
}

TreeNode* TreeSet::addRecursive(TreeNode* node, int value) {
    return nullptr;
}

TreeNode* TreeSet::removeRecursive(TreeNode* node, int value) {
    return nullptr;
}

TreeNode* TreeSet::containsRecursive(TreeNode* node, int value) {
    return nullptr;
}

int TreeSet::sizeRecursive(TreeNode* node) {
    return nullptr;
}

TreeNode* TreeSet::leftRotate(TreeNode* x) {
    TreeNode* y = x->getRight();
    TreeNode* T2 = y->getLeft();

    y->setLeft(x);
    x->setRight(T2);

    x->recalculateHeight();
    y->recalculateHeight();

    return y;
}

TreeNode* TreeSet::rightRotate(TreeNode* y) {
    TreeNode* x = y->getLeft();
    TreeNode* T2 = x->getRight();

    x->setRight(y);
    y->setLeft(T2);

    y->recalculateHeight();
    x->recalculateHeight();

    return x;
}

void TreeSet::destroyTree(TreeNode* node) {
    if (node){
        destroyTree(node->getLeft());
        destroyTree(node->getRight());
        delete node;
    }
}

