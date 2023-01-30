#include <iostream>
#include <string>
#include "TStack.h"
#include "HCalculator.h"

using namespace std;

int Calculator::Priority(char operation)
{
	switch (operation)
	{
	case '*':
		return 3;
	case '/':
		return 3;
	case '+':
		return 2;
	case '-':
		return 2;
	case '(':
		return 1;
	default:
		cout << "Wrong Operation!" << operation;
		break;
	}
}

bool Calculator::NoMistakes(std::string infix)
{
	if (infix.length() == 0)
		throw "The line is empty";
	if (infix[0] == ')')
		throw "You cannot start with a bracket )";
	int open_bracket = 0, close_bracket = 0, operands = 0, operations = 0;
	for (int i = 0; i < infix.length(); i++)
	{
		if (infix[i] == '(')
		{
			if (i != 0)
				if (infix[i - 1] == ')')
					throw "Brackets together )(";
			open_bracket++;
		}
		if (infix[i] == ')')
		{
			if (i != 0)
				if (infix[i - 1] == '(')
					throw "Brackets together ()";
			close_bracket++;
		}
		if (isalpha(infix[i]))
			operands++;
		if ((infix[i] == '*') || (infix[i] == '/') || (infix[i] == '+') || (infix[i] == '-'))
			operations++;
	}
	if ((open_bracket > close_bracket) || (close_bracket > open_bracket))
		throw "Different number of brackets";
	if (operations >= operands)
		throw "Not enough operands";
	if ((operations + 1) != operands)
		throw "Too many operands";
	return true;
}

std::string Calculator::Postfix(std::string infix)
{
	int n = 0;
	TStack<char> postfix(20);
	TStack<char> stack(20);
	for (int i = 0; i < infix.length(); i++)
	{
		if (infix[i] == '(')
			stack.Push(infix[i]);
		if (isalpha(infix[i]))
		{
			postfix.Push(infix[i]);
		}
		if ((infix[i] == '*') || (infix[i] == '/') || (infix[i] == '+') || (infix[i] == '-'))
		{
			if (!stack.IsEmpty())
				if (Priority(stack.Top()) >= Priority(infix[i]))
				{
					postfix.Push(stack.Top());
					stack.Pop();
				}
			stack.Push(infix[i]);
		}
		if (infix[i] == ')')
		{
			while (stack.Top() != '(')
			{
				postfix.Push(stack.Top());
				stack.Pop();
			}
			stack.Pop();
		}
	}
	while (!stack.IsEmpty())
	{
		postfix.Push(stack.Top());
		stack.Pop();
	}

	char tmp[20];
	int i = 0;
	while (!postfix.IsEmpty())
	{
		tmp[i] = postfix.Top();
		postfix.Pop();
		i++;
	}
	for (int j = i; j < 20; j++)
		tmp[j] = '\0';


	std::string str_postfix = string(tmp);
	for (int j = 0; j < i / 2; j++)
		swap(str_postfix[j], str_postfix[i - j - 1]);
	cout << "Postfix form is: " << str_postfix << '\n';
	return str_postfix;
}

void Calculator::GettingValues(std::string postfix, char*& operands, double*& values, int& num_operands)
{
	num_operands = 0;
	for (int i = 0; i < postfix.length(); i++)
		if (isalpha(postfix[i]))
			num_operands++;
	int f;
	operands = new char[num_operands];
	values = new double[num_operands];
	num_operands = 0;
	for (int i = 0; i < postfix.length(); i++)
	{
		if (isalpha(postfix[i]))
		{
			f = 0;
			for (int j = 0; j < num_operands; j++)
				if (postfix[i] == operands[j])
					f++;
			if (f == 0)
			{
				operands[num_operands] = postfix[i];
				num_operands++;
			}
		}
	}

	for (int i = 0; i < num_operands; i++)
	{
		cout << operands[i] << '\n';
		cin >> values[i];
	}
}

double Calculator::Calculate(std::string postfix, char* operands, double* values, int num_operands)
{
	TStack<double> stack(postfix.length());

	char cur_elem;
	double left = 0, right = 0, result = 0;
	for (int i = 0; i < postfix.length(); i++)
	{
		cur_elem = postfix[i];
		if (isalpha(cur_elem))
		{
			for (int j = 0; j < num_operands; j++)
				if (cur_elem == operands[j])
				{
					stack.Push(values[j]);
					break;
				}
		}
		if (cur_elem == '*')
		{
			right = stack.Top();
			stack.Pop();
			left = stack.Top();
			stack.Pop();
			result = left * right;
			stack.Push(result);
		}
		if (cur_elem == '+')
		{
			right = stack.Top();
			stack.Pop();
			left = stack.Top();
			stack.Pop();
			result = left + right;
			stack.Push(result);
		}
		if (cur_elem == '-')
		{
			right = stack.Top();
			stack.Pop();
			left = stack.Top();
			stack.Pop();
			result = left - right;
			stack.Push(result);
		}
		if (cur_elem == '/')
		{
			right = stack.Top();
			stack.Pop();
			left = stack.Top();
			stack.Pop();
			result = left / right;
			stack.Push(result);
		}
	}
	return result;
}
