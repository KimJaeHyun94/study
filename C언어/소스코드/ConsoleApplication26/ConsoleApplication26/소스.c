//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//#include<windows.h>
//#define EMPTY 0
//
//typedef struct node {
//	char data;
//	struct node*llink, *rlink;
//}Tree;
////트리 출력 
//void Llink(Tree**root, int x, int y);
//void Rlink(Tree**root, int x, int y);
//void Allink(Tree**root, int x, int y);
////차수 구하기
//int GetDepth(Tree**root);
//int GetHeight(Tree**root);
////회전
//void LineUp(Tree**root);
//void LL(Tree**root);
//void RR(Tree**root);
//void RL(Tree**root);
//void LR(Tree**root);
//
//Tree*get_node() {
//	Tree*tmp;
//	tmp = (Tree*)malloc(sizeof(Tree));
//	tmp->llink = EMPTY;
//	tmp->rlink = EMPTY;
//	return tmp;
//}
//void gotoxy(int x, int y) {
//	COORD pos = { 2 * x,y };
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//}
//
//void InsertNode(Tree**root, char data) {
//	if ((*root) == EMPTY)
//	{
//		(*root) = get_node();
//		(*root)->data = data;
//	}
//	else if ((*root)->data > data) {
//		InsertNode(&(*root)->llink, data);
//	}
//	else if ((*root)->data < data) {
//		InsertNode(&(*root)->rlink, data);
//	}
//	else {
//		printf("같은 값이 이미 존재합니다\n");
//	}
//	LineUp(&(*root));
//}
//void LineUp(Tree**root) {
//	Tree*tmp = *root;
//	if (tmp == EMPTY) return;
//	while ((GetHeight(&(*root)) > 1))
//	{
//		GetHeight(&(*root)->llink) > 0 ?
//			LL(&(*root)) : LR(&(*root));
//	}
//	while ((GetHeight(&(*root)) < -1))
//	{
//		GetHeight(&(*root)->rlink) < 0 ?
//			RR(&(*root)) : RL(&(*root));
//	}
//	LineUp(&(*root)->llink);
//	LineUp(&(*root)->rlink);
//}
//void LL(Tree**root) {
//	Tree*tmp = (*root)->llink;
//	(*root)->llink = tmp->rlink;
//	tmp->rlink = (*root);
//	(*root) = tmp;
//}
//void RR(Tree**root) {
//	Tree*tmp = (*root)->rlink;
//	(*root)->rlink = tmp->llink;
//	tmp->llink = (*root);
//	(*root) = tmp;
//}
//void LR(Tree**root) {
//	RR(&(*root)->llink);
//	LL(&(*root));
//}
//void RL(Tree**root) {
//	LL(&(*root)->rlink);
//	RR(&(*root));
//}
//int GetDepth(Tree**root) {
//	{
//		if ((*root) == NULL)
//		{
//			return 0;
//		}
//	}
//	return max(GetDepth(&(*root)->llink), GetDepth(&(*root)->rlink)) + 1;
//}
//int GetHeight(Tree**root) {
//	return
//		GetDepth(&(*root)->llink) - GetDepth(&(*root)->rlink);
//}
//void PreOrder(Tree**root) {
//	printf("%c ", (*root)->data);
//	if ((*root)->llink != EMPTY) {
//		PreOrder(&(*root)->llink);
//	}
//	if ((*root)->rlink != EMPTY) {
//		PreOrder(&(*root)->rlink);
//	}
//}
//void InOrder(Tree**root) {
//	if ((*root)->llink != EMPTY) {
//		InOrder(&(*root)->llink);
//	}
//	printf("%c ", (*root)->data);
//	if ((*root)->rlink != EMPTY) {
//		InOrder(&(*root)->rlink);
//	}
//}
//void PostOrder(Tree**root) {
//	if ((*root)->llink != EMPTY) {
//		PostOrder(&(*root)->llink);
//	}
//	if ((*root)->rlink != EMPTY) {
//		PostOrder(&(*root)->rlink);
//	}
//	printf("%c ", (*root)->data);
//}
//void LevelOrder(Tree**root) {
//	Tree** Queue[100];
//	int front = 0, rear = 0;
//	if (*root) {
//		Queue[rear++] = *root;
//	}
//	while (*root != NULL && front != rear)
//	{
//		*root = Queue[front++];
//		printf("%c ", (*root)->data);
//		if ((*root)->llink) {
//			Queue[rear++] = (*root)->llink;
//		}
//		if ((*root)->rlink) {
//			Queue[rear++] = (*root)->rlink;
//		}
//	}
//}
//void Llink(Tree**root, int x, int y) {
//	Tree*tmp = *root;
//	if (tmp == EMPTY) return;
//	int depth = GetDepth(&(*root));
//	gotoxy(x -= depth, y += 2);
//	printf("%c", tmp->data);
//	if (tmp->llink&&tmp->rlink)
//	{
//		Allink(&tmp, x, y);
//	}
//	if (tmp->llink && !tmp->rlink)
//	{
//		Llink(&tmp->llink, x, y);
//	}
//	if (!tmp->llink&&tmp->rlink) {
//		Rlink(&tmp->rlink, x, y);
//	}
//}
//void Rlink(Tree**root, int x, int y) {
//	Tree*tmp = *root;
//	int depth = GetDepth(&(*root));
//	gotoxy(x += depth, y += 2);
//	printf("%c", tmp->data);
//	if (tmp == EMPTY) return;
//	if (tmp->llink&&tmp->rlink)
//	{
//		Allink(&tmp, x, y);
//	}
//	if (tmp->llink&&tmp->rlink)
//	{
//		Llink(&tmp->llink, x, y);
//	}
//	if (tmp->rlink && !tmp->llink) {
//		Rlink(&tmp->rlink, x, y);
//	}
//}
//void Allink(Tree**root, int x, int y) {
//	Tree*tmp = *root;
//	if (tmp == EMPTY) return;
//	int depth = GetDepth(&(*root));
//	gotoxy(x -= depth, y += 2);
//	printf("%c", tmp->llink->data);
//	gotoxy(x += 2 * depth, y);
//	printf("%c", tmp->rlink->data);
//	{
//		if (tmp->llink->llink&&tmp->llink->rlink)
//			Allink(&tmp->llink, x - 2 * depth, y);
//		if (!tmp->llink->llink&&tmp->llink->rlink)
//			Rlink(&tmp->llink->rlink, x - 2 * depth, y);
//		if (tmp->llink->llink && !tmp->llink->rlink)
//			Llink(&tmp->llink->llink, x - 2 * depth, y);
//		if (tmp->rlink->llink&&tmp->rlink->rlink)
//			Allink(&tmp->rlink, x, y);
//		if (!tmp->rlink->llink&&tmp->rlink->rlink)
//			Rlink(&tmp->rlink->rlink, x, y);
//		if (tmp->rlink->llink && !tmp->rlink->rlink)
//			Llink(&tmp->rlink->llink, x, y);
//	}
//}
//void Print_data(Tree**root) {
//	Tree*tmp = *root;
//	int depth = GetDepth(&(*root));
//	if (tmp == EMPTY)return;
//	int x = 100; int y = 0;
//	gotoxy(x -= 50, y);
//	printf("%c", tmp->data);
//	if ((tmp->llink&&tmp->rlink)) {
//		Allink(&tmp, x, y);
//	}
//	else if (tmp->llink && !tmp->rlink) {
//		Llink(&tmp->llink, x, y);
//	}
//	else if (!tmp->llink && tmp->rlink)
//	{
//		Rlink(&tmp->rlink, x, y);
//	}
//	gotoxy(0, 20);
//}
//int main() {
//	Tree*root = EMPTY;
//	char num; int n;
//	char data;
//	char delete;  
//	char str[50];
//	while (1) {
//		system("cls");
//		Print_data(&root);
//		printf("AVL TREE 프로그램입니다\n");
//		printf("1. data 추가\n2. data 출력\n3. 종료\n");
//		printf(">>>>>> : ");
//		scanf("%d", &n);
//		if (n < 0 || n > 5)
//			continue;
//		switch (n) {
//		case 1:
//			getchar();
//			printf("산술식을 입력하세요 :");
//			gets(str);
//			for (int i = 0; i < strlen(str); i++) {
//				InsertNode(&root, str[i]);
//			}
//			system("pause");
//			continue;
//		case 2:
//			PreOrder(&root);
//			printf("\n");
//			InOrder(&root);
//			printf("\n");
//			PostOrder(&root);
//			printf("\n");
//			LevelOrder(&root);
//			printf("\n");
//			system("pause");
//			continue;
//		case 3:
//			return 0;
//		}
//	}
//}