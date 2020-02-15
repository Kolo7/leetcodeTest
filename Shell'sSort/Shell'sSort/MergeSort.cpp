#include <iostream>

/*
	从left到right都取到
*/
void mergeSort(int arr[], int left, int right) {
	if (left>=right)
	{
		return;
	}
	int mid = (left + right) / 2;
	if (mid >= left)
	{
		mergeSort(arr, left, mid);
	}
	if (right > mid)
	{
		mergeSort(arr, mid + 1, right);
	}
	int* newArr = (int*)malloc((right - left + 1) * sizeof(int));
	int p1 = left, p2 = mid+1,p3=0;
	while (p1<=mid&&p2<=right)
	{
		newArr[p3++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
	}
	while (p1<=mid)
	{
		newArr[p3++] = arr[p1++];
	}

	while (p2<=right)
	{
		newArr[p3++] = arr[p2++];
	}
	p3 = 0;
	for (int i = left; i <= right; i++)
	{
		arr[i] = newArr[p3++];
	}
	free(newArr);
}
