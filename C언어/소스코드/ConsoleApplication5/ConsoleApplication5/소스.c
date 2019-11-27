#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#define EMPTY 0

typedef struct node {
	int data;
	struct node*llink, *rlink;
}Tree;
//트리 출력 
void Llink(Tree**root, int x, int y);
void Rlink(Tree**root, int x, int y);
void Allink(Tree**root, int x, int y);
//차수 구하기
int GetDepth(Tree**root);
int GetHeight(Tree**root);
//회전
void LineUp(Tree**root);
void LL(Tree**root);
void RR(Tree**root);
void RL(Tree**root);
void LR(Tree**root);

Tree*get_node() {
	Tree*tmp;
	tmp = (Tree*)malloc(sizeof(Tree));
	tmp->llink = EMPTY;
	tmp->rlink = EMPTY;
	return tmp;
}
void gotoxy(int x, int y) {
	COORD pos = { 2 * x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void InsertNode(Tree**root, int data) {
	if ((*root) == EMPTY)
	{
		(*root) = get_node();
		(*root)->data = data;
	}
	else if ((*root)->data > data) {
		InsertNode(&(*root)->llink, data);
	}
	else if ((*root)->data < data) {
		InsertNode(&(*root)->rlink, data);
	}
	else {
		printf("같은 값이 이미 존재합니다\n");
	}
	LineUp(&(*root));
}
void LineUp(Tree**root) {
	Tree*tmp = *root;
	if (tmp == EMPTY) return;
	while ((GetHeight(&(*root)) > 1))
	{
		GetHeight(&(*root)->llink) > 0 ?
			LL(&(*root)) : LR(&(*root));
	}
	while ((GetHeight(&(*root)) < -1))
	{
		GetHeight(&(*root)->rlink) < 0 ?
			RR(&(*root)) : RL(&(*root));
	}
	LineUp(&(*root)->llink);
	LineUp(&(*root)->rlink);
}
void LL(Tree**root) {
	Tree*tmp = (*root)->llink;
	(*root)->llink = tmp->rlink;
	tmp->rlink = (*root);
	(*root) = tmp;
}
void RR(Tree**root) {
	Tree*tmp = (*root)->rlink;
	(*root)->rlink = tmp->llink;
	tmp->llink = (*root);
	(*root) = tmp;
}
void LR(Tree**root) {
	RR(&(*root)->llink);
	LL(&(*root));
}
void RL(Tree**root) {
	LL(&(*root)->rlink);
	RR(&(*root));
}
int GetDepth(Tree**root) {
	{
		if ((*root) == NULL)
		{
			return 0;
		}
	}
	return max(GetDepth(&(*root)->llink), GetDepth(&(*root)->rlink)) + 1;
}
int GetHeight(Tree**root) {
	return
		GetDepth(&(*root)->llink) - GetDepth(&(*root)->rlink);
}
void PreOrder(Tree**root) {
	printf("%d:(차수:%d) ", (*root)->data, GetHeight(&(*root)));
	if ((*root)->llink != EMPTY) {
		PreOrder(&(*root)->llink);
	}
	if ((*root)->rlink != EMPTY) {
		PreOrder(&(*root)->rlink);
	}
}
void InOrder(Tree**root) {
	if ((*root)->llink != EMPTY) {
		InOrder(&(*root)->llink);
	}
	printf("%d ", (*root)->data);
	if ((*root)->rlink != EMPTY) {
		InOrder(&(*root)->rlink);
	}
}
void PostOrder(Tree**root) {
	if ((*root)->llink != EMPTY) {
		PostOrder(&(*root)->llink);
	}
	if ((*root)->rlink != EMPTY) {
		PostOrder(&(*root)->rlink);
	}
	printf("%d ", (*root)->data);
}
Tree*SearchNode(Tree**root, int data) {
	Tree*tmp = *root;
	if (*root == EMPTY) {
		return NULL;
	}
	else if ((*root)->data == data) {
		return tmp;
	}
	else
		if ((*root)->data > data)
		{
			return SearchNode(&(*root)->llink, data);
		}
		else if ((*root)->data < data)
		{
			return SearchNode(&(*root)->rlink, data);
		}
}
void DeleteNode(Tree**root, int delete) {
	int num;
	if (*root == EMPTY) {
		printf("삭제할 값이 없습니다\n");
	}
	else if ((*root)->data == delete) {
		printf("삭제할 값이 있습니다\n");
		Tree*tmp = (*root);
		if ((*root)->llink != EMPTY && (*root)->rlink != EMPTY) {
			printf("왼쪽 경로는 1번 오른쪽 경로는 2번 :");
			scanf("%d", &num);
			if (num == 1) {
				Tree*rev = tmp->llink;
				while (rev->rlink) {
					rev = rev->rlink;
				}
				tmp->data = rev->data;
				DeleteNode(&tmp->llink, rev->data);
				return;
			}
			else if (num == 2) {
				Tree*rev = tmp->rlink;
				while (rev->llink) {
					rev = rev->llink;
				}
				tmp->data = rev->data;
				DeleteNode(&tmp->rlink, rev->data);
				return;
			}
		}
		else if (!(*root)->llink && (*root)->rlink) {
			(*root) = tmp->rlink;
			free(tmp);
		}
		else if (!(*root)->rlink && (*root)->llink) {
			(*root) = tmp->llink;
			free(tmp);
		}
		else {
			(*root) = NULL;
		}
	}
	else {
		if ((*root)->data > delete)
		{
			DeleteNode(&(*root)->llink, delete);
		}
		else if ((*root)->data < delete)
		{
			DeleteNode(&(*root)->rlink, delete);
		}
	}
}
void Llink(Tree**root, int x, int y) {
	Tree*tmp = *root;
	if (tmp == EMPTY) return;
	int depth = GetDepth(&(*root));
	gotoxy(x -= depth, y += 2);
	printf("%d", tmp->data);
	if (tmp->llink&&tmp->rlink)
	{
		Allink(&tmp, x, y);
	}
	if (tmp->llink && !tmp->rlink)
	{
		Llink(&tmp->llink, x, y);
	}
	if (!tmp->llink&&tmp->rlink) {
		Rlink(&tmp->rlink, x, y);
	}
}
void Rlink(Tree**root, int x, int y) {
	Tree*tmp = *root;
	int depth = GetDepth(&(*root));
	gotoxy(x += depth, y += 2);
	printf("%d", tmp->data);
	if (tmp == EMPTY) return;
	if (tmp->llink&&tmp->rlink)
	{
		Allink(&tmp, x, y);
	}
	if (tmp->llink&&tmp->rlink)
	{
		Llink(&tmp->llink, x, y);
	}
	if (tmp->rlink && !tmp->llink) {
		Rlink(&tmp->rlink, x, y);
	}
}
void Allink(Tree**root, int x, int y) {
	Tree*tmp = *root;
	if (tmp == EMPTY) return;
	int depth = GetDepth(&(*root));
	gotoxy(x -= depth, y += 2);
	printf("%d", tmp->llink->data);
	gotoxy(x += 2 * depth, y);
	printf("%d", tmp->rlink->data);
	{
		if (tmp->llink->llink&&tmp->llink->rlink)
			Allink(&tmp->llink, x - 2 * depth, y);
		if (!tmp->llink->llink&&tmp->llink->rlink)
			Rlink(&tmp->llink->rlink, x - 2 * depth, y);
		if (tmp->llink->llink && !tmp->llink->rlink)
			Llink(&tmp->llink->llink, x - 2 * depth, y);
		if (tmp->rlink->llink&&tmp->rlink->rlink)
			Allink(&tmp->rlink, x, y);
		if (!tmp->rlink->llink&&tmp->rlink->rlink)
			Rlink(&tmp->rlink->rlink, x, y);
		if (tmp->rlink->llink && !tmp->rlink->rlink)
			Llink(&tmp->rlink->llink, x, y);
	}
}
void Print_data(Tree**root) {
	Tree*tmp = *root;
	int depth = GetDepth(&(*root));
	if (tmp == EMPTY)return;
	int x = 100; int y = 0;
	gotoxy(x -= 50, y);
	printf("%d", tmp->data);
	if ((tmp->llink&&tmp->rlink)) {
		Allink(&tmp, x, y);
	}
	else if (tmp->llink && !tmp->rlink) {
		Llink(&tmp->llink, x, y);
	}
	else if (!tmp->llink && tmp->rlink)
	{
		Rlink(&tmp->rlink, x, y);
	}
	gotoxy(0, 20);
}
int main() {
	Tree*root = EMPTY;
	int num; int n;
	int data;
	int delete;
	while (1) {
		system("cls");
		Print_data(&root);
		printf("AVL TREE 프로그램입니다\n");
		printf("1. data 추가\n2. data 출력\n3. data 검색\n4. data 삭제\n5. 종료\n");
		printf(">>>>>> : ");
		scanf("%d", &n);
		if (n < 0 || n > 5)
			continue;
		switch (n) {
		case 1:
			printf("입력하고 싶은 값을 입력하시오 :");
			scanf("%d", &data);
			InsertNode(&root, data);
			system("pause");
			continue;
		case 2:
			PreOrder(&root);
			printf("\n");
			InOrder(&root);
			system("pause");
			continue;
		case 3:
			printf("찾는 값을 입력하세요 :");
			scanf("%d", &num);
			if (SearchNode(&root, num) == NULL) {
				printf("찾는 값이 없습니다\n");
			}
			else
				printf("찾는 값이 있습니다\n");
			system("pause");
			continue;
		case 4:
			printf("삭제할 값을 입력하시오 :");
			scanf("%d", &delete);
			DeleteNode(&root, delete);
			system("pause");
			continue;
		case 5:
			return 0;
		}
	}
}