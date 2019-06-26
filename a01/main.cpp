#include <iostream>
#include "matrixType.h"

//void multiplyMatrix(matrixType&, matrixType&, matrixType&);

using namespace std;

int main() // ASK!!!- not entering 0 size?
{
	//store and build matrix #1
	int rows1, cols1;
	cin >> rows1;
	cin >> cols1;
	
	matrixType <int>matrix1(rows1, cols1);
	
	//store and build matrix #2
	int rows2, cols2;
	cin >> rows2;
	cin >> cols2;
	
	matrixType <int>matrix2(rows2, cols2);
	

	cout << "\n\n\n Matrix 1: " << endl;
	matrix1.printMatrix();
	
	cout << "\n\n\n Matrix 2: " << endl;
	matrix2.printMatrix();
	
	//matrixType <int>matrix3(rows1, cols1, 0);
	
	
	
	//create 3rd matrix and fill values
	if(rows1 == rows2 && cols1 == cols2) // same size? - add/subtract
	{
		matrixType<int> matrix3(rows1, cols1, 0);
		matrixType<int> matrix5(rows1,cols1,0);
		 
		matrix3 = matrix1 + matrix2;
		
		matrix5 = matrix1 + matrix2;
		
		matrix3.printMatrix();
		matrix5.printMatrix();
		
	}

	if(rows2 == cols1) // multiplies new matrix
	{
		matrixType<int> matrix4(rows1, cols2, 0); //will call constructor 
													//that doesnt ask for input
		matrix4 = (matrix1 * matrix2);
		matrix4.printMatrix();
		
	}
	
	
	//cout << "\n \n \n \n \n" << endl;
	//matrix1.printMatrix(); 
	//cout << endl;
	//matrix3.printMatrix();
	
	return 0;
}






