#include<stdio.h>
#include<stdlib.h>

typedef int Element;
typedef struct list_node *list_pointer;
typedef list_pointer List;
typedef list_pointer Node;
typedef struct list_node {
	Element value;
	list_pointer llink;
	list_pointer rlink;
};
int isEmtpy(List L);

int isEmtpy(List L) {
	if (L == NULL) {
		return 1;
	}
	else
	{
		return 0;
	}
}
void WriteListItem(List L) {
	list_pointer rnode;
	rnode = L;
	do {
		printf("%d\t", rnode->value);
		rnode = rnode->rlink;
	} while (rnode != L);
}
List AddItem(List L, Element el) {
	List inode;
	List rnode, Inode;
	inode = (List)malloc(sizeof(struct list_node));
	if (inode == NULL) {
		printf("Unable");
	}
	int i = isEmtpy(L);
	if (i==1) {
		inode->value = el;
		inode->llink = inode;
		inode->rlink = inode;
		L = inode;
	}
	else {
		rnode = L;
		Inode = rnode->llink;

		inode->value = el;
		inode->rlink = rnode;
		inode->llink = Inode;

		Inode->rlink = inode;
		rnode->llink = inode;
    }
	return L;
}

List FindItem(List L, Element el) {
	List tnode = L;
	List anode = L;
	while (tnode->llink!= L) {
		if (tnode->value == el) {
			printf("%d\n", el);
			return tnode;
		}
		tnode = tnode->llink;
	}
	if (tnode->value == el) {
		printf("FindItem :%d\n", tnode->value);
		printf("%d in in L\n", el);
		return tnode;
	}
	printf("%d does not exist\n",el);
	return anode;
}
List DeleteFirstItem(List L) {
	List dnode = L;
	List rnode = dnode->rlink;
	List lnode = dnode->llink;

	if (isEmtpy(L)) {
		printf("L is Empty!");
	}
	else {
		free(dnode);
		rnode->llink = lnode;
		lnode->rlink = rnode;
		L = rnode;
	}
	return L;
}
List DeleteItem(List L, Element el) {
	List dnode = L;
	List rnode;
	if (isEmtpy(L)) {
		printf("L is Empty!");
	}
	else {
		if (L->value == el) {
			return DeleteFirstItem(L);
		}
		else {
			do {
				if (dnode->value == el) {
					dnode->llink->rlink = dnode->rlink;
					dnode->rlink->llink = dnode->llink;
					rnode = dnode->rlink;
					free(dnode);
					break;
				}
				else {
					dnode = dnode->rlink;
				}
			} while (dnode != L);
		}
	}
	return L;
}
List MakeListEmpty(List L) {
	List dnode = L;
	List rnode = dnode->rlink;
	List lnode = dnode->llink;
	while (dnode != lnode) {
		free(dnode);
		dnode = rnode;
		rnode = dnode->rlink;
	}
	L = NULL;
	return L;
}

int main() {
	Node L=NULL;
	L=AddItem(L, 1);
	L=AddItem(L, 2);
	L=AddItem(L, 3);
	L = AddItem(L, 4);
	WriteListItem(L);
	printf("\n");
	L = FindItem(L, 4);

	WriteListItem(L);
	L=DeleteItem(L,5);
	printf("\n");
	WriteListItem(L);
}