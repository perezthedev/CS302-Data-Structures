
//Ryan Aponte
//Asignment #2
//This code tests the different algorithms.
//I commented out the normal for loops to test
//the loops without recursion, and then I wrote
//the recursive function afterwards. 

//For recursion, 4th loop (3 nested for loops) 
//crashes when it hits 15 or higher.


#include <iostream>

using namespace std;

void fcn(int, int&, int&); // recursive
void fcn(int, int&); //normal
void loop1(int, int&, int&);
void loop2(int, int&, int&, int&);
void loop3(int, int&, int&, int&);
void loop4(int, int&, int&, int&, int&);

int main()
{

	
	
	cout << "Iterative: Enter a value for n (0 to stop): ";
	int n;
	cin >> n;
	//Normal loop through
	
	do{

		
		
		//code 1 - I think will be n
		int count = 0;
		for(int i = 0; i < n; i++)
		{
			count++;
		}
	
		cout << "Code 1: count = " << count << endl;
	
		//code 2 - I think will be O((n^2) *2)
		count = 0;
		for(int i = 0; i < 2*n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				count++;
			}
		}
		cout << "Code 2: count = " << count << endl;
	
		//code 3 - calls a function: 
		count = 0;
		for(int i = 0; i < n; i++)
		{
			fcn(n, count);
		}
		cout << "Code 3: count = " << count << endl;
	
		//code 4 - O(n^4)
		count = 0;
		for(int i = 0; i < n * n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				for(int k = 0; k < 3 * n; k++)
				{
					count++;
				}
			}
		}
		cout << "Code 4: count = " << count << endl;
	
		cout << "Iterative: Enter a value for n (0 to stop): ";
		//int n;
		cin >> n;
	
	}while(n != 0);
	
	
	//Recursive Loop Through
	
	//used different counts to keep track of the iterations and 
	//variable counts that would normlaly be used in a for loop
	
	//I passed the count variables by reference to keep count despite all 
	//the different function calls
	cout << "Recursive: Enter a value for n (0 to stop): ";
	int nm;
	cin >> nm;
	
	do{	

		int num_of_ite1 = 0;
	
		int i_count1 = 0;
	
		loop1(nm, i_count1, num_of_ite1);
		cout << "Recursive Code 1: count = " << num_of_ite1 << endl;
	
	
		int num_of_ite2 = 0;
		int i_count2 = 0;
		int j_count2 = 0;
		loop2(nm, i_count2, j_count2, num_of_ite2);
		cout << "Recursive Code 2: count = " << num_of_ite2 << endl;
	
	
		int num_of_ite3 = 0;
		int i_count3 = 0;
		int i_foo_count3 = 0;
		loop3(nm, i_count3, i_foo_count3, num_of_ite3);
		cout << "Recursive Code 3: count = " << num_of_ite3 << endl;
	
	
		int num_of_ite4 = 0;
		int i_count4 = 0;
		int j_count4 = 0;
		int k_count4 = 0;
		
		if(nm > 14)
		{
			cout << "\n" << nm << " is too large, program will crash." << endl;
			cout << "Changed n to 14, the furthest point" << endl;
			cout << "to where the program will not crash.\n" << endl;
			nm = 14;
		}
		
		// will crash if it hits 15 or higher
		loop4(nm, i_count4, j_count4, k_count4, num_of_ite4); 
		cout << "Recursive Code 4: count = " << num_of_ite4 << endl;
		
		cout << "Recursive: Enter a value for n (0 to stop): ";
		cin >> nm;
		//int nm;
	}while(nm != 0);
	
	
	return 0;
}


//part of normal looping

void fcn(int n , int &count)
{
	int i;
	for(i = 0; i < n; i++)
	{
		count++;
	}
}



void fcn(int n , int &i_foo_count3, int &iteration3)
{
	if(i_foo_count3 < n)
	{
		i_foo_count3 += 1;
		iteration3 += 1;
		fcn(n, i_foo_count3, iteration3);
	}
	return;
}



void loop1(int n,int & i_count, int &iteration1)
{
	if(i_count < n)
	{
		i_count += 1;
		iteration1 += 1;
		loop1(n, i_count,iteration1);
	}
	else
	{
		return;
	}

}
void loop2(int n, int &i_count2, int &j_count2, int &iteration2)
{

	if(i_count2 < n*2)
	{
		if(j_count2 < n) // inner for loop
		{
			j_count2 += 1;
			iteration2 += 1;
			loop2(n, i_count2, j_count2, iteration2);
			//i_count += 1;
		}
		else if(i_count2 < n*2) // outer for loop
		{
			j_count2 = 0;
			i_count2 += 1;
			loop2(n, i_count2, j_count2, iteration2);
		}
		else return;
	}
}


void loop3(int n, int &i_count3, int &i_foo_count3, int &iteration3)
{
	if(i_count3 < n)
	{
		i_count3 += 1;
		fcn(n, i_foo_count3, iteration3);
		i_foo_count3 = 0;
		
		loop3(n, i_count3, i_foo_count3, iteration3);
	}
	else return;
	
	
}



void loop4(int n, int &i_count4, int &j_count4, int &k_count4, int &iteration4)
{
	
	if(i_count4 < n*n)
	{
		if(j_count4 < n)
		{
			if(k_count4 < 3*n)
			{
				k_count4 += 1;
				iteration4 += 1;
				loop4(n, i_count4, j_count4, k_count4, iteration4);
			}
			else
			{
				k_count4 = 0;
				j_count4 += 1;
				//cout << iteration4 << endl;
				loop4(n, i_count4, j_count4, k_count4, iteration4);
			}
		}
		else 
		{
			k_count4 = 0;
			j_count4 = 0;
			i_count4 += 1;
			loop4(n, i_count4, j_count4, k_count4, iteration4);
		}
	}
	else return;
	
	
	//~ for(int i = 0; i < n*n; i++)
	//~ {
		//~ for(int j = 0; j < n; j++)
		//~ {
			//~ for(int k = 0; k < 3*n; k++)
			//~ {
				
			//~ }
		//~ }
	//~ }
	
}




