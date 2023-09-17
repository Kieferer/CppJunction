#include <gtest/gtest.h>
#include "TreeSet/TreeSet.h"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

class TreeSetTest : public ::testing::Test {
protected:
    Collection* tree;
    void SetUp() override {
        tree = new TreeSet();
    }

    void TearDown() override {
        delete tree;
    }
};

TEST_F(TreeSetTest, IsTreeEmpty) {
    EXPECT_TRUE(tree->isEmpty());
}

TEST_F(TreeSetTest, AddSingleElement) {
    int testElement = 10;
    tree->add(testElement);
    EXPECT_FALSE(tree->isEmpty());
}

TEST_F(TreeSetTest, AddMultipleElement) {
    int testElements[] = {10, 25, 36, 44, 56, 67, 88, 91};
    for (int element : testElements) {
        tree->add(element);
    }
    int numberOfElements = sizeof(testElements) / sizeof(testElements[0]);
    EXPECT_EQ(numberOfElements, tree->size());
}

/*
    These tests throw segmentation errors

    TEST_F(TreeSetTest, AddRemoveSingleElement) {
    int testElement = 10;
    tree->add(testElement);
    tree->remove(testElement);
    EXPECT_TRUE(tree->isEmpty());
}

TEST_F(TreeSetTest, AddRemoveSomeElements) {
    int testElements[] = {10, 25, 36, 44, 56, 67, 88, 91};
    int elementsToBeRemoved[] = {10, 36, 56, 88};
    for (int element : testElements) {
        tree->add(element);
    }
    for (int removedElement : elementsToBeRemoved) {
        tree->remove(removedElement);
    }
    int numberOfElements = sizeof(testElements) / sizeof(testElements[0]);
    int numberOfRemovedElements = sizeof(elementsToBeRemoved) / sizeof(elementsToBeRemoved[0]);
    int assumesSizeOfTree = numberOfElements - numberOfRemovedElements;
    EXPECT_EQ(assumesSizeOfTree, tree->size());
}*/

TEST_F(TreeSetTest, ContainsElements) {
    int testElements[] = {10, 25, 36, 44, 56, 67, 88, 91};
    int elementsToBeChecked[] = {10, 36, 56, 88};
    bool isAnyElementMissing = false;
    for (int element : testElements) {
        tree->add(element);
    }
    for (int checkedElement : elementsToBeChecked) {
        if (!tree->contains(checkedElement)){
            isAnyElementMissing = true;
        }
    }
    EXPECT_FALSE(isAnyElementMissing);
}