//#include<stdio.h>
//#include <stdlib.h> 
//
//typedef struct {
//	int col;
//	int row;
//	int value;
//}MATRIX;
//
//void Compress(int**a, int row, int col, int cnt, MATRIX*mat) {
//	mat[0].row = row;
//	mat[0].col = col;
//	mat[0].value = cnt;
//	int idx = 1;
//
//	for (int n = 0; n < row; n++) {
//		for (int m = 0; m < col; m++) {
//			if (a[n][m] != 0) {
//				mat[idx].row = n;
//				mat[idx].col = m;
//				mat[idx].value = a[n][m];
//				idx++;
//			}
//		}
//	}
//}
//void Sum(MATRIX mat[], int k) {
//	int sum = 0;
//	int i = 0;
//	for (i = 1; i <= mat->value; i++) {
//		sum += mat[i].value;
//	}
//	printf("합계는 : %d\n", sum);
//	printf("%d\n", i);
//	double t = ((double)(i - 1) /(double)k * 100);
//	printf("%lf\n", t);
//
//}
//int main() {
//
//	int k;
//	printf("희소 행렬의 크기를 입력하세요 : ");
//	scanf("%d", &k);
//	int **a;
//	int z = k / 2; int t = 0;
//
//	a = (int**)malloc(sizeof(int*)*(z));
//	for (int i = 0; i < z; i++) {
//		a[i] = (int*)malloc(sizeof(int)*(z));
//	}
//	for (int i = 0; i < z; i++) {
//		for (int j = 0; j < z; j++) {
//			a[i][j] = rand() % 9;
//			if (a[i][j] != 0) {
//				t++;
//			}
//			if (t >(k *0.333)) {
//				a[i][j] = 0;
//			}
//		}
//	}
//	int cnt = 0;
//	for (int i = 0; i < z; i++) {
//		for (int j = 0; j < z; j++) {
//			if (a[i][j] != 0) {
//				cnt++;
//			}
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}
//
//	MATRIX*s = (MATRIX*)malloc(sizeof(MATRIX)*(cnt + 1));
//	Compress(a, z, z, cnt, s);
//	Sum(s, k);
//	free(a);
//	free(s);
//}