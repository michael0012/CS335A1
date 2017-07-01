/*
*Michael Medina
*Class CS 335
*Assignment 1
*matrix.h
*/

#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>
#include<vector>
using namespace std;

template<class Comparable>
class matrix;

template<class Comparable>
ostream& operator<< (ostream& output,const matrix<Comparable>& rhs);

template<class Comparable>
ostream& operator<< (ostream& output,matrix<Comparable>&& rhs);

template<class Comparable>
ostream& operator<< (ostream& output,vector<Comparable> rhs);

template<class Comparable>
class matrix
{
	public:
		matrix();
		~matrix();
		matrix(const matrix& rhs);
		matrix(matrix && rhs);// points array to the same location as rhs
		matrix& operator=(const matrix& rhs);
		matrix& operator=(matrix&& rhs);
		size_t NumRows() const;
		size_t NumCols() const;
		void ReadMatrix(); // reads input from user
        friend ostream& operator<< <>(ostream& output,const matrix& rhs);
        friend ostream& operator<< <>(ostream& output,matrix&& rhs);
        friend ostream& operator<< <>(ostream& output, vector<Comparable> rhs);
		vector<Comparable> operator[](size_t index) const;
		matrix operator+(const matrix& rhs) const;
		matrix operator+(Comparable&& rhs) const;
		void Swap(matrix& input);
	private:
		size_t num_cols_;
		size_t num_rows_;
		Comparable **array_;
};

#include"matrix.cpp"

#endif
