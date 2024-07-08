#include <iostream>

using namespace std;


// int MySwapValue(int i, int j)
// {
// 	int tmp = j;
// 	j = i ;
// 	i = tmp;
// 	return i,j ;
// }

void MySwapPtr(int* i, int* j)
{
	int tmp = *i;
	*i = *j;
	*j = tmp;
}

void MySwapRef(int& i, int& j)
{
	int tmp = i;
	i = j;
	j = tmp;
}


bool CheckSorted(int a, int b)
{
	if (a<=b){
		return true;
	}
	return false;
}

int main()
{
	// Swap
	{
		int a = 3;
		int b = 2;

		cout << a << " " << b << endl;

		// MySwapPtr(&a,&b);
		MySwapRef(a,b);

		cout << a << " " << b << endl;
	}


	// 정렬(sorting)
	{
		int arr[] = { 9, 3 };

		cout << arr[0] << " " << arr[1] << endl;
		cout << boolalpha;
		for(int i = 0; i<5; i++){
			for(int j = 0; j<5; j++){
				std::cout << i << " " << j << " " << CheckSorted(i,j) << std::endl;
			}
		}

		cout << arr[0] << " " << arr[1] << endl;
	}

	// 값과 상관 없이 항상 작은 값이 먼저 출력되게 하려면?
	// 두 값이 같을 때는 순서가 상관 없음 -> 큰 값이 먼저 출력되지 않게 하려면?
	{
		int arr[2];

		// TODO:
	}

	return 0; 
}
