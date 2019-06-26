
#include "linkedStack.h"
#include <iostream>

using namespace std;

linkedStack::linkedStack()
{
	stackTop = NULL;
}

linkedStack::~linkedStack()
{
	initializeStack();
}

bool linkedStack::isStackEmpty() const
{
	return (stackTop == NULL);
}

void linkedStack::initializeStack()
{
	nodeType * temp;
	
	while(stackTop != NULL)
	{
		temp = stackTop;
		stackTop = stackTop -> link;
		delete temp;
	}
}

void linkedStack::pop()
{
	nodeType * temp;
	
	if(stackTop != NULL)
	{
		temp = stackTop;
		
		stackTop = stackTop -> link;
		
		delete temp;
	}
}

void linkedStack::push(const int &newElement)
{
	nodeType * newNode;
	
	newNode = new nodeType;
	
	newNode -> info = newElement;
	newNode -> link = stackTop;
	stackTop = newNode;
}

int linkedStack::top() const
{
	int lpeek = stackTop -> info;
	return lpeek;
}
