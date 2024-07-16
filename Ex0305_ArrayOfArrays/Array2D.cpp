#include "Array2D.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

	// float** arrays_ = nullptr; // 2중 포인터
	// int num_rows_ = 0;
	// int num_cols_ = 0;

Array2D::Array2D(int num_rows, int num_cols)
{
	// float *array = new float[len]; 
	// float **arrays_ = new float* [num_rows];
    arrays_ = new float* [num_rows]; // 포인터의 배열

    for (int r = 0; r < num_rows; r++)
    {
        arrays_[r] = new float[num_cols] ; // 값의 배열
    }
	this->num_cols_ = num_cols;
	this->num_rows_ = num_rows;

	for(int r = 0; r< num_rows_; r++)
		for (int c = 0; c<num_cols_;c++)
			arrays_[r][c] = 0.0f;
			
}
// 복사 생성자 (b를 복사)
Array2D::Array2D(const Array2D& b)
{
	this->num_rows_ = b.num_rows_;
	this->num_cols_ = b.num_cols_;

	for(int i = 0; i< num_rows_; i++)
	{
		for(int j = 0; j<num_cols_; j++)
		{
			arrays_[i][j] = *b.arrays_[i];
		}
	}

	//TODO:
}

Array2D::~Array2D()
{

	if (arrays_) delete[] arrays_;
	//TODO:
}

void Array2D::SetValue(int row, int col, float value)
{
			arrays_[row][col]= value; 
	// TODO:
}

float Array2D::GetValue(int row, int col) const // 맨 뒤의 const는 함수 안에서 멤버 변수의 값을 바꾸지 않겠다는 의미
{
	return arrays_[row][col];
	return 0.0f; // TODO:
}

Array2D Array2D::Transpose()
{
	Array2D temp(num_cols_, num_rows_); // num_cols_, num_rows_ 순서 주의

	for (int r = 0; r < num_rows_; r++)
		for (int c = 0; c < num_cols_; c++)
			temp.SetValue(c, r, GetValue(r, c));

	return temp;
}

Array2D Array2D::Add(const Array2D& b)
{
	assert(b.num_cols_ == num_cols_);
	assert(b.num_rows_ == num_rows_);

	Array2D temp(num_rows_, num_cols_);

	for (int r = 0; r < num_rows_; r++)
		for (int c = 0; c < num_cols_; c++)
			temp.SetValue(r, c, GetValue(r, c) + b.GetValue(r, c));

	return temp;
}

void Array2D::Print()
{
	for (int r = 0; r < num_rows_; r++)
	{
		for (int c = 0; c < num_cols_; c++)
			cout << GetValue(r, c) << " ";

		cout << endl;
	}
}
