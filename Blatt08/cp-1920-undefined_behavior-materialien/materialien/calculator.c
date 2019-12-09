#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	size_t curCount, allocatedSize;
	double* data;
} Stack;

void Stack_construct(Stack* me) { assert(0 && "TODO"); }
bool Stack_isEmpty(Stack* me) { assert(0 && "TODO"); }
void Stack_push(Stack* me, double value) { assert(0 && "TODO"); }
double Stack_pop(Stack* me) { assert(0 && "TODO"); }
void Stack_destruct(Stack* me) { assert(0 && "TODO"); }

double calculate(char* expression) {
	Stack myStack;
	Stack_construct(&myStack);
	while(*expression) {
		switch(*expression) {
			case ' ': {
				expression++;
			} break;

			case '+':
			case '-':
			case '*':
			case '/': {
				assert(!Stack_isEmpty(&myStack));
				double argB = Stack_pop(&myStack);
				assert(!Stack_isEmpty(&myStack));
				double argA = Stack_pop(&myStack);
				Stack_push(&myStack, *expression == '+' ? argA + argB :
				                     *expression == '-' ? argA - argB :
				                     *expression == '*' ? argA * argB :
				                                          argA / argB);
				expression++;
			} break;

			default: {
				char* nextToken;
				double value = strtod(expression, &nextToken);
				assert(nextToken != expression);
				Stack_push(&myStack, value);
				expression = nextToken;
			} break;
		}
	}
	assert(!Stack_isEmpty(&myStack));
	double result = Stack_pop(&myStack);
	assert(Stack_isEmpty(&myStack));
	return result;
}

int main() {
	printf("%f\n", calculate("1 1 1 1 + + + 1 - 1 1 1 1 + + + 1 1 + / * 1 1 + 1 1 + * 1 1 + * 1 - *"));
}
