#include "src/stack/stack.h"



int main() {
	Stack* stack = createStack();
	int a = 5;
	pushStack(stack, &a);

	printf("%d\n", stackCount(stack));

	destoryStack(stack);
	return 0;
}