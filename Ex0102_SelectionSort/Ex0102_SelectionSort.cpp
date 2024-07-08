#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;

struct Element
{
	int key;
	char value;
};

bool CheckSorted(int* arr, int size)
{
	
	for (int i = 0; i<size-1; i++){
		if(arr[i]>arr[i+1]){return false;}
	}
	return true;
}
 
void Print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << endl;
}

void Print(Element* arr, int size)
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i].key << " ";
	std::cout << endl;

	for (int i = 0; i < size; i++)
		std::cout << arr[i].value << " ";
	std::cout << endl;
}

int main()
{
	// 3개 정렬
	{
		for (int k = 0; k < 3; k++)
			for (int j = 0; j < 3; j++)
				for (int i = 0; i < 3; i++) {

					int arr[3] = { i, j, k };
					int size = sizeof(arr) / sizeof(arr[0]);

					for (int e = 0; e < size; e++) {
						std::cout << arr[e] << " " << flush;
					}

					std::cout << " -> " << flush;

					
					for (int i = 0; i<size; i++){
						for (int j = i; j<size; j++){
							if (arr[i] > arr[j]) {std::swap(arr[i] , arr[j]);}
						}
					}

					for (int e = 0; e < size; e++) {
						std::cout << arr[e] << " " << flush;
					}

					std::cout << boolalpha;
					std::cout << CheckSorted(arr, size); // 정렬 되었나 확인
					std::cout << endl;
				}
	}

	return 0; // <- 실습용 임시

	// 5개라면? 더 많다면?
	{
		// 8 4 2 8 3
		// TODO: ???

		// 8 3 2 5 1 1 2 5 8 9
		// TODO: ???

		// 100개라면?
	}

	// 가장 작은 수 찾기
	{
		int arr[] = { 8, 3, 2, 5, 1, 1, 2, 5, 8, 9 }; // 임의의 숫자들, 변경 가능
		int size = sizeof(arr) / sizeof(arr[0]);

		assert(size > 0); // size가 1이상이라고 가정

		// TODO:

		// std::cout << "Minimum number is " << min_number << endl;
	}

	// 가장 작은 수의 인덱스 찾기
	{
		int arr[] = { 8, 3, 2, 5, 1, 1, 2, 5, 8, 9 };
		int size = sizeof(arr) / sizeof(arr[0]);

		assert(size > 0); // size가 1이상이라고 가정

		// TODO:

		//std::std::cout << "The index of min is " << min_index << endl;
		//std::cout << "Minimum number is " << arr[min_index] << endl;
	}

	// Selection Sort
	// 힌트: swap()
	{
		int arr[] = { 8, 3, 2, 5, 1, 1, 2, 5, 8, 9 };
		int size = sizeof(arr) / sizeof(arr[0]);

		int min_index;
		for (int i = 0; i < size - 1; i++)
		{

			// TODO:

			Print(arr, size);

			std::cout << boolalpha;
			std::cout << CheckSorted(arr, size);
			std::cout << endl;
		}
	}

	// 비교 횟수 세보기, 더 효율적인 방법은 없을까?
	// https://en.wikipedia.org/wiki/Sorting_algorithm
	{
		ofstream ofile("log.txt");
		for (int size = 1; size < 1000; size++)
		{
			int count = 0;
			int* arr = new int[size];
			for (int s = 0; s < size; s++) {
				arr[s] = size - s;
			}

			//TODO: count ++;

			//std::cout << size << ", " << count << endl;
			ofile << size << ", " << count << endl;
			// Print(arr, size);

			delete[] arr;
		}

		ofile.close();
	}

	// [2, 2, 1]
	// [1, 2, 2] // 첫 2가 마지막으로 이동

	// 안정성 확인(unstable)
	{
		Element arr[] = { {2, 'a'}, {2, 'b'}, {1, 'c'} };
		int size = sizeof(arr) / sizeof(arr[0]);

		Print(arr, size); // arr이 Element의 배열

		// TODO:

		Print(arr, size); // arr이 Element의 배열
	}
}
