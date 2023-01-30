#include <iostream>
#include <string>
#include "pch.h"
#include "..\Calculator\Calculator.cpp"

using namespace std;

TEST(Calc, check_the_line_is_empty)
{
	string s = "";
	ASSERT_ANY_THROW(Calculator::NoMistakes(s));
}

TEST(Calculator, check_first_elem_is_a_closing_bracket)
{
	string s = ")A";
	ASSERT_ANY_THROW(Calculator::NoMistakes(s));
}

TEST(Calculator, check_there_are_mistakes_brackets_together1)
{
	string s = "A()";
	ASSERT_ANY_THROW(Calculator::NoMistakes(s));
}

TEST(Calculator, check_there_are_mistakes_brackets_together2)
{
	string s = "A)(";
	ASSERT_ANY_THROW(Calculator::NoMistakes(s));
}

TEST(Calculator, check_different_number_of_brackets)
{
	string s = "(A+B)+(";
	ASSERT_ANY_THROW(Calculator::NoMistakes(s));
}

TEST(Calculator, check_not_enough_operands)
{
	string s = "A+B-";
	ASSERT_ANY_THROW(Calculator::NoMistakes(s));
}

TEST(Calculator, check_too_many_operands)
{
	string s = "A+BC";
	ASSERT_ANY_THROW(Calculator::NoMistakes(s));
}

TEST(Calculator, check_right_result_plus)
{
	std::string infix = "A+B";
	std::string postfix;

	double res;

	if (Calculator::NoMistakes(infix) == true)
		postfix = Calculator::Postfix(infix);

	char operands[] = { 'A', 'B' };
	double value_operands[] = { 10, 5 };
	int number_of_operands = 2;
	res = Calculator::Calculate(postfix, operands, value_operands, number_of_operands);

	EXPECT_EQ(15, res);
}

TEST(Calculator, check_right_result_minus)
{
	std::string infix = "A-B";
	std::string postfix;

	double res;

	if (Calculator::NoMistakes(infix) == true)
		postfix = Calculator::Postfix(infix);

	char operands[] = { 'A', 'B' };
	double value_operands[] = { 10, 5 };
	int number_of_operands = 2;
	res = Calculator::Calculate(postfix, operands, value_operands, number_of_operands);

	EXPECT_EQ(5, res);
}

TEST(Calculator, check_right_result_one_multiplication)
{
	std::string infix = "A*B";
	std::string postfix;

	double res;

	if (Calculator::NoMistakes(infix) == true)
		postfix = Calculator::Postfix(infix);

	char operands[] = { 'A', 'B' };
	double value_operands[] = { 10, 5 };
	int number_of_operands = 2;
	res = Calculator::Calculate(postfix, operands, value_operands, number_of_operands);

	EXPECT_EQ(50, res);
}

TEST(Calculator, check_right_result_division)
{
	std::string infix = "A/B";
	std::string postfix;

	double res;

	if (Calculator::NoMistakes(infix) == true)
		postfix = Calculator::Postfix(infix);

	char operands[] = { 'A', 'B' };
	double value_operands[] = { 10, 5 };
	int number_of_operands = 2;
	res = Calculator::Calculate(postfix, operands, value_operands, number_of_operands);

	EXPECT_EQ(2, res);
}

TEST(Calculator, check_right_result_algebraic_expression)
{
	std::string infix = "a+b*c*d-(e-f)/(g*h+i)";
	std::string postfix;

	double res;

	if (Calculator::NoMistakes(infix) == true)
		postfix = Calculator::Postfix(infix);

	char operands[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i' };
	double value_operands[] = { 0.33, 1, 2, 3, 6, 4, 0.5, 2, 1 };
	int number_operands = 9;
	res = Calculator::Calculate(postfix, operands, value_operands, number_operands);

	EXPECT_EQ(5.33, res);
}