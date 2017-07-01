/*
*Michael Medina
*Class CS 335
*TestMatrix.cpp
*Assignment 1
*/
#include"matrix.h"

void TestPart1();
void TestPart2();
void TestPart3();

int main()
{
	cout<< "This is test part 1 all inputs are integers."<<endl;
	TestPart1();
	cout<<"This is test part 2 all inputs are strings."<<endl;
	TestPart2();
	cout << "This is test part 3 all inputs are type double."<<endl;
	TestPart3();
	return 0;
}

void TestPart1() 
{
    matrix<int> a, b; //Two empty matrices are created
    cout << (a.NumRows()) << " "<< (a.NumCols()) << endl; // yields 0 0
    a.ReadMatrix(); // User provides number of rows, columns and matrix values.
    cout << a << endl; // Output should be what user entered.
    b.ReadMatrix();
    cout << b << endl;
    a = b; // Should call the copy assignment operator for a.
    cout << a << endl;
    matrix<int> c = b; // Should call the copy constructor for a.
    cout << c << endl;
    matrix<int> d = std::move(c); // Move constructor for d.
    cout << d << endl;
    a = std::move(d); // Move assignment operator for a.
    cout << a << endl;
} // Destructors will be called.

void TestPart2()
{
	matrix<string> a, b;
	a.ReadMatrix(); // User provides input for matrix a.
	cout << a << endl;
	b.ReadMatrix(); // User provides input for matrix b.
	cout << b << endl;
	cout << a + b << endl; // Matrices should have same size.
	// The default + operator for strings
	// will be used.
	matrix<string> d = a + b;
	cout << d <<endl;
	cout << d + "hi_there"<<endl;
	cout << a[1] << endl; // Should print the first row of a.
	cout << b[2] << endl; // Should be print the second row of b.
	// Note, that the [] operator should return
	// a vector object.
} // End of TestPart2.

void TestPart3()
{
	matrix<double> a, b;
	a.ReadMatrix(); // User provides input for matrix a.
	cout << a << endl;
	b.ReadMatrix(); // User provides input for matrix b.
	cout << b << endl;
	a.Swap(b);
	cout << a << endl;
	cout << b << endl;
} // End of TestPart3.
