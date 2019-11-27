//#include<stdio.h>
//
//#define nsize 100
//
//typedef struct{
//	int element[nsize];
//	int top;
//}Stack;
//
//
//int isEmpty(Stack*stack) {
//	if (stack->top == 0) {
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}
//void Push(Stack*stack, int a) {
//	stack->element[stack->top++] = a;
//}
//int Pop(Stack*stack) {
//	if (isEmpty(stack)) {
//		return 0;
//	}
//	else {
//		int a = stack->element[--stack->top];
//		return a;
//	}
//}
//int main() {
//	Stack stack;
//	stack.top = 0;
//	Push(&stack, 1);
//	Push(&stack, 2);
//	Push(&stack, 3);
//	Push(&stack, 4);
//	Push(&stack, 5);
//	printf("%d\n", Pop(&stack));
//	printf("%d\n", Pop(&stack));
//	printf("%d\n", Pop(&stack));
//	printf("%d\n", Pop(&stack));
//	printf("%d\n", Pop(&stack));
//	printf("%d\n", Pop(&stack));
//}