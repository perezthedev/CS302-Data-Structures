//Ryan
//CS 302 Section 1007

//Assignment # 5
//Quick Sort & Merge Sort

//Input: a file with different chars and no spaces
//Output: The original list and the 3 different sorts


#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cctype>

using namespace std;

int global_count = 0;

void mergeSort(char[], int, int);
void merge(char[], int, int, int);
void recQuickSort(char[], int, int);
int partition(char[], int, int);
void swap(char[], int, int);
void printArray(char[], int);
void combQuickSort(char[], int, int);
int combPartition(char[], int, int);


int main()
{
	string og_line;
	cin >> og_line;
	
	int line_length = static_cast<int>(og_line.length());
	
	//one for merge one for quick one for combination
	char arr1[line_length] = {0};
	char arr2[line_length] = {0};
	char arr3[line_length] = {0};
	
	for(int i = 0; i < line_length; i++) //copy
	{
		arr1[i] = og_line[i];
		arr2[i] = og_line[i];
		arr3[i] = og_line[i];
	}
	
	//call sort functions and print
	
	cout << "Original Line: " << endl;
	printArray(arr1, line_length);
	
	
	mergeSort(arr1, 0, line_length - 1);
	cout << "Merge Sort: " << endl;
	printArray(arr1, line_length);
	cout << "count = " << global_count << endl;
	
	global_count = 0;
	recQuickSort(arr2, 0, line_length-1);
	cout << "Quick Sort: " << endl;
	printArray(arr2, line_length);
	cout << "count = " << global_count << endl;
	
	global_count = 0;
	combQuickSort(arr3, 0, line_length-1);
	cout << "Combination Sort: " << endl;
	printArray(arr3, line_length);
	cout << "count = " << global_count << endl;
	
	
	return 0;
}

void mergeSort(char l_line[], int left, int right)
{
	if(left < right)
	{
		int middle = left + (right-left)/2; // avoids potential overflow 
											//same as (l+r)/2

		mergeSort(l_line, left, middle);
		mergeSort(l_line, middle+1, right);
		
		merge(l_line, left, middle, right);
	}
}

//normal merge function used with recursive merge sort
void merge(char l_line[], int left, int middle, int right)
{
	
	//int i, j, k;
	int num1 = middle - left + 1;
	int num2 = right - middle;
	
	int L[num1], R[num2];
	
	//create two temp arrays
	for(int i = 0; i < num1; i++)
	{
		L[i] = l_line[left + i];
	}
	
	for(int j = 0; j < num2; j++)
	{
		R[j] = l_line[middle + 1 + j];
	}
	
	int i = 0, j = 0;
	int k = left;
	
	//merge the arrays into l_local
	while(i < num1 && j < num2)
	{
		if(toupper(L[i]) <=   toupper(R[j])) // checks comparison
		{
			l_line[k] = L[i];
			i++;
		}
		else
		{
			l_line[k] = R[j];
			j++;
		}
		k++;
		global_count++;
	}
	
	//copies L[]
	while(i < num1)
	{
		l_line[k] = L[i];
		i++;
		k++;
	}
	
	//copies R[]
	while(i < num2)
	{
		l_line[k] = R[j];
		j++;
		k++;
	}
}

//normal quick sort
void recQuickSort(char l_arr[], int first, int last)
{
	int pivotLocation;
	
	if(first < last)
	{
		pivotLocation = partition(l_arr, first, last);
		recQuickSort(l_arr, first, pivotLocation - 1);
		recQuickSort(l_arr, pivotLocation + 1, last);
	}
	
}

//will find the pivot point by dividng in half
int partition(char l_arr[], int first, int last)
{
	char pivot;
	
	int index, smallIndex;
	
	swap(l_arr, first, (first+last)/2);
	
	pivot = l_arr[first];
	smallIndex = first;
	
	for(index = first + 1; index <= last; index++)
	{
		if(toupper(l_arr[index]) < toupper(pivot)) // makes comparison
		{
			smallIndex++;
			swap(l_arr, smallIndex, index);
			global_count++;
		}
	}
	swap(l_arr, first, smallIndex);
	
	return smallIndex;
}

//swaps within the same array using a temp
void swap(char l_arr[], int first, int second)
{
	char temp;
	temp = l_arr[first];
	l_arr[first] = l_arr[second];
	l_arr[second] = temp;
}

void printArray(char larr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << larr[i] << " ";
	}
	cout << endl << endl;
}

//Is a quickSort algorithm, but will then call MergeSort 
//when each sides sizes are less than 10
void combQuickSort(char l_arr[], int first, int last)
{
	int pivotLocation;
	
	
	if(first < last)
	{
		global_count++;
		pivotLocation = partition(l_arr, first, last);
		//global_count++;
		int left_size = (pivotLocation -1) - first;
		int right_size = last - pivotLocation + 1;
		
		//will call mergeSort after right side size is less than 10 and then 
		//also when right side size is less than 10
		if(left_size < 10)
		{
			mergeSort(l_arr, first, pivotLocation - 1);
		}
		else
		{
			combQuickSort(l_arr, first, pivotLocation - 1);
		}
		if(right_size < 10)
		{
			mergeSort(l_arr, pivotLocation + 1, last);
		}
		else
		{
			combQuickSort(l_arr, pivotLocation + 1, last);
		}
	}
	
}




