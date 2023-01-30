#include <iostream>
#include <string>
#include "TStack.h"
#include "HCalculator.h"

using namespace std;

void main()
{
	std::string infix, postfix;
	double result;
	cout << "~~~~~ Welcome. This is a calculator with brackets ~~~~~" << '\n';
	getline(cin, infix);
	cout << infix << '\n';
	try
	{
		if (Calculator::NoMistakes(infix) == true)
			postfix = Calculator::Postfix(infix);
		char* let;
		double* val;
		int n;
		Calculator::GettingValues(postfix, let, val, n);
		result = Calculator::Calculate(postfix, let, val, n);

		cout << "The result is " << result << '\n';
		delete[] let;
		delete[] val;
	}
	catch (const char* sms)
	{
		cout << sms << endl;
	}
}