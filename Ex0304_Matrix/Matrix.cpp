#include "Matrix.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

Matrix::Matrix(int num_rows, int num_cols) : num_rows_(num_rows), num_cols_(num_cols)

{
	// this->num_rows_ = num_rows;
	// this->num_cols_ = num_cols;
	values_ = new float[num_rows * num_cols]{0.0f};

}

Matrix::Matrix(const Matrix& b)
{
	values_ = new float[b.num_rows_ * b.num_cols_];
	num_rows_ = b.num_rows_;
	num_cols_ = b.num_cols_;

	for(int i = 0; i< num_cols_*num_rows_; i++ )
	{
		values_[i] = b.values_[i];
	}
	
}

Matrix::~Matrix()
{
	// TODO:
	if (values_) delete[] values_;
}

void Matrix::SetValue(int row, int col, float value)
{
	values_[num_cols_*row + col] = value;

}

float Matrix::GetValue(int row, int col) const // 맨 뒤의 const는 함수 안에서 멤버 변수의 값을 바꾸지 않겠다는 의미
{
	//TODO:
	return values_[num_cols_*row + col]; 
}

Matrix Matrix::Transpose()
{
	Matrix temp(num_cols_, num_rows_); // num_cols_, num_rows_ 순서 주의

	// TODO:
	for ( int r = 0; r< num_rows_; r++)
		for (int c = 0; c< num_cols_; c++)
			temp.SetValue(c,r,GetValue(r,c));

	return temp;
}

Matrix Matrix::Add(const Matrix& b)
{
	assert(b.num_cols_ == num_cols_);
	assert(b.num_rows_ == num_rows_);

	Matrix temp(num_rows_, num_cols_);

	// TODO:
	for ( int r = 0; r< num_rows_; r++)
		for (int c = 0; c< num_cols_; c++)
		{
			temp.SetValue(r,c,this->GetValue(r,c)+b.GetValue(r,c));
		}
	
	return temp;
}

void Matrix::Print()
{
	for (int r = 0; r < num_rows_; r++)
	{
		for (int c = 0; c < num_cols_; c++)
			cout << GetValue(r, c) << " ";

		cout << endl;
	}
}
