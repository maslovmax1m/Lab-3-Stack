#include "pch.h"
#include "..\Calculator\TStack.h"

TEST(TStack, can_create_stack_with_positive_maxsize)
{
	ASSERT_NO_THROW(TStack<int> st(15));
}

TEST(TStack, can_create_stack_containing_chars)
{
	ASSERT_NO_THROW(TStack<char> st(15));
}

TEST(TStack, throws_when_create_stack_with_negative_maxsize)
{
	ASSERT_ANY_THROW(TStack<int> st(-15));
}

TEST(TStack, can_push_elem)
{
	TStack<int> st(2);

	ASSERT_NO_THROW(st.Push(3));
}

TEST(TStack, throws_when_stack_is_full)
{
	TStack<int> st(2);
	st.Push(1);
	st.Push(2);

	ASSERT_ANY_THROW(st.Push(3));
}

TEST(TStack, can_pop_elem)
{
	TStack<int> st(2);
	st.Push(1);
	st.Push(2);

	ASSERT_NO_THROW(st.Pop());
}

TEST(TStack, throws_when_stack_is_empty)
{
	TStack<int> st(2);

	ASSERT_ANY_THROW(st.Pop());
}

TEST(TStack, check_stack_is_empty)
{
	TStack<int> st(2);

	EXPECT_EQ(true, st.IsEmpty());
}

TEST(TStack, check_stack_is_not_empty)
{
	TStack<int> st(2);
	st.Push(1);
	st.Push(2);

	EXPECT_EQ(false, st.IsEmpty());
}

TEST(TStack, check_stack_is_full)
{
	TStack<int> st(2);
	st.Push(1);
	st.Push(2);

	EXPECT_EQ(true, st.IsFull());
}

TEST(TStack, check_stack_is_not_full)
{
	TStack<int> st(2);
	st.Push(1);

	EXPECT_EQ(false, st.IsFull());
}

TEST(TStack, can_stack_show_top)
{
	TStack<int> st(2);
	st.Push(1);

	EXPECT_EQ(1, st.Top());
}