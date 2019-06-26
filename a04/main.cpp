//Ryan
//Assignment #4

#include <iostream>
#include <sstream>
#include <string>
#include "linkedQueue.h"
#include "circularQueue.h"


using namespace std;

int main()
{
	//linkedQueue queue1;
	
	//cout << "Enter circular array size: ";
	//string num_line;
	//getline(cin, num_line);
	//static_cast<int>(num_line);
	//int array_size = stoi(num_line);
	
	int array_size = 5;
	
	//initialize the circular array
	circularQueue circle(array_size);
	
	circle.enqueue(circle.createQueue());
	
	cout << "Enqueued!:" << endl;
	circle.enqueue(0, 'A');
	circle.enqueue(0, 'B');
	circle.enqueue(0, 'C');
	circle.print();
	
	cout << "Dequeued!:" << endl;
	circle.dequeue();
	//circle.print();
	
	/*
	string line;
	while(getline(cin, line))
	{
		istringstream iss(line);
		string temp_char = "";
		//circle.array[0] = circle.createQueue();
		circle.enqueue(circle.createQueue());
		while(getline(iss, temp_char, ' '))
		{
			//cout << "Before enqueuearray" << endl;
				char char_data = temp_char[0];
			
			circle.enqueue((circle.array_front), char_data);
			
			//cout << circle[0] << endl;
			
			//cout << array1.print() << endl;
		}
		
	}
	*/
	
	//linkedQueue queue = array1.createQueue();
	
	
	
	
	
	return 0;
}
		
		
		
		
