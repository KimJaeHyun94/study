#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define EMPTY 0

struct node {
	int data;
	struct node * link;
};
typedef struct node Stack;

Stack * get_node() {//heap������ stack����� ����ü ����.
	Stack * tmp;
	tmp = (Stack *)malloc(sizeof(Stack));
	tmp->link = EMPTY;
	return tmp;
}
void push(Stack **top, int data) {
	Stack *tmp;
	tmp = *top;
	*top = get_node();
	(*top)->data = data;
	(*top)->link = tmp;
}
int Pop(Stack**top) {
	Stack* tmp;
	int num;
	tmp = *top;
	if (*top == EMPTY) {
		printf("empty data\n");
		return 0;
	}
	num = tmp->data;
	*top = (*top)->link;
	free(tmp);
	return num;
}

int main() {
	Stack*top = EMPTY;
	Stack*a=EMPTY;
	Stack*b = EMPTY;
	int count = 0;
	int num, n;

	while (1)
	{
		system("cls");
		printf("stack���α׷��Դϴ�\n");
		printf("1. push\n2. pop\n3. print_data\n4.����\n");
	    printf(">>>>>> : ");
		scanf("%d", &n);
		switch (n) {
		case 1:
			printf("���� �Է��Ͻÿ�: ");
			scanf("%d", &num);
			push(&top, num);
			push(&a, num);
			push(&b, num);
			count++;
			continue;
		case 2:
			printf("%d", Pop(&top));
			system("pause");
			continue;
		case 3:
			for (int i = 0; i < count; i++) {
				printf("%d\n", Pop(&a));
			}
			system("pause");
			continue;
		case 4:
			printf("��� ���� ���� �� ����\n");
			for (int i = 0; i < count; i++) {
				Sleep(500);
				printf("%d\n", Pop(&b));
			}
			return 0;
		}
	}
}
