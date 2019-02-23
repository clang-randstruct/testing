#include <stdio.h>


int distance(void *a, void *b)
{
	return a - b;
}

#define PRINT_FIELD_LOC(s, f) printf("%d\t%s\n", distance((void*) &s.f, (void*) &s), #f)
struct mystruct {
	char *first;
	char *second;
	char *third;
}__attribute__((no_randomize_layout)) __attribute__((randomize_layout));
int main(void)
{
	struct mystruct m;
	m.first = "I'm the first!";
	m.second = "and I'm the second!";

	printf("%d first\n", distance((void*)&m.first, (void*)&m));
	printf("%d second\n", distance((void*)&m.second, (void*)&m));
	return 0;
}
