#include <circulardeque.h>
#include <gtest/gtest.h>

TEST(CircularDeque, empty)
{
    CircularDeque<int> deque;
    EXPECT_TRUE(deque.empty());
}

TEST(CircularDeque, nonEmpty)
{
    CircularDeque<int> deque;
    deque.push_back(0);
    EXPECT_FALSE(deque.empty());
}

TEST(CircularDeque, sizeZero)
{
    CircularDeque<int> deque;
    EXPECT_EQ(0, deque.size());
}

TEST(CircularDeque, sizeFour)
{
    CircularDeque<int> deque;
    for (int i = 0; i < 4; ++i) {
        deque.push_back(i);
    }
    EXPECT_EQ(4, deque.size());
}

TEST(CircularDeque, pushFront)
{
    CircularDeque<int> deque;
    deque.push_front(99);
    EXPECT_EQ(99, deque.front());
    EXPECT_EQ(99, deque.back());
}

TEST(CircularDeque, pushBack)
{
    CircularDeque<int> deque;
    deque.push_back(99);
    EXPECT_EQ(99, deque.front());
    EXPECT_EQ(99, deque.back());
}

TEST(CircularDeque, pushFrontAndBack)
{
    CircularDeque<int> deque;
    deque.push_front(-99);
    deque.push_back(99);
    EXPECT_EQ(2,   deque.capacity());
    EXPECT_EQ(2,   deque.size());
    EXPECT_EQ(-99, deque.front());
    EXPECT_EQ(99,  deque.back());
    EXPECT_EQ(-99, deque.front());
}

TEST(CircularDeque, pushBackAndPopFront)
{
    CircularDeque<int> deque;
    for (int i = 0; i < 3; ++i) {
        deque.push_back(i);
    }
    for (int i = 0; i < 3; ++i) {
        EXPECT_EQ(i, deque.front());
        deque.pop_front();
    }
    EXPECT_TRUE(deque.empty());
}

TEST(CircularDeque, pushFrontAndPopBack)
{
    CircularDeque<int> deque;
    for (int i = 0; i < 3; ++i) {
        deque.push_front(i);
    }
    for (int i = 0; i < 3; ++i) {
        EXPECT_EQ(i, deque.back());
        deque.pop_back();
    }
    EXPECT_TRUE(deque.empty());
}

TEST(CircularDeque, pushFrontAndPushBack)
{
    CircularDeque<int> deque;
    for (int i = 0; i < 5; ++i) {
        deque.push_front(i);
        deque.push_back(i);
    }
    for (int i = 4; i >= 0; --i) {
        EXPECT_EQ(i, deque.front());
        EXPECT_EQ(i, deque.back());
        deque.pop_front();
        deque.pop_back();
    }
    EXPECT_TRUE(deque.empty());
}
