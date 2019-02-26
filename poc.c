#include <stdio.h>

int distance(void *a, void *b)
{
	return a - b;
}

#define PRINT_FIELD_LOC(s, f) printf("%d\t%s\n", distance((void*) &s.f, (void*) &s), #f)

struct autoselecttest {
        int (*test1)();
	int (*test2)();
};
struct autotestfail {
	int (*test1)();
	int test2;
};
struct notautoselect {
	int (*test1)();
	int (*test2)();
}__attribute__((no_randomize_layout));

struct norand {
	int tomato;
	char potato;
	double lettuce;
	int computer;
};

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
	struct autoselecttest a;
	struct notautoselect n;
	struct autotestfail f;
	
	m.first = "I'm the first!";
	m.second = "and I'm the second!";
	m.third = "third!!!";

	f.test1 = NULL;
	f.test2 = 1;
	a.test1 = NULL;
	a.test2 = NULL;
	n.test1 = NULL;
	n.test2 = NULL;



	PRINT_FIELD_LOC(m, first);
	PRINT_FIELD_LOC(m, second);
	PRINT_FIELD_LOC(m, third);

	printf("Autofail test 1: %i\n", &f.test1);
	printf("Autofail test 2: %i\n", &f.test2);
	printf("Auto test 1: %i\n", &a.test1);
	printf("Auto test 2: %i\n", &a.test2);

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

	struct norand r;

	PRINT_FIELD_LOC(r, tomato);
	PRINT_FIELD_LOC(r, potato);
	PRINT_FIELD_LOC(r, lettuce);
	PRINT_FIELD_LOC(r, computer);

	return 0;
}
