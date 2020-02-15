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
		// �����ɨ�裨�����ұ߻����ҵ������ߣ�
		while (i <= r && arr[i] < p)
			i++;
		// ͬ�ϣ�����ߣ���С�ߣ�
		while (j >= l+1 && arr[j] > p)
			j--;
		// ����Ƿ��Ѿ�������
		if (i>j)
			break;
		std::swap(arr[i], arr[j]);
		i++;
		j--;
	}
	// ��������Ԫ�ز��뵽����С��λ�ã���������ڵĻ�j��������Լ�Ҳ�͵��ڲ���
	std::swap(arr[l], arr[j]);
	return j;
}