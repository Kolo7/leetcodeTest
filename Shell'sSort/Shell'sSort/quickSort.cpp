#include <iostream>

int partition(int arr[], int l, int r);

void quickSort(int arr[], int l, int r) {
	if (l >= r)
		return;
	int p = partition(arr, l, r);
	quickSort(arr, l, p - 1);
	quickSort(arr, p + 1, r);
}

int partition(int arr[], int l, int r) {
	int p = arr[l];
	int i = l + 1, j = r;
	while (i<=j) {
		// 从左边扫描（至最右边或者找到更大者）
		while (i <= r && arr[i] < p)
			i++;
		// 同上（最左边，更小者）
		while (j >= l+1 && arr[j] > p)
			j--;
		// 检查是否已经找完了
		if (i>j)
			break;
		std::swap(arr[i], arr[j]);
		i++;
		j--;
	}
	// 将待插入元素插入到比他小的位置，如果不存在的话j将会等于自己也就等于不换
	std::swap(arr[l], arr[j]);
	return j;
}