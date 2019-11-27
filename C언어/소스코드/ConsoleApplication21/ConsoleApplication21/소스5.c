#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#define EMPTY 0

typedef struct node {
	int data;
	struct node*llink, *rlink;
}Tree;


Tree*get_node() {
	Tree*tmp;
	tmp = (Tree*)malloc(sizeof(Tree));
	tmp->llink = EMPTY;
	tmp->rlink = EMPTY;
	return tmp;
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
}

void PreOrder(Tree**root) {
	printf("%d ", (*root)->data);
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

void LevelOrder(Tree**root) {
	Tree* Queue[100];
	int front = 0, rear = 0;
	if (*root) {
		Queue[rear++] = *root;
	}
	while (*root != NULL && front != rear)
	{
		*root = Queue[front++];
		printf("%d ", (*root)->data);
		if ((*root)->llink) {
			Queue[rear++] = (*root)->llink;
		}
		if ((*root)->rlink) {
			Queue[rear++] = (*root)->rlink;
		}
	}
}
int main() {
	Tree*root = EMPTY;
	InsertNode(&root, 4); InsertNode(&root, 2);
	InsertNode(&root, 1);  InsertNode(&root, 3);
	 InsertNode(&root, 5);  InsertNode(&root, 6);
	 InsertNode(&root, 7);
	
	//전위
	PreOrder(&root);
	printf("\n");
	//중위
	InOrder(&root);
	printf("\n");
	//후위
	PostOrder(&root);
	printf("\n");
	//검색
	LevelOrder(&root);
	printf("\n");
}