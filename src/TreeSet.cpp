#include "TreeSet/TreeSet.h"

TreeSet::~TreeSet() {
    destroyTree(root);
}

void TreeSet::add(int value) {
    addRecursive(root, value);
}

void TreeSet::remove(int value) {
    removeRecursive(root, value);
}

bool TreeSet::contains(int value) {
    return containsRecursive(root, value);
}

int TreeSet::size() {
    return sizeRecursive(root);
}

TreeNode* TreeSet::addRecursive(TreeNode* node, int value) {
    if (node == nullptr){
        return new TreeNode(value);
    }

    if (value < node->getKey()){
        node->setLeft(addRecursive(node->getLeft(), value));
    } else if (value > node->getKey()) {
        node->setRight(addRecursive(node->getRight(), value));
    } else {
        return node;
    }

    node->recalculateHeight();
    int balance = node->getBalance();

    if (balance > 1) {
        if (value < node->getLeft()->getKey()){
            return rightRotate(node);
        }
        if (value > node->getLeft()->getKey()){
            return leftRotate(node->getLeft());
        }
    } else if (balance < -1) {
        if (value > node->getRight()->getKey()) {
            return leftRotate(node);
        }
        if (value < node->getRight()->getKey()) {
            node->setRight(rightRotate(node->getRight()));
            return leftRotate(node);
        }
    }

    return node;
}

TreeNode* TreeSet::removeRecursive(TreeNode* node, int value) {
    return nullptr;
}

TreeNode* TreeSet::containsRecursive(TreeNode* node, int value) {
    return nullptr;
}

int TreeSet::sizeRecursive(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }

    int sizeLeft = sizeRecursive(node->getLeft());
    int sizeRight = sizeRecursive(node->getRight());
    return 0;
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

