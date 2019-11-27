#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#define EMPTY 0

typedef struct node {
	int data;
	struct node*llink, *rlink;
}Tree;
void Llink(Tree**root, int x, int y);
void Rlink(Tree**root, int x, int y);
void Allink(Tree**root, int x, int y);
void LineUp(Tree**root);
int GetLeft(Tree**root);
int GetRight(Tree**root);
int GetHeight(Tree**root);
Tree*get_node() {
	Tree*tmp;
	tmp = (Tree*)malloc(sizeof(Tree));
	tmp->llink = EMPTY;
	tmp->rlink = EMPTY;
	return tmp;
}

void gotoxy(int x, int y) {
	COORD pos = { x,y };
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

	if (GetHeight(&(*root)) == -1) {
		if ((*root)->rlink && !(*root)->llink)
		{
			if (!(*root)->rlink->llink && (*root)->rlink->rlink)
			{
				Tree*rev = tmp->rlink;
				Tree*key = tmp->rlink->llink;
				tmp->llink->rlink = key;
				tmp->rlink = rev->llink;
				tmp->rlink->rlink = rev;
				rev->llink = EMPTY;
			}
			else return;
		}
	}
	if (GetHeight(&(*root)) == -2) {
		Tree*key = (*root)->rlink->llink;
		(*root) = tmp->rlink;
		(*root)->llink = tmp;
		tmp->rlink = EMPTY;
		tmp->rlink = key;
	}
	if (GetHeight(&(*root)) == 1) {
		if (!(*root)->rlink && (*root)->llink) {
			if ((*root)->llink->rlink && !(*root)->llink->llink)
			{
				Tree*rev = tmp->llink;
				tmp->llink = rev->rlink;
				tmp->llink->llink = rev;
				rev->rlink = EMPTY;
			}
			else return;
		}
	}
	if (GetHeight(&(*root)) == 2) {
		Tree*key = (*root)->llink->rlink;
		(*root) = tmp->llink;
		(*root)->rlink = tmp;
		tmp->llink = EMPTY;
		tmp->llink = key;
	}
	LineUp(&(*root)->llink);
	LineUp(&(*root)->rlink);
}
int GetHeight(Tree**root) {
	int left;
	int right;
	if (root == EMPTY) {
		return 0;
	}
	left = (GetLeft(&(*root)));
	right = (GetRight(&(*root)));

	if (left == right) {
		return 0;
	}
	else
		return (left - right);
}
int GetLeft(Tree**root) {
	int left = 0;
	if (root == EMPTY) return 0;
	Tree*tmp = *root;
	while (tmp->llink) {
		left++;
		tmp = tmp->llink;
	}
	return left;
}
int GetRight(Tree**root) {
	int right = 0;
	if (root == EMPTY)return 0;
	Tree*tmp = *root;
	while (tmp->rlink) {
		right++;
		tmp = tmp->rlink;
	}
	return right;
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
		else if ((*root)->llink != EMPTY && (*root)->rlink == EMPTY) {
			(*root) = tmp->rlink;
			free(tmp);
		}
		else if ((*root)->rlink != EMPTY && (*root)->llink == EMPTY) {
			(*root) = tmp->llink;
			free(tmp);
		}
		else {
			(*root) = NULL;
			free(tmp);
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
	gotoxy(x -= 5, y += 2);
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
	gotoxy(x += 5, y += 2);
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
	gotoxy(x -= 5, y += 2);
	printf("%d", tmp->llink->data);
	gotoxy(x += 10, y);
	printf("%d", tmp->rlink->data);

	if (tmp->llink->rlink&&tmp->rlink->llink) {  //겹친다면
		int k = tmp->llink->rlink->data;
		if (tmp->llink->llink&&tmp->llink->rlink)
			Allink(&tmp->llink, x - 10, y);
		if (!tmp->llink->llink&&tmp->llink->rlink)
			Rlink(&tmp->llink->rlink, x - 10, y);

		if (tmp->rlink->llink&&tmp->rlink->rlink)
			Allink(&tmp->rlink, x, y);
		if (tmp->rlink->llink && !tmp->rlink->rlink)
			Llink(&tmp->rlink->llink, x, y);
		gotoxy(x -= 5, y += 2);
		printf("%d,%d", k, tmp->rlink->llink->data);
	}
	else {                                     //안겹친다면
		if (tmp->llink->llink&&tmp->llink->rlink)
			Allink(&tmp->llink, x - 10, y);
		if (!tmp->llink->llink&&tmp->llink->rlink)
			Rlink(&tmp->llink->rlink, x - 10, y);
		if (tmp->llink->llink && !tmp->llink->rlink)
			Llink(&tmp->llink->llink, x - 10, y);

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
	if (tmp == EMPTY)return;
	int x = 50; int y = 0;
	gotoxy(x -= 5, y);
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
		}
	}
}
