#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	size_t curCount, allocatedSize;
	double* data;
} Stack;

void Stack_construct(Stack* me) {
	double * data = malloc(8*sizeof(double));
	me->data = data;
	me->curCount = 0;
	me->allocatedSize = 8;
}

bool Stack_isEmpty(Stack* me) {
	return me->curCount == 0;
}

void Stack_push(Stack* me, double value) {
	if(me->curCount == me->allocatedSize)
	{
		me->data = realloc(me->data, me->allocatedSize * 2 * sizeof(double));
		me->allocatedSize *= 2;
	}

	me->data[me->curCount] = value;
	me->curCount += 1;
}
double Stack_pop(Stack* me) {
	double returnvalue = me->data[me->curCount - 1];
	me->curCount -= 1;

	if(me->curCount < me->allocatedSize / 2)
	{
		me->data = realloc(me->data, (me->allocatedSize / 2) * sizeof(double));
		me->allocatedSize /= 2;
	}
	return returnvalue;
}

void Stack_destruct(Stack* me) {
	free(me->data);
}

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
