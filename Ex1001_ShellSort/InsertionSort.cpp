void InsertionSort(int arr[], int n)
{
	for (int i = 1; i < n; i += 1)
	{
		int key = arr[i];
		int j = i;
		for (; j > 0 && arr[j - 1] > key; j -= 1)
			arr[j] = arr[j - 1];
		arr[j] = key;
	}
}

int main()
{
	int arr[] = { 99, 83, 18, 66, 7, 54, 95, 86, 47, 69, 25, 28 };
	int n = sizeof(arr) / sizeof(arr[0]);

	InsertionSort(arr, n);

}
