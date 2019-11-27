#include<iostream>
#include<cstring>
using namespace std;

template<typename T>
void SelectSort(T*data, int arrsize) {
	int i, j;
	T temp;
	for (i = 0; i < arrsize - 1; i++) {
		for (j = i + 1; j < arrsize; j++) {
			if (data[i] < data[j]) {
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
	}
	for (i = 0; i < arrsize - 1; i++) {
		cout << data[i] << ' ';
	}
}
template<typename T>
void SelectSort2(T*data, int arrsize) {
	int i, j;
	T temp;
	for (i = 0; i < arrsize - 1; i++) {
		for (j = i + 1; j < arrsize; j++) {
			if (data[i] > data[j]) {
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
	}
	for (i = 0; i < arrsize - 1; i++) {
		cout << data[i] << ' ';
	}
}

int main() {
	int data[6] = { 1,5,7,8,9,4 };
	SelectSort(data, 6);
	SelectSort2(data, 6);
	char data2[4] = { 'a','c','e','d' };
	SelectSort(data2, 4);
	SelectSort2(data2, 6);
}