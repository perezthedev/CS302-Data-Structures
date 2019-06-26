// I hit a wall with how to add the matrices
//decided to try and add them in the main instead



#include <iostream>
#include <iomanip>


using namespace std;

template <class myType>
struct nodeType{
	myType info;
	//int row, col;
	nodeType<myType> *up, *down, *left, *right;
};

template <class myType>
class matrixType{
	
	public:
		//matrixType();
		matrixType(int, int);
		matrixType(int, int, int);
		~matrixType();
		//void insertInfo(matrixType);
		matrixType operator+(matrixType&);
		matrixType operator=(const matrixType&);
		//myType addMatrix(int, int);
		//myType addMatrices(matrixType<myType>&, matrixType<myType>&, matrixType<myType>&);
		matrixType<myType> addMatrix(nodeType<myType>*, nodeType<myType>*);
		matrixType<myType> subtractMatrix(matrixType, matrixType);
		matrixType<myType> operator*(matrixType&);
		//void multiplyCall();
		//matrixType<myType> multiplyMatrix(matrixType&, matrixType&, matrixType&);
		//matrixType<myType> multiplyMatrix(matrixType, matrixType);
		void multiplyMatrix();
		void printMatrix();

		

		
	
	private:
		nodeType<myType> *head;
		nodeType<myType> *current_row;
		nodeType<myType> *current_col;
		nodeType<myType> *current_node;
		nodeType<myType> *trailing_node;
		
		
		int col_size;
		int row_size; //don't leave this as an int in private part of class!!!


		
};

template <class myType>
matrixType<myType>::matrixType(int lrows, int lcols)
{
	
	//create matrix
	head = nullptr;
	current_col = nullptr;
	current_row = nullptr;
	current_node = nullptr;
	trailing_node = nullptr;
	col_size = lcols;
	row_size = lrows;
	
	for(int i = 0; i < lrows; i++)
	{
		current_col = current_row;

		for(int j = 0; j < lcols; j++)
		{
			nodeType<myType> * newNode;
			newNode = new nodeType<myType>;
			newNode -> up = nullptr;
			newNode -> down = nullptr;
			newNode -> left = nullptr;
			newNode -> right = nullptr;
			
			//create first node of matrix
			if(head == nullptr)
			{
				head = newNode;
				current_row = newNode;
				current_col = newNode;
				current_node = newNode;
				trailing_node = newNode;
				
				myType tempNum;
				cin >> tempNum;
				newNode -> info = tempNum;
			}
			//links left +cols
			else if(i == 0 && j > 0)
			{

				newNode -> left = current_col;
				current_col -> right = newNode;
				current_col = newNode;
				
				myType tempNum;
				cin >> tempNum;
				newNode -> info = tempNum;
				
			}
			//links up +rows // i might not be moving current col
			else if(i > 0 && j == 0)
			{
				newNode -> up = current_row;
				current_row -> down = newNode;
				trailing_node = newNode;
				current_row = newNode;
				
				myType tempNum;
				cin >> tempNum;
				newNode -> info = tempNum;
			}
			//links left and up
			else if(i > 0 && j > 0)
			{

				newNode -> left = trailing_node;
				trailing_node -> right = newNode;
				current_col = current_col -> right;
				newNode -> up = current_col;
				current_col -> down = newNode;
				trailing_node = newNode;

				myType tempNum;
				cin >> tempNum;
				newNode -> info = tempNum; 
			}
			
		}
	}
	current_node = head;
	current_row = head;
	current_col = head;
	trailing_node = head;
}


template <class myType>
matrixType<myType>::matrixType(int lrows, int lcols, int tempNum)
{
	//create matrix
	head = nullptr;
	current_col = nullptr;
	current_row = nullptr;
	current_node = nullptr;
	trailing_node = nullptr;
	col_size = lcols;
	row_size = lrows;
	
	for(int i = 0; i < lrows; i++)
	{
		current_col = current_row;
		
		for(int j = 0; j < lcols; j++)
		{
			nodeType<myType> * newNode;
			newNode = new nodeType<myType>;
			newNode -> up = nullptr;
			newNode -> down = nullptr;
			newNode -> left = nullptr;
			newNode -> right = nullptr;
			
			//create first node of matrix
			if(head == nullptr)
			{				
				head = newNode;
				current_row = newNode;
				current_col = newNode;
				current_node = newNode;
				trailing_node = newNode;
				
				newNode -> info = tempNum;
			}
			//links left +cols
			else if(i == 0 && j > 0)
			{

				newNode -> left = current_col;
				current_col -> right = newNode;
				current_col = newNode;
				
				newNode -> info = tempNum;
			}
			//links up +rows // i might not be moving current col
			else if(i > 0 && j == 0)
			{
				newNode -> up = current_row;
				current_row -> down = newNode;
				trailing_node = newNode;
				current_row = newNode;

				newNode -> info = tempNum;
			}
			//links left and up
			else if(i > 0 && j > 0)
			{

				newNode -> left = trailing_node;
				trailing_node -> right = newNode;
				current_col = current_col -> right;
				newNode -> up = current_col;
				current_col -> down = newNode;
				trailing_node = newNode;

				newNode -> info = tempNum; 
			}
			
		}
	}
	current_node = head;
	current_row = head;
	current_col = head;
	trailing_node = head;
	
	

}


template <class myType>
matrixType<myType>::~matrixType()
{
		head = nullptr;
		current_row = nullptr;
		current_col = nullptr;
		current_node = nullptr;
		trailing_node = nullptr;
}

template <class myType>
matrixType<myType> matrixType<myType>::operator+( matrixType& object2)
{				//* star goes there
	
	matrixType matrix3(row_size, col_size, 0);
	matrix3.addMatrix(this -> head, object2.head);
	
	return matrix3; //&matrix3
}

template <class myType>
matrixType<myType> matrixType<myType>::operator=(const matrixType& object_passed)
{
	
	if(this != &object_passed)
	{
		nodeType<myType> * temp1 = (this -> head);
		nodeType<myType> * object_point1 = (object_passed.head);
		nodeType<myType> * temp2;
		nodeType<myType> * object_point2;

		for(int i = 0; i < row_size; i++)
		{
			temp2 = temp1;
			object_point2 = object_point1;
			
			for(int j = 0; j < col_size; j++)
			{
				temp2 -> info = object_point2 -> info;
				if((temp2 -> right) != nullptr)
				{
					temp2 = temp2 -> right;
					object_point2 =  object_point2 -> right;
				}
			}
			
			if(temp1 -> down != nullptr)
			{
				temp1 = temp1 -> down;
				object_point1 = object_point1 -> down;
			}
		}
	}
	
	return *this;
}


template<class myType>
matrixType<myType> matrixType<myType>::addMatrix(nodeType<myType>* headA, nodeType<myType>* headB)
{
	nodeType<myType> * temp = (this -> head); //what if temp -> head
	nodeType<myType> * matrixA = headA;
	nodeType<myType> * matrixB = headB;

	temp -> info = (matrixA -> info) + (matrixB -> info);
	
	if((matrixA -> down != nullptr) && (temp -> down -> info != 0))
	{
		matrixA = matrixA -> down;
		matrixB = matrixB -> down;
		temp = temp -> down;
		
		addMatrix(matrixA, matrixB);
		
		matrixA = matrixA -> up;
		matrixB = matrixB -> up;
		temp = temp -> up;
		
		
	}
	
	if(matrixA -> right != nullptr)
	{
		matrixA = matrixA -> right;
		matrixB = matrixB -> right;
		temp  = (this -> head);
		temp = temp -> right;
		
		addMatrix(matrixA, matrixB);
		
		matrixA = current_node -> left;
		matrixB = current_node -> left;
		temp = current_node -> left;
		
	}
	return *this;
}

template<class myType>
matrixType<myType> matrixType<myType>::operator*(matrixType& right_object)
{
	matrixType<myType> matrixC(this -> row_size, right_object.col_size, 0);
	nodeType<myType> * temp1 = (this-> head); //should set temp to point to 
											//first node of left hand matrix
											//is it this.head?
	nodeType<myType> * temp2 = (right_object.head);
	nodeType<myType> * temp3 = (matrixC.head);
	
	nodeType<myType> * trail1 = (this -> head);
	nodeType<myType> * trail2 = (right_object.head);
	nodeType<myType> * trail3 = (matrixC.head);
	

	//cout << "Inside operator * \n" << endl;
	
	for(int i = 0; i < (this -> row_size); i++)
	{	
		
		for(int j = 0; j < (right_object.col_size); j++)
		{
			
			for(int k = 0; k < (this -> col_size); k++)
			{
				//cout << "i: " << i << "j: " << j << "k: " << k << endl;
				(temp3 -> info) += ((temp1 -> info) * (temp2 -> info));
				
				
				if(temp2 -> down != nullptr)
				{
					
					temp2 = temp2 -> down;
					temp1 = temp1 -> right;
					
				}	
			}
			if(trail2 -> right != nullptr)
			{
				temp2 = trail2 -> right;
				trail2 = trail2 ->right;
				temp3 = temp3 -> right;
				temp1 = trail1;
			}
			else
			{
		
				temp1 = trail1 -> down;
				trail1 = trail1 -> down;
				temp2 = head;
				trail2 = head;
				temp3 = trail3 -> down;
			//temp3 = trail3 -> down;
				trail3 = trail3 -> down;
			}
		
			
		}
		if(trail1 -> down != nullptr)
			{
				temp1 = trail1 -> down;
				trail1 = trail1 -> down;
			}
	}
		
	return matrixC;
}


template<class myType>
void matrixType<myType>::printMatrix()
{
	nodeType<myType> * temp1 = (this -> head);
	nodeType<myType> * temp2;// = (this -> head);
	
	cout << setw(2) << row_size << "x" << col_size << " Matrix" << endl;
	string stars;
	stars.append(50,'-');
	cout << stars << endl;
	for(int i = 0; i < row_size; i++)
	{
		temp2 = temp1;
		
		for(int j = 0; j < col_size;j++)
		{
			cout << setw(5) << (temp2 -> info);
			if(temp2 -> right != nullptr)
			{
				temp2 = temp2 -> right;
			}
		}
		cout << endl;
		if((temp1 -> down) != nullptr)
		{
			temp1 = temp1 -> down;
		}
	}

}





