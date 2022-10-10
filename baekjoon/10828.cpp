#include <stdio.h>
#include <string.h>

void push(int stack[], int n, int *top) {
	stack[++*top] = n;
}
int pop(int stack[], int* top) {
	int a;
	if (*top == -1) return -1;
	a = stack[*top];
	stack[--*top];
	return a;
}
int size(int* top) {
	return *top+1;
}
int empty(int* top) {
	if (*top == -1) return 1;
	else return 0;
}
int topp(int stack[],int *top) {
	if (*top == -1) return -1;
	return stack[*top];
}
int main() {
	int n;
	int t;
	int jo[10000] = { 0 };
	char a[10] = { 0 };
	int stack[10001] = { 0 };
	int top = -1;
	int e = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			a[j] = 0;
		}
		scanf("%s", a);
		if (strcmp(a, "push") == 0) {
			scanf("%d", &t); 
			push(stack,t,&top); 
		}
		else if (strcmp(a, "pop") == 0) { jo[e] = pop(stack, &top); e++; }
		else if (strcmp(a, "size") == 0) { jo[e] = size(&top); e++;}
		else if (strcmp(a, "empty") == 0) { jo[e] = empty(&top); e++;}
		else if (strcmp(a, "top") == 0) { jo[e] = topp(stack, &top); e++;}

	}
	for (int i = 0; i < e ; i++) {
		printf("%d\n", jo[i]);
	}
}