#include "deque_test.hpp"
#include "deque.hpp"
#include <gtest/gtest.h>

class DequeTest : public ::testing::Test {
  protected:
    void SetUp() override {}

    void TearDown() override {}

    Deque<int> intDeque;
    Deque<std::string> stringDeque;
};

TEST_F(DequeTest, IsDequeEmpty) {
    EXPECT_EQ(intDeque.isEmpty(), true);
    intDeque.pushLeft(1);
    EXPECT_EQ(intDeque.isEmpty(), false);
}

TEST_F(DequeTest, PushLeftAddsElementToFront) {
    intDeque.pushLeft(1);
    EXPECT_EQ(intDeque.peekLeft(), 1);
    EXPECT_EQ(intDeque.peekRight(), 1);

    intDeque.pushLeft(2);
    EXPECT_EQ(intDeque.peekLeft(), 2);
    EXPECT_EQ(intDeque.peekRight(), 1);

    intDeque.pushLeft(3);
    EXPECT_EQ(intDeque.peekLeft(), 3);
    EXPECT_EQ(intDeque.peekRight(), 1);
}

TEST_F(DequeTest, PushRightAddsElementToBack) {
    intDeque.pushRight(2);
    EXPECT_EQ(intDeque.peekLeft(), 2);
    EXPECT_EQ(intDeque.peekRight(), 2);

    intDeque.pushRight(3);
    EXPECT_EQ(intDeque.peekLeft(), 2);
    EXPECT_EQ(intDeque.peekRight(), 3);

    intDeque.pushRight(4);
    EXPECT_EQ(intDeque.peekLeft(), 2);
    EXPECT_EQ(intDeque.peekRight(), 4);
}

TEST_F(DequeTest, PushOperationsWithStrings) {
    stringDeque.pushLeft("world");
    stringDeque.pushLeft("hello");
    stringDeque.pushRight("!");

    EXPECT_EQ(stringDeque.peekLeft(), "hello");
    EXPECT_EQ(stringDeque.peekRight(), "!");
}

TEST_F(DequeTest, EmptyDequeBehavior) {
    EXPECT_THROW(intDeque.peekLeft(), std::out_of_range);
    EXPECT_THROW(intDeque.peekRight(), std::out_of_range);
}
