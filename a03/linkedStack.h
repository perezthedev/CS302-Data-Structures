
#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include <iostream>

struct nodeType{
	int info;
	nodeType * link;
};

class linkedStack
{
	public:
		linkedStack();
		~linkedStack();
		void push(const int&);
		void pop();
		int top() const;
		bool isStackEmpty() const;
		void initializeStack();
		
	private:
		nodeType * stackTop;
		
};

#endif
