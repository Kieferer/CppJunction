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
