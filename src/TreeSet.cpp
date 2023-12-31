#include "TreeSet/TreeSet.h"

TreeSet::~TreeSet() {
    destroyTree(root);
}

void TreeSet::add(int value) {
    root = addRecursive(root, value);
}

void TreeSet::remove(int value) {
    root = removeRecursive(root, value);
}

bool TreeSet::contains(int value) {
    return containsRecursive(root, value);
}

bool TreeSet::isEmpty() {
    return size() == 0;
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
    if (node == nullptr) {
        return nullptr;
    }

    if (value < node->getKey()) {
        node->setLeft(removeRecursive(node->getLeft(), value));
    } else if (value > node->getKey()) {
        node->setRight(removeRecursive(node->getRight(), value));
    } else {
        if (node->getLeft() == nullptr || node->getRight() == nullptr) {
            TreeNode* temp = (node->getLeft() != nullptr) ? node->getLeft() : node->getRight();
            if (temp == nullptr) {
                node = nullptr;
            } else {
                *node = *temp;
                delete temp;
            }
        } else {
            TreeNode* current = node->getRight();
            while (current->getLeft() != NULL) {
                current = current->getLeft();
            }
            node->setKey(current->getKey());

            node->setRight(removeRecursive(node->getRight(), current->getKey()));
        }
    }

    node->recalculateHeight();
    int balance = node->getBalance();

    if (balance > 1) {
        if (value < node->getLeft()->getKey()) {
            return rightRotate(node);
        }
        if (value > node->getLeft()->getKey()) {
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

bool TreeSet::containsRecursive(TreeNode* node, int value) {
    if (node == nullptr){
        return false;
    }

    if (value == node->getKey()) {
        return true;
    } else if (value < node->getKey()) {
        return containsRecursive(node->getLeft(), value);
    } else {
        return containsRecursive(node->getRight(), value);
    }
}

int TreeSet::sizeRecursive(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }

    int sizeLeft = sizeRecursive(node->getLeft());
    int sizeRight = sizeRecursive(node->getRight());
    return (sizeLeft + sizeRight) + 1;
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

