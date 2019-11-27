//#include <stdio.h>
//#define nsize 21
//
//typedef struct {
//	int element[nsize];
//	int front, rear;
//} Queue;
//
//void enqueue(Queue*q, int data) {
//	if (q->rear == 0) {
//		q->front =0;
//	}
//	if (isFull(q) == 1) {
//		printf("Full!\n");
//	}
//	else {
//		q->rear = (q->rear + 1) % nsize;
//		q->element[q->rear] = data;
//	}
//}
//int isEmpty(Queue*q) {
//	if (q->front==q->rear||q->front==-1) {
//		return 1;
//	}
//	else
//		return 0;
//}
//void dequeue(Queue*q) {
//	if (isEmpty(q) == 1) {
//		printf("Empty!\n");
//	}
//	else {
//		q->front = (q->front + 1) % nsize;
//		printf("%d\n", q->element[q->front]);
//		q->element[q->front] = NULL;
//	}
//}
//
//int isFull(Queue*q) {
//	int tmp = (q->rear + 1) % nsize;
//	if (tmp==q->front){
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}
//int main(int argc, char *argv[])
//{
//	Queue queue;
//	queue.front = -1;
//	queue.rear = 0;
//	dequeue(&queue);
//	enqueue(&queue, 2);	enqueue(&queue, 4);	enqueue(&queue, 5);	enqueue(&queue, 6);	enqueue(&queue, 8);
//	enqueue(&queue, 9);	enqueue(&queue, 10);	enqueue(&queue, 18);	enqueue(&queue, 28);	enqueue(&queue, 38);
//	enqueue(&queue, 17);	enqueue(&queue, 3);	enqueue(&queue, 81);	enqueue(&queue, 88);	enqueue(&queue, 48);
//	enqueue(&queue, 13);	enqueue(&queue, 22);	enqueue(&queue, 83);	enqueue(&queue, 78);	enqueue(&queue, 58);
//	enqueue(&queue, 14);	
//
//	dequeue(&queue); dequeue(&queue);	dequeue(&queue);	dequeue(&queue);	dequeue(&queue);
//
//
//	return 0;
//}
