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

struct perf {
	int a;
	char b;
	int c[6];
	struct mystruct m;
	unsigned potato : 1;
	int (* hi)();
}__attribute__((randomize_layout));

int main(void)
{
	struct mystruct m;
	m.first = "I'm the first!";
	m.second = "and I'm the second!";
	m.second = "third!!!";

	PRINT_FIELD_LOC(m, first);
	PRINT_FIELD_LOC(m, second);
	PRINT_FIELD_LOC(m, third);

	struct perf p;

	p.a = 0;
	p.b = 'a';
	p.m = m;
	p.potato = 0;
	p.hi = NULL;

	PRINT_FIELD_LOC(p, a);
	PRINT_FIELD_LOC(p, b);
	PRINT_FIELD_LOC(p, c);
	PRINT_FIELD_LOC(p, m);
	//PRINT_FIELD_LOC(p, potato);
	PRINT_FIELD_LOC(p, hi);

	printf("%d first\n", distance((void*)&m.first, (void*)&m));
	printf("%d second\n", distance((void*)&m.second, (void*)&m));
	return 0;
}
