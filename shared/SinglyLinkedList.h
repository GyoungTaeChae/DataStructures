#pragma once

#include <cassert>
#include <stdint.h>

template<typename T>
class SinglyLinkedList
{
public:
	struct Node
	{
		T item = T();
		Node* next = nullptr;
	};

	SinglyLinkedList()
	{
	}

	SinglyLinkedList(const SinglyLinkedList& list)
	{
		Node* current = list.first_;
		while(current)
		{
			this->PushBack(current->item);
			current = current->next;
		}
	}

	~SinglyLinkedList()
	{
		Clear();
	}

	void Clear() // 모두 지워야(delete) 합니다.
	{
		// TODO: 모두 삭제
	}

	bool IsEmpty()
	{
		return first_ == nullptr;
	}

	int Size()
	{
		int size = 1;
		Node* current = first_;

		while (current->next != nullptr)
		{
			size++;
			current = current->next ;
		}
		
		return size;
	}

	T Front()
	{
		assert(first_);

		return T(); // TODO: 수정
	}

	T Back()
	{
		assert(first_);

		return T(); // TODO: 수정
	}

	Node* Find(T item)
	{
		// TODO: item이 동일한 노드 포인터 반환
		Node* current = first_;

		while(current)
		{
			if(current->item == item)
				return current;	

			current = current->next;
		}
		return current;
	}

	void InsertBack(Node* node, T item)
	{
		// TODO:
		Node* new_node = new Node;
		new_node->item = item;
		new_node->next = node->next;
		node->next = new_node;
		
	}

	void Remove(Node* n)
	{
		assert(first_);

		// 하나 앞의 노드를 찾아야 합니다.
		// TODO:
		Node* prev = first_;
		while (prev->next)
		{
			if(prev->next == n)
				break;
			prev = prev->next;
		}
		prev->next = n->next;
		delete n;
	}

	void PushFront(T item)
	{
		
		if(first_ == nullptr)
		{
			first_ = new Node();
			first_->item = item;
        	first_->next = nullptr;
		}
		else
		{
			Node* new_node = new Node();
			new_node->item = item;
			new_node->next = first_;
			first_ = new_node;
		}
	}

	void PushBack(T item)
	{
		if (first_ == nullptr)
		{
			first_ = new Node();
			first_->item = item;
        	first_->next = nullptr;
		}
		else
		{
			Node* new_node = new Node();
			new_node->item = item;
			new_node->next = nullptr;
			
			Node* current = first_;
			while(current->next!=nullptr)
			{
				current = current->next;
			}
			current->next = new_node;
		}
	}

	void PopFront()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopFront()" << endl;
			return;
		}

		assert(first_);
		
		
		Node* temp = first_;
		first_ = first_->next;

		delete temp;
		// TODO: 메모리 삭제
	}

	void PopBack()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopBack()" << endl;
			return;
		}

		// 맨 뒤에서 하나 앞의 노드를 찾아야 합니다.

		assert(first_);
		Node* current;

		while(current->next != nullptr)
		{
			current = current->next;
		}
		
		Node* temp = current->next;
		current->next = nullptr;
		delete temp;
		// TODO: 메모리 삭제
	}

	void Reverse()
	{
		Node* current = first_;
		Node* previous = nullptr;

		while(current != nullptr)
		{
			Node* temp = previous; 
			previous = current; 
			current = current->next;
			previous->next = temp;

		}	
		first_ = previous;

	}




	void SetPrintDebug(bool flag)
	{
		print_debug_ = flag;
	}

	void Print()
	{
		using namespace std;

		Node* current = first_;

		if (IsEmpty())
			cout << "Empty" << endl;
		else
		{
			cout << "Size = " << Size() << " ";

			while (current)
			{
				if (print_debug_)
				{
					//cout << "[" << current << ", " << current->item << ", " << current->next << "]";

					// 주소를 짧은 정수로 출력 (앞 부분은 대부분 동일하기때문에 뒷부분만 출력)
					cout << "[" << reinterpret_cast<uintptr_t>(current) % 100000 << ", "
						<< current->item << ", "
						<< reinterpret_cast<uintptr_t>(current->next) % 100000 << "]";
				}
				else
				{
					cout << current->item;
				}

				if (current->next)
					cout << " -> ";
				else
					cout << " -> NULL";

				current = current->next;
			}
			cout << endl;
		}
	}

protected:
	Node* first_ = nullptr;

	bool print_debug_ = false;
};