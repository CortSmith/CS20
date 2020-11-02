//============================================================================
// Name        : CS20_Stack_Calculator.cpp
// Author      : Cort Smith
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
using namespace std;

int main() {

	stack<double> myCalculatorStack;

	double xValue = 0;


	// Execute this equation: 10 + 20 + 30
	myCalculatorStack.push(10);
	myCalculatorStack.push(20);
	myCalculatorStack.push(30);

	xValue += myCalculatorStack.top();
	myCalculatorStack.pop();
	cout << "Current value of x is: " << xValue << endl;
	xValue += myCalculatorStack.top();
	myCalculatorStack.pop();
	cout << "Current value of x is: " << xValue << endl;
	xValue += myCalculatorStack.top();
	myCalculatorStack.pop();
	cout << "Current value of x is: " << xValue << endl;



	// Execute this equation: 10 * (30 - 5) / 50.
	xValue = 0;
	myCalculatorStack.push(50);
	myCalculatorStack.push(10);
	myCalculatorStack.push(5);
	myCalculatorStack.push(30);

	xValue = myCalculatorStack.top();
	myCalculatorStack.pop();
	xValue -= myCalculatorStack.top();
	myCalculatorStack.pop();
	xValue *= myCalculatorStack.top();
	myCalculatorStack.pop();
	xValue /= myCalculatorStack.top();
	myCalculatorStack.pop();

	// Equation: 32 / 5 + 6 * 4 / 2

	/*
	push(2)
	push(4)
	push(6)
	push(5)
	push(32)
	*/

	myCalculatorStack.push(5);
	myCalculatorStack.push(32);
	myCalculatorStack.push(6);
	myCalculatorStack.push(2);
	myCalculatorStack.push(4);

	cout << "xValue: " << xValue << endl;

	xValue = 0;
	double xTemp = 0;

	xValue = myCalculatorStack.top();
	myCalculatorStack.pop();
	xValue /= myCalculatorStack.top();
	myCalculatorStack.pop();
	xValue *= myCalculatorStack.top();
	myCalculatorStack.pop();

	xTemp = myCalculatorStack.top();
	myCalculatorStack.pop();
	xTemp /= myCalculatorStack.top();
	myCalculatorStack.pop();

	xValue += xTemp;

	cout << "xValue: " << xValue << endl;








	cout << "Program ending, have a nice day!" << endl; // prints !!!Hello World!!!
	return 0;
}
