//#include <stdio.h>
//
//int sorted[8]; // ���ĵ� �迭
//
//void merge(int *data, int start, int mid, int end) {
//	int i = start;
//	int j = mid + 1;
//	int k = start;
//
//	while (i <= mid && j <= end) {
//		if (data[i] <= data[j]) {
//			sorted[k] = data[i];
//			i++;
//		}
//		else {
//			// data[i] > data[j]
//			sorted[k] = data[j];
//			j++;
//		}
//		k++;
//	}
//	if (i > mid) {
//		for (int t = j; t <= end; t++) {
//			sorted[k] = data[t];
//			k++;
//		}
//	}
//	else {
//		for (int t = i; t <= mid; t++) {
//			sorted[k] = data[t];
//			k++;
//		}
//	}
//
//	// ���ĵ� �迭�� ����
//	for (int t = start; t <= end; t++) {
//		data[t] = sorted[t];
//	}
//}
//
//void merge_sort(int *data, int start, int end) {
//	if (start < end) {
//		int mid = (start + end) / 2;
//		merge_sort(data, start, mid); // ���� ���� 
//		merge_sort(data, mid + 1, end); // ���� ���� 
//		merge(data, start, mid, end);
//	}
//}
//
//int main(void) {
//
//	int data[8] = { 3, 6, 7, 1, 2, 4, 8, 5 };
//
//	merge_sort(data, 0, 7);
//
//	// ��� Ȯ��
//	for (int i = 0; i<8; i++) {
//		printf("%d ", data[i]);
//	}
//	return 0;
//}
