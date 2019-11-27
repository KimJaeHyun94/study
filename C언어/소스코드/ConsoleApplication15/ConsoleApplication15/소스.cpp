#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	char data;
	struct Node* lchild;
	struct Node* rchild;
}Node;

Node* CreNode(char Newdata)
{
	Node *NewNode = (Node *)malloc(sizeof(Node));
	NewNode->lchild = NULL;
	NewNode->rchild = NULL;
	NewNode->data = Newdata;

	return NewNode;
}

void DesNode(Node* Node)
{
	free(Node);
}

void Preorder(Node* Node)
{
	if (Node == NULL)
		return;

	printf("%c ", Node->data);
	Preorder(Node->lchild);
	Preorder(Node->rchild);
}

void Inorder(Node* Node)
{
	if (Node == NULL)
		return;

	Inorder(Node->lchild);
	printf("%c ", Node->data);
	Inorder(Node->rchild);
}

void Postorder(Node* Node)
{
	if (Node == NULL)
		return;

	Postorder(Node->lchild);
	Postorder(Node->rchild);
	printf("%c ", Node->data);
}

int main()
{
	Node* A = CreNode('+');
	Node* B = CreNode('*');
	Node* C = CreNode('-');
	Node* D = CreNode('a');
	Node* E = CreNode('b');
	Node* F = CreNode('c');
	Node* G = CreNode('d');

	A->lchild = B;
	B->lchild = D;
	B->rchild = E;
	A->rchild = C;
	C->lchild = F;
	C->rchild = G;

	printf("Prefix \n");
	Preorder(A);
	printf("\n");

	printf("Infix \n");
	Inorder(A);
	printf("\n");

	printf("Postfix \n");
	Postorder(A);
	printf("\n");

	DesNode(A);

	return 0;
}

