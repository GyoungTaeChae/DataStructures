#pragma once

#include "Queue.h"

#include <cassert>
#include <iostream>
#include <iomanip>

// Double Ended Queue (덱, dequeue와 구분)
template<typename T>
class Deque : public Queue<T>
{

	typedef Queue<T> Base;

public:
	Deque(int capacity)
		: Queue<T>(capacity)
	{
	}

	T& Front()
	{
		return Base::Front();
	}

	T& Back()
	{
		return Base::Rear();
	}

	void PushFront(const T& item)
	{
		if (Base::IsFull())
			Base::Resize();

		Base::queue_[Base::front_] = item;
		Base::front_ = (Base::front_ -1 +Base::capacity_) % Base::capacity_;
		// TODO:
	}

	void PushBack(const T& item)
	{
		Base::Enqueue(item);
	}

	void PopFront()
	{
		Base::Dequeue();
	}

	void PopBack()
	{
		assert(!Base::IsEmpty());
		// Base::rear_ = (Base::rear_+1)%Base::capacity_;
		// Base::queue_[Base::rear_] = item;
		// TODO:
		Base::rear_ = (Base::rear_ -1 +Base::capacity_) % Base::capacity_;
	}

private:
	// Queue와 동일
	// T* queue_; // array for queue elements
	// int front_ = 0; // 시작 인덱스보다 하나 작은 값
	// int rear_ = 0; // 마지막 인덱스 (첫 값은 1에 추가)
	// int capacity_; // 빈 칸을 하나 둬야 하기 때문에 필요 메모리는 최대 저장량 + 1
	// bool print_debug_ = false;
};
