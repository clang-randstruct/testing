#include <stdio.h>

struct mystruct {
	char *first;
	char *second;
}__attribute__((randomize_layout));

int distance(void *a, void *b)
{
	return a - b;
}

int main(void)
{
	struct mystruct m;
	m.first = "I'm the first!";
	m.second = "and I'm the second!";

	printf("%d first\n", distance((void*)&m.first, (void*)&m));
	printf("%d second\n", distance((void*)&m.second, (void*)&m));
	return 0;
}
