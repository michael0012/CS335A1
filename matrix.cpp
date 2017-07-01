/*
*Michael Medina
*Class CS 335
*Assignment 1
*matrix.cpp
*/
template<class Comparable>
matrix<Comparable>::matrix(): num_cols_{0},num_rows_{0}
{
	array_ = nullptr;
}// end default constructor

template<class Comparable>
matrix<Comparable>::~matrix()
{
	for(size_t i = 0; i < num_rows_ ; i++)
	{
		delete [] array_[i];
		array_[i] = nullptr;
	}
	if(num_rows_ > 0)
	{
		delete []array_;
		array_ = nullptr;
	}
	num_cols_ = 0;
	num_rows_ = 0;
	
}// end deconstructor

template<class Comparable>
matrix<Comparable>::matrix(const matrix & rhs)
{
	num_rows_ = rhs.num_rows_;
	num_cols_ = rhs.num_cols_;
	array_ = new Comparable*[num_rows_];
	for(size_t i = 0;  i < num_rows_ ; i++)
	{
		array_[i] = new Comparable[num_cols_];
		for(size_t j = 0 ; j < num_cols_ ; j++)
			array_[i][j] = rhs.array_[i][j];
	}// copies each row

} // end copy constructor

template<class Comparable>
matrix<Comparable>::matrix(matrix && rhs):array_{rhs.array_},num_rows_{rhs.num_rows_},num_cols_{rhs.num_cols_}
{
    rhs.num_rows_ = 0;
    rhs.num_cols_ = 0;
	rhs.array_ = nullptr;

} // end move constructor

template<class Comparable>
matrix<Comparable>& matrix<Comparable>::operator=(const matrix& rhs)
{
	if(this != &rhs )
	{
		matrix Copy = rhs;
		std::swap((*this),Copy);
	}

	return *this;

}// end equal overload lvalue

template<class Comparable>
matrix<Comparable>& matrix<Comparable>::operator=(matrix && rhs)
{

	std::swap(array_,rhs.array_);
	std::swap(num_rows_ ,rhs.num_rows_);
	std::swap(num_cols_ ,rhs.num_cols_);
	return *this;
}// end move equal overload

template<class Comparable>
size_t matrix<Comparable>::NumRows() const
{
	return num_rows_;
}// end number of row function

template<class Comparable>
size_t matrix<Comparable>::NumCols() const
{
	return num_cols_;
}// number of columns function

template<class Comparable>
void matrix<Comparable>::ReadMatrix()
{
    for(size_t i = 0; i < num_rows_ ; i++)
	{
		delete []array_[i];
		array_[i] = nullptr;
	}// deletes each pointer 
	delete []array_;// deletes the array of pointers

	size_t temp_col,temp_row;// will temporary holds inputs for number of rows and columns
	Comparable temp; // will temporary holds the input of the matrix 
	cout << "Enter the numbers of rows the matrix will have.\n";
	cin >> temp_row;
	cout <<"Enter the number of columns the matrix will have. \n";
	cin >> temp_col;
	num_rows_ = temp_row;
	num_cols_ = temp_col;

	array_ = new Comparable*[num_rows_];

	for(size_t i = 0;  i < num_rows_ ; i++)
	{
		cout << "Inputs for the "<< i+1 <<" row " <<endl;
		array_[i] = new Comparable[num_cols_]; 
		for(size_t j = 0 ; j < num_cols_ ; j++)
		{
			cout << "Enter for the "<< i+1 << " in the "<< j+1 << " column" <<endl;
			cin >> temp;
			array_[i][j] = temp;


		}//inputs for row,column 

	}//inputs for each row

}// end read matrix function

template<class Comparable>
ostream& operator<< (ostream& output,const matrix<Comparable>& rhs)
{
	for(size_t i = 0;  i < rhs.num_rows_ ; i++)
	{
		for(size_t j = 0 ; j < rhs.num_cols_ ; j++)
			output << (rhs.array_)[i][j] << ' ';
	
		output << endl;
	}

	return output;
}// ends the output overload of lvalue 

template<class Comparable>
ostream& operator<< (ostream& output,matrix<Comparable>&& rhs)
{
	for(size_t i = 0;  i < rhs.num_rows_ ; i++)
	{
		for(size_t j = 0 ; j < rhs.num_cols_ ; j++)
			output << (rhs.array_)[i][j] << ' ';

		output << endl;
	}

	return output;
}// ends the output overload of rvalue

template<class Comparable>
ostream& operator<< (ostream& output, vector<Comparable> rhs)
{

		for(auto i : rhs)
			output << i << ' ';



	return output;
}// end of overload the output of vector

template<class Comparable>
matrix<Comparable> matrix<Comparable>::operator+(const matrix<Comparable>& rhs) const
{
	matrix<Comparable> output;
	output.num_rows_ = std::move(rhs.num_rows_);
	output.num_cols_ = std::move(rhs.num_cols_);
	output.array_ = new Comparable*[output.num_rows_];


	for(size_t i = 0;  i < output.num_rows_ ; i++)
	{
		(output.array_)[i] = new Comparable[output.num_cols_];

		for(size_t j = 0 ; j < output.num_cols_ ; j++)
		{

			(output.array_)[i][j] =  array_[i][j] + (rhs.array_)[i][j];

		}

	}

	return output;
}// end addition function for lvalue

template<class Comparable>
matrix<Comparable> matrix<Comparable>::operator+(Comparable&& rhs) const
{
	matrix<Comparable> output;
	output.num_rows_ = num_rows_;
	output.num_cols_ = num_cols_;
	output.array_ = new Comparable*[output.num_rows_];


	for(size_t i = 0;  i < output.num_rows_ ; i++)
	{
		(output.array_)[i] = new Comparable[output.num_cols_];

		for(size_t j = 0 ; j < output.num_cols_ ; j++)
		{

			(output.array_)[i][j] =  array_[i][j] + rhs;

		}

	}

	return output;
}// end addition function for rvalue

template<class Comparable>
vector<Comparable> matrix<Comparable>::operator[](size_t index) const
{
	vector<Comparable> output;
	if(num_rows_ < index && index > 0)
		return output;
	for(size_t i = 0; i < num_cols_ ; i++ )
	{
		output.push_back(array_[index - 1][i]);
	}
	return output;
}// end overload access operator

template<class Comparable>
void matrix<Comparable>::Swap(matrix& input)
{
    matrix temp = std::move(input);
	input = std::move(*this);
	*this = std::move(temp);
}// end swap function
