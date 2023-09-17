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