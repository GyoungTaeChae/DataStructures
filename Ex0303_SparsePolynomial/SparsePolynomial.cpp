#include "SparsePolynomial.h"

#include <iostream>
#include <cassert>
#include <algorithm>
#include <cstring>

using namespace std;

// 새로운 항을 추가할 때 자기 위치를 찾아서 넣어줘야 함

// exp항이 이미 존재하면 거기에 coef를 더해준다.
// 존재하지 않는다면 exp 오름 차순으로 정렬된 상태로 새로 추가한다.
void SparsePolynomial::NewTerm(float coef, int exp)
{
	if (coef == 0.0f) return; // 0이면 추가하지 않음

	if (num_terms_ >= capacity_)
	{
		// capacity 증가 (num_terms는 일단 고정)
		capacity_ = capacity_ > 0 ? capacity_ * 2 : 1; // 2배씩 증가
		Term* new_term = new Term[capacity_];

		// 원래 가지고 있던 데이터 복사
		memcpy(new_term, terms_, sizeof(Term) * num_terms_);

		// 메모리 교체
		if (terms_) delete[] terms_;
		terms_ = new_term;
	}

	terms_[num_terms_].coef = coef;
	terms_[num_terms_].exp = exp;

	num_terms_++;
}
	// Term* terms_ = nullptr;
	// int capacity_ = 0;
	// int num_terms_ = 0;
float SparsePolynomial::Eval(float x)
{
	float temp = 0.0f;

	// TODO:
	for(int i = 0; i<capacity_; i++)
	{
		temp += terms_[i].coef * std::pow(x,terms_[i].exp);
	}

	return temp;
}

SparsePolynomial SparsePolynomial::Add(const SparsePolynomial& poly)
{
	SparsePolynomial temp;
	int index1 = 0;
	int index2 = 0;

	while((index1 < this->num_terms_) && (index2<poly.num_terms_))
	{
		if(this->terms_[index1].exp < poly.terms_[index2].exp)
		{
			temp.NewTerm(this->terms_[index1].coef,this->terms_[index1].exp);
			index1++;
		}
		else if(this->terms_[index1].exp > poly.terms_[index2].exp)
		{
			temp.NewTerm(poly.terms_[index2].coef,poly.terms_[index2].exp);
			index2++;
		}
		else 
		{
			temp.NewTerm((this->terms_[index1].coef+poly.terms_[index2].coef),this->terms_[index1].exp);
			index1++;
			index2++;
		}
	}
			// 남은 term들 추가
		for (; index1 < this->num_terms_; index1++)
		{
			temp.NewTerm(this->terms_[index1].coef,this->terms_[index1].exp);
		}

		for (; index2 < poly.num_terms_; index2++)
		{
			temp.NewTerm(poly.terms_[index2].coef,poly.terms_[index2].exp);
		}		

	return temp;
}
1
void SparsePolynomial::Print()
{
	bool is_first = true; // 더하기 출력시 확인용

	for (int i = 0; i < num_terms_; i++)
	{
		// 0이 아닌 항들만 골라서 출력할 필요가 없음

		if (!is_first)
			cout << " + "; // 첫 항이 아니라면 사이사이에 더하기 출력

		cout << terms_[i].coef;

		if (terms_[i].exp != 0) cout << "*" << "x^" << terms_[i].exp;

		is_first = false;
	}

	cout << endl;
}
