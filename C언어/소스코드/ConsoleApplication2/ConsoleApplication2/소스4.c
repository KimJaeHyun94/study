//#include<stdio.h>
//
//hanoi_tower(int n, char from, char tmp, char to) {
//	if (n == 1)
//	{
//		printf("���� 1�� %c���� %c�� �ű��\n", from, to);
//	}
//	else
//	{
//		hanoi_tower(n - 1, from, to, tmp);
//		printf("���� %d�� %c���� %c�� �ű��\n", n, from, to);
//		hanoi_tower(n - 1, from, to, tmp);
//	}
//}
//
//int main() {
//	hanoi_tower(4, 'A', 'B', 'C');
//}

//#include<stdio.h>
//#define SIZE 10
//
//int main() {
//	char ans1;
//	int ans2, i;
//	int seats[SIZE] = { 0 };
//
//	while (1) {
//		printf("�¼��� �����Ͻðڽ��ϱ�?(y�Ǵ�n)");
//		scanf("%c", &ans1);
//		if (ans1 == 'y') {
//			printf("-------------------------\n");
//			printf("1 2 3 4 5 6 7 8 9 10\n");
//			printf("-------------------------\n");
//
//			for (i = 0; i < SIZE; i++)
//			{
//				printf("  %d", seats[i]);
//			}
//				printf("\n");
//			
//
//			printf("�� ��° �¼��� �����Ͻðڽ��ϱ�");
//			scanf("%d", &ans2);
//			if (ans2 <= 0 || ans2 > SIZE) {
//				printf("1�� 10������ ���� �Է��Ͻÿ�\n");
//				continue;
//			}
//			if (seats[ans2 - 1] == 0)
//			{
//				seats[ans2 - 1] = 1;
//				printf("����Ǿ����ϴ�\n");
//			}
//			else
//				printf("�̹� ����� �ڸ��Դϴ�\n");
//		}
//		else if (ans1 == 'n')
//			return 0;
//	}
//}

//#include<stdio.h>
//#include<stdlib.h>
//void disp(char board[3][3]);
//void init_board(char board[][3]);
//int get(int player, char board[][3]);
//int main() {
//	char board[3][3];
//	int quit = 0;
//
//	init_board(board);
//	do {
//		disp(board);
//		quit = get(0, board);
//		disp(board);
//		quit = get(1, board);
//	} while (quit == 0);
//
//}
//void init_board(char board[][3]) {
//	int x, y;
//	for (x = 0; x < 3; x++)
//		for (y = 0; y < 3; y++)
//			board[x][y] = ' ';
//}
//int get(int player, char board[][3])
//{
//	int x, y, done = 0;
//	while (done != 1) {
//		printf("(x,y)��ǥ (���� -1,-1):");
//		scanf("%d %d", &x, &y);
//		if (x == -1 && y == -1) return 1;
//		if (board[x][y] == ' ')break;
//		else printf("�߸��� ��ġ�Դϴ�.\n");
//	}
//	if (player == 0) board[x][y] = 'X';
//	else board[x][y] = 'O';
//	return 0;
//}
//void disp(char board[3][3]) {
//	int i;
//	for (i = 0; i < 3; i++) {
//		printf("---|---|---\n");
//		printf("  %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//	}
//	printf("---|---|---\n");
//}

//#include<stdio.h>
//
//typedef struct student {
//	char name[20];
//	char juso[50];
//	char phone[20];
//	char point[50];
//}STUDENT;
//void func();
//void add_record(STUDENT *p, int count);
//void search_record(STUDENT *p, int count);
//void update_record(STUDENT *p, int count);
//void print(STUDENT *p, int count);
//int main() {
//	STUDENT p[50];
//	int select=0;
//	int count=0;
//	while (1)
//	{
//		func();
//		printf("�޴��� �Է��Ͻÿ� :");
//		scanf("%d", &select);
//
//		if (select == 1)
//		{
//			add_record(p,count);
//			count++;
//		}
//		else if (select == 2)
//		{
//			update_record(p,count);
//		}
//		else if (select == 3)
//		{
//			search_record(p,count);
//		}
//		else if (select == 4)
//		{
//			print(p, count);
//		}
//		else
//			break;
//	}
//}
//void func() {
//	printf("====================\n");
//	printf("1.�߰�\n2.����\n3.�˻�\n4.���\n5.����");
//	printf("\n====================\n");
//}
//
//void add_record(STUDENT *p,int count) {
//	printf("�̸� :");
//	scanf("%s", p[count].name);
//	printf("�ּ� :");
//	getchar();
//	gets(p[count].juso);
//	printf("�޴��� :");
//	scanf("%s", p[count].phone);
//	printf("Ư¡ :");
//	getchar();
//	scanf("%s", p[count].point);
//}
//
//void search_record(STUDENT *p,int count) {
//	char example[20];
//	printf("�̸��� �Է��Ͻÿ� :");
//	scanf("%s", &example);
//
//	for (int i = 0; i < count; i++) {
//		if (strcmp(example, p[i].name) == 0)
//		{
//			printf("�ּҴ� %s��\n", p[i].juso);
//		}
//		else
//			printf("ã�� ����� ���� �����ϴ�\n");
//	}
//}
//void update_record(STUDENT *p,int count) {
//	char example[20];
//	char change[20];
//	printf("�̸��� �Է��Ͻÿ� :");
//	scanf("%s", &example);
//	for (int i = 0; i < count; i++) {
//		if (strcmp(example, p[i].name) == 0)
//		{
//			printf("������ �̸��� �Է��Ͻÿ� :");
//			scanf("%s", &change);
//			strcpy(p[i].name, change);
//		}
//		else
//		{
//			printf("ã�� ����� �����ϴ�\n");
//		}
//	}
//}
//void print(STUDENT *p, int count) {
//	for (int i = 0; i < count; i++) {
//		printf("�̸� :%s\n", p[i].name);
//	}
//}

//#include <stdio.h>
//#include <string.h>
//#include <windows.h>
//#include <stdlib.h>
//#define NUM 100
//struct user {
//	char id[8];
//	char password[16];
//};
//int checkUser(struct user ** stu, char *inputId, char *inputPassword, int * num)
//{
//	int i;
//
//	for (i = 0; i<*num; i++) {
//		if (!strcmp(stu[i]->id, inputId))
//			if (!strcmp(stu[i]->password, inputPassword))
//				return 1;
//			else {
//				printf("Ʋ�Ƚ��ϴ�!!!\n");
//				return 0;
//			}
//	}
//	if (i == *num)
//		printf("��ϵ��� ���� ID �Դϴ�.\n");
//	return 0;
//}
//
//int addUser(struct user ** stu, char *inputID, char * inputPassword, int * num) {
//	int i;
//	if ((*num) != 0) {
//		for (i = 0; i < (*num); i++) {
//			if (!strcmp(stu[i]->id, inputID)) {
//				printf("��ϵ� ID �Դϴ�.\n");
//				return 0;
//			}
//		}
//	}
//	stu[*num] = (struct user *)malloc(sizeof(struct user));
//	strcpy(stu[*num]->id, inputID);
//	strcpy(stu[*num]->password, inputPassword);
//	(*num)++;
//	return 1;
//}
//int delUser(struct user ** stu, char *inputID, char * inputPassword, int * num) {
//	int i;
//	if (num != 0) {
//		for (i = 0; i < *num; i++) {
//			if (!strcmp(stu[i]->id, inputID)) {
//				free(stu[i]);
//				return 1;
//			}
//		}
//	}
//	return 0;
//}
//int main()
//{
//	struct user * stu[NUM] = { 0 };
//	int option, i, num = 0;
//	char inputID[8];
//	char inputPassword[16];
//	while (1) {
//		system("cls");
//		printf("���ϴ� ����� �����ϼ���.\n");
//		printf("1. �α׿� \n");
//		printf("2. ȸ�� ����\n");
//		printf("3. ȸ�� Ż��\n");
//		printf("4. ����\n");
//		printf("Select...");
//		scanf("%d", &option);
//		getchar();
//		if (option < 0 || option > 4)
//			continue;
//		switch (option) {
//		case 1:
//			printf("ID : ");
//			gets(inputID);
//			printf("Password : ");
//			gets(inputPassword);
//			if (!checkUser(stu, inputID, inputPassword, &num)) {
//				system("pause");
//				continue;
//			}
//			printf("������ ����߽��ϴ�.\n");
//			printf("�����մϴ�.\n");
//			system("pause");
//			break;
//		case 2:
//			printf("ID : ");
//			gets(inputID);
//			printf("Password : ");
//			gets(inputPassword);
//			if (addUser(stu, inputID, inputPassword, &num)) {
//				printf("\n��� ����\n");
//				system("pause");
//				continue;
//			}
//			printf("��� ����\n");
//			system("pause");
//			break;
//		case 3:
//			printf("ID : ");
//			gets(inputID);
//			printf("Password : ");
//			gets(inputPassword);
//			if (delUser(stu, inputID, inputPassword, &num)) {
//				printf("\nŻ�� ����\n");
//				system("pause");
//				continue;
//			}
//			printf("Ż�� ����\n");
//			system("pause");
//			break;
//		case 4:
//			return 0;
//		case 0:
//			for (i = 0; i<NUM; i++) {
//				if (stu[i]->id == NULL) {
//					printf("\n%3d ID: %s\n", i, stu[i]->id);
//					printf("    PW: %s\n", stu[i]->password);
//				}
//			}
//			system("pause");
//			break;
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#define EMPTY 0
//
//struct node {
//	int data;
//	struct node * link;
//};
//typedef struct node Stack;
//
//Stack * get_node(){    //heap������ stack����� ����ü ����.
//	Stack * tmp;
//	tmp=(Stack *)malloc(sizeof(Stack));
//	tmp->link=EMPTY;
//	return tmp;
//}
//void push(Stack **top, int data){
//	Stack *tmp;
//	tmp=*top;
//
//	*top=get_node();
//
//	(*top)->data=data;
//	(*top)->link=tmp;
//}
//void main () {
//	Stack * top=EMPTY;
//
//	push(&top, 10);
//	push(&top, 20);
//	push(&top, 30);
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <Windows.h>
//#define EMPTY 0
//
//struct node {
//	int data;
//	struct node * link;
//};
//typedef struct node Stack;
//
//Stack * get_node() {//heap������ stack����� ����ü ����.
//	Stack * tmp;
//	tmp = (Stack *)malloc(sizeof(Stack));
//	tmp->link = EMPTY;
//	return tmp;
//}
//void push(Stack **top, int data) {
//	Stack *tmp;
//	tmp = *top;
//	*top = get_node();
//	(*top)->data = data;
//	(*top)->link = tmp;
//}
//int Pop(Stack**top) {
//	Stack* tmp;
//	int num;
//	tmp = *top;
//	if (*top == EMPTY) {
//		printf("empty data\n");
//		return 0;
//	}
//	num = tmp->data;
//	*top = (*top)->link;
//	free(tmp);
//	return num;
//}
//
//int main() {
//	Stack*top = EMPTY;
//	Stack*a = EMPTY;
//	Stack*b = EMPTY;
//	int count = 0;
//	int num, n;
//
//	while (1)
//	{
//		system("cls");
//		printf("stack���α׷��Դϴ�\n");
//		printf("1. push\n2. pop\n3. print_data\n4.����\n");
//		printf(">>>>>> : ");
//		scanf("%d", &n);
//		switch (n) {
//		case 1:
//			printf("���� �Է��Ͻÿ�: ");
//			scanf("%d", &num);
//			push(&top, num);
//			push(&a, num);
//			push(&b, num);
//			count++;
//			continue;
//		case 2:
//			printf("%d", Pop(&top));
//			system("pause");
//			continue;
//		case 3:
//			for (int i = 0; i < count; i++) {
//				printf("%d\n", Pop(&a));
//			}
//			system("pause");
//			continue;
//		case 4:
//			printf("��� ���� ���� �� ����\n");
//			for (int i = 0; i < count; i++) {
//				Sleep(500);
//				printf("%d\n", Pop(&b));
//			}
//			return 0;
//		}
//	}
//}
