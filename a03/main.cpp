
//Ryan 
//Assignment #3
//Postfix Notation ( + - * / % )

//This program will read in the line operations to be performed,
// and then parse each string popping, and pushing
//all while checking for an operation. Once an
//operation is found, numbers are popped off the stack twice 
//(if stack is not empty) and the arithmetic is done.

//Limits: It does not accept invalid operations, and only takes ints

//Input: Lines of numbers and operators to do arithmetic with.

//Output: Will output the result of the arithmetic given from postfix notation,
//or will tell user the line is an invalid operation.


#include <iostream>
#include <string>
#include <sstream>
#include "linkedStack.h"

using namespace std;

int main()
{
	string line;
	
	//collects a line from read in file
	while(getline(cin, line))
	{
		bool flag = false;
		istringstream iss(line);
		string temp_line = "";
		linkedStack stack;
		
		// iss is the line being read,
		//temp_line is where the new parsed line is being stored
		//' ' is where the line string (iss) will split at
		
		//will parse the collected line until finished parsing
		while(getline(iss, temp_line, ' ')) 
		{
			

			if(temp_line == "+"|| temp_line == "-" ||temp_line == "%"
			|| temp_line == "*" ||temp_line == "/")//line is an operator
			{
				char temp_operator = temp_line[0]; // converts string into a char
				
				int num1;
				int num2;
				int temp_total;
				
				//used to find which operator is needed,
				//logic is about the same for each operator
				switch(temp_operator)
				{
					case '+':
						if(!stack.isStackEmpty()) //stack is NOT empty
						{
							num1 = stack.top();
							stack.pop();
						}
						else
						{
							flag = true;
						}
						if(!stack.isStackEmpty())
						{
							num2 = stack.top();
							stack.pop();
							temp_total = num2 + num1; //arithmetic
							stack.push(temp_total);
						}
						else
						{
							flag = true;
						}
						break;
					
					case '-':
						if(!stack.isStackEmpty())
						{
							num1 = stack.top();
							stack.pop();
						}
						else
						{
							flag = true;
						}
						if(!stack.isStackEmpty())
						{
							num2 = stack.top();
							stack.pop();
							temp_total = num2 - num1;
							stack.push(temp_total);
						}
						
						else
						{
							flag = true;
						}
						break;
					
					case '*':
						if(!stack.isStackEmpty())
						{
							num1 = stack.top();
							stack.pop();
						}
						else
						{
							flag = true;
						}
						if(!stack.isStackEmpty())
						{
							num2 = stack.top();
							stack.pop();
							temp_total = num2 * num1;
							stack.push(temp_total);
						}
						
						else
						{
							flag = true;
						}
						break;
					
					case '/':
						if(!stack.isStackEmpty())
						{
							num1 = stack.top();
							stack.pop();
						}
						else
						{
							flag = true;
						}
						if(!stack.isStackEmpty())
						{
							num2 = stack.top();
							stack.pop();
							temp_total = num2 / num1;
							stack.push(temp_total);
						}
						
						else
						{
							flag = true;
						}
						break;
					
					case '%':
						if(!stack.isStackEmpty())
						{
							num1 = stack.top();
							stack.pop();
						}
						else
						{
							flag = true;
						}
						if(!stack.isStackEmpty())
						{
							num2 = stack.top();
							stack.pop();
							temp_total = num2 % num1;
							stack.push(temp_total);
						}
						else
						{
							flag = true;
						}
						break;
				}
			}
			else // if the stirng is not an operator then it must be a number
			{
				int temp_num = stoi(temp_line); 
				stack.push(temp_num); //converts str to num and pushes on stack
			}
		}
		int final_num = stack.top(); // pops final solution, if their is more
		stack.pop();				// on stack, then it is invalid
		if(!stack.isStackEmpty())
		{
			flag = true;
		}
		
		//print solution
		cout << line << " => ";
		if(flag)
		{
			cout << "Invalid Expression" << endl;
		}
		else
		{
			cout << final_num << endl;
		}
	}
	
	return 0;
}
