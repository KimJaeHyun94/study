#include <stdio.h> 

#define max_vertex 100 
#define max_element 100 

int parent[max_vertex];
int num[max_vertex];

typedef struct {
	int v; // 정점1 
	int u; // 정점2 
	int key; // 간선의 가중치 
}element;

typedef struct {
	element heap[max_element];
	int heap_size;
}heaptype;

void initheap(heaptype *h)
{
	h->heap_size = 0;
}
void insertheap(heaptype *h, element item)
{
	int i;
	i = ++(h->heap_size);

	while (i != 1 && item.key < h->heap[i / 2].key) // 부모노드와 비교 
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}

	h->heap[i] = item;
}

element deleteheap(heaptype *h)
{
	int parent = 1, child = 2;
	element data, temp;

	data = h->heap[parent];
	temp = h->heap[(h->heap_size)--]; // 삭제에 의한 size 감소 

	while (child <= h->heap_size)
	{
		//자식 노드간 작은 수 비교  
		if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key)
			child++;

		if (temp.key <= h->heap[child].key) break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2; // 다음 자식 노드와 비교 
	}

	h->heap[parent] = temp;
	return data;
}

void inituf(void) // 전역 변수 초기화 
{
	int i;
	for (i = 0; i<max_vertex; i++)
	{
		parent[i] = -1;
		num[i] = 1;
	}
}

int setfind(int v) 
{
	int i, p, temp;
	for (i = v; (p = parent[i]) >= 0; i = p); 
	temp = i; 
	for (i = v; (p = parent[i]) >= 0; i = p)
		parent[i] = temp; 
	return temp;
}

void setunion(int v1, int v2)  
{
	if (num[v1] < num[v2]) 
	{
		parent[v1] = v2; 
		num[v1] += num[v2];
	}
	else
	{
		parent[v2] = v1; 
		num[v2] += num[v1];
	}
}

void insertheapedge(heaptype *h, int v, int u, int weight)
{
	element node;
	node.v = v;
	node.u = u;
	node.key = weight;
	insertheap(h, node);
}

int kruskal(int n)
{
	element e;
	heaptype h;
	int uset, vset, edgecount = 0, sum = 0;

	initheap(&h);
	inituf();

	int num, arr,edge;
	while (1) {
		printf("그래프를 입력하세요 : (-1입력시 끝)");
		scanf("%d %d %d", &num, &arr,&edge);
		if (num == -1) {
			break;
		}
		insertheapedge(&h, num, arr, edge);
	}

	while (edgecount < n - 1) 
	{
		e = deleteheap(&h); 
		uset = setfind(e.u);
		vset = setfind(e.v);

		if (uset != vset) 
		{
			printf("(%d,%d) %d\n", e.u, e.v, e.key);
			sum += e.key;
			edgecount++; 
			setunion(uset, vset); 
		}
	}

	printf("최소 비용의 간선 길이 %d \n\n", sum);
	for (int m = 1; m<n; m++)
		printf("자식 [%d] : 부모 %d\n", m, parent[m]);

	return 0;
}

int main()
{
	int num;
	printf("몇개의 노드 그래프를 만드실 껀가요 ?");
	scanf("%d", &num);
	kruskal(num); 
}