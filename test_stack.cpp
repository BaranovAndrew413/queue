#include "..\queue\TQueue.h"

#include "gtest.h"

TEST(TQueue, can_create_TQueue_with_positive_length)
{
	ASSERT_NO_THROW(TQueue<int> ts(3));                    
}                                                       


TEST(TStack, can_create_TQueue_with_negative_length)
{
	ASSERT_ANY_THROW(TQueue<int> ts(-3));
}

TEST(TQueue, vzyatie_is_pustogo_TStack)
{
	TQueue<int>ts(1);
	ASSERT_ANY_THROW(ts.Pop());
}

TEST(TStack, vzyatie_verhnego_elementa_is_TStack)
{
	TQueue<int>ts(2);
	ts.Push(1);
	ts.Push(2);
	ASSERT_EQ(ts.Top(),2);
}

TEST(TQueue, ubrat_verhniy_element_is_TQueue)
{
	TQueue<int>ts(2);
	ts.Push(1);
	ts.Push(2);
	ts.Pop();
	ASSERT_EQ(ts.Top(),1);
}

TEST(TQueue, vzyatie_verhnego_elementa_is_pystogo_TQueue)
{
	TQueue<int>ts(0);
	ASSERT_ANY_THROW(ts.Top());
}

TEST(TQueue, ybrat_element_is_pystogo_TStack)
{
	TQueue<int>ts(0);
	ASSERT_ANY_THROW(ts.Pop());
}

TEST(TQueue, can_create_copied_TQueue)
{
	TQueue<int> m(5);
	ASSERT_NO_THROW(TQueue<int> m1(m));
}

TEST(TStack, copied_TQueue_is_equal_to_source_one)
{
	TQueue <int> m(4);
	m.Push(1);
	TQueue <int> m1(m);
	int a = m.Pop();
	int b = m1.Pop();
	EXPECT_EQ(a, b);
}

TEST(TQueue, copied_TQueue_has_its_own_memory)
{
	TQueue<int> m1(4);
	TQueue<int> m2(4);

	m1.Push(1);
	m1.Push(2);

	m2.Push(1);
	m2.Push(2);
	EXPECT_FALSE(&m1 == &m2);
}