﻿#include <iostream>
#include <cassert>
#include <algorithm> // swap

using namespace std;

int Sum(int* arr, int n)
{
	int sum = 0;

	for (int i = 0; i < n; i++)
		sum += arr[i];

	return sum;
}

int RecurSum(int* arr, int n)
{
	if (n==0){return 0;}
	else {return RecurSum(arr,n-1)+n;}
}

int main()
{
	// Sum vs RecurSum

	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	// cout << Sum(arr, n) << endl;
	cout << RecurSum(arr, n) << endl;

	return 0;
}
